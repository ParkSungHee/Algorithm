package kr.co.gracegirls.tmi.view.record;

import android.Manifest;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.os.Bundle;
import android.hardware.Sensor;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.Toast;
import android.view.View.OnClickListener;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.location.LocationListener;
import com.google.android.gms.location.LocationRequest;
import com.google.android.gms.location.LocationServices;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;

import java.io.IOException;
import java.util.List;
import java.util.Locale;
import android.content.Context;
import android.hardware.SensorEvent;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.util.PermissionUtils;


public class RecordFragment extends Fragment implements OnMapReadyCallback,
        GoogleApiClient.ConnectionCallbacks,
        GoogleApiClient.OnConnectionFailedListener,
        ActivityCompat.OnRequestPermissionsResultCallback,
        LocationListener, SensorEventListener {
    private GoogleMap googleMap;
    private GpsTracker gpsTracker;
    private Polyline polylines;

    private static final int LOCATION_PERMISSION_REQUEST_CODE = 1;

    private GoogleApiClient googleApiClient;
    private LocationRequest locationRequest;
    private Location currentLocation;
    private Marker currentMarker;
    private LatLng startLatLng = new LatLng(0, 0);        //polyline 시작점
    private LatLng endLatLng = new LatLng(0, 0);         //polyline 끝점
    private boolean walkState = false;                          //걸음 상태


    // 버튼 초기, 실행, 중지 상태 표시
    final static int Init =0;
    final static int Run =1;
    final static int Pause =2;

    int cur_Status = Init; // 현재의 상태를 저장할변수를 초기화함.
    ImageButton myBtnStart; // 시작 버튼

    // 시간 카운터를 위한 변수
    long myBaseTime;
    long myPauseTime;
    long calTime;

    TextView myTime;

    // 거리 계산을 위한 변수
    TextView myDistance;

    // 걸음수를 위한 변수
    TextView myWalkNum; // 걸음수 출력 textview
    private int mSteps = 0; // 현재 걸음 수
    private int mCounterSteps = 0;   // 리스너가 등록되고 난 후의 step count
    //센서 연결을 위한 변수
    private SensorManager sensorManager;
    //private Sensor accelerormeterSensor;
    private Sensor stepCountSensor;

    // 칼로리 계산을 위한 변수
    TextView myCalorie;

    @Override
    public void onCreate(Bundle saveInstanceState) {
        super.onCreate(saveInstanceState);
    }

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_record, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("기록", false);

        //센서 연결[걸음수 센서를 이용한 흔듬 감지]
        sensorManager = (SensorManager)getActivity().getSystemService(Context.SENSOR_SERVICE);
        //accelerormeterSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        stepCountSensor = sensorManager.getDefaultSensor(Sensor.TYPE_STEP_COUNTER);


        // 카운터 체크용
        myTime = view.findViewById(R.id.time_out);
        myBtnStart = view.findViewById(R.id.btn_start);

        // 거리 체크용
        myDistance=view.findViewById(R.id.killo_distance);

        // 걸음 체크용
        myWalkNum = view.findViewById(R.id.walk_num);

        // 칼로리 체크용
        myCalorie=view.findViewById(R.id.calorie_num);

        myBtnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch(v.getId()){
                    case R.id.btn_start: //시작버튼을 클릭했을때 현재 상태값에 따라 다른 동작을 할수있게끔 구현.
                        Log.e("start", "start");
                        switch(cur_Status){
                            case Init:
                                myBaseTime = SystemClock.elapsedRealtime();
                                Log.d("time", String.valueOf(myBaseTime));
                                //myTimer이라는 핸들러를 빈 메세지를 보내서 호출
                                myTimer.sendEmptyMessage(0);
                                myBtnStart.setImageResource(R.drawable.icon_pause);
                                cur_Status = Run; //현재상태를 런상태로 변경

                                myDisCheck.sendEmptyMessage(0);
                                myCalCheck.sendEmptyMessage(0);
                                break;
                            case Run:
                                myTimer.removeMessages(0); //핸들러 메세지 제거
                                // 중지된 시간
                                myPauseTime = SystemClock.elapsedRealtime();
                                myBtnStart.setImageResource(R.drawable.icon_start);
                                cur_Status = Pause;

                                myCalCheck.removeMessages(0); //핸들러 메세지 제거
                                break;
                            case Pause:
                                long now = SystemClock.elapsedRealtime();
                                myTimer.sendEmptyMessage(0);
                                myBaseTime += (now- myPauseTime);
                                myBtnStart.setImageResource(R.drawable.icon_pause);
                                cur_Status = Run;

                                myCalCheck.sendEmptyMessage(0);
                                break;
                        }
                        break;
                }
            }
        });

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.record_map);

        mapFragment.getMapAsync(this);

        if (googleApiClient == null) {
            googleApiClient = new GoogleApiClient.Builder(getActivity())
                    .addApi(LocationServices.API)
                    .addConnectionCallbacks(this)
                    .addOnConnectionFailedListener(this)
                    .build();
        }
        createLocationRequest();


        ImageButton start_button = view.findViewById(R.id.btn_start);
        start_button.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                changeWalkState();        //걸음 상태 변경
            }
        });

        return view;
    }
    private void changeWalkState(){
        if(!walkState) {
            gpsTracker = new GpsTracker(getActivity());

            double latitude = gpsTracker.getLatitude();
            double longitude = gpsTracker.getLongitude();
            String address = getCurrentAddress(latitude, longitude);

            Toast.makeText(getActivity(), "현재위치 \n위도 " + latitude + "\n경도 " + longitude +"\n위치 "+address, Toast.LENGTH_LONG).show();

            startLatLng = new LatLng(latitude, longitude);  //현재 위치를 시작점으로 설정
            walkState = true;
        }else{
            walkState = false;
        }
    }

    private void drawPath(){        //polyline을 그려주는 메소드
        PolylineOptions line = new PolylineOptions()
                .add(startLatLng).add(endLatLng)
                .width(5)
                .color(Color.RED);
        polylines = googleMap.addPolyline(line);
        googleMap.moveCamera(CameraUpdateFactory.newLatLngZoom(startLatLng, 18));
    }

    @Override
    public void onStart() {
        super.onStart();
        googleApiClient.connect();

        // 걸음 수 체크용 함수들
        if(stepCountSensor !=null){
            //센서의 속도 설정
            sensorManager.registerListener(this,stepCountSensor,SensorManager.SENSOR_DELAY_GAME);
        }
    }

    @Override
    public void onStop() {
        super.onStop();

        googleApiClient.disconnect();

        if(sensorManager!=null){
            sensorManager.unregisterListener(this);
        }
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        this.googleMap = googleMap;
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                           @NonNull int[] grantResults) {
        if (requestCode != LOCATION_PERMISSION_REQUEST_CODE) {
            return;
        }

        if (PermissionUtils.isPermissionGranted(permissions, grantResults,
                Manifest.permission.ACCESS_FINE_LOCATION)) {
            // 권한이 부여 된 경우 내 위치 레이어를 활성화
            enableMyLocation();
        } else {
            // fragment 다시 시작될 때 누락 된 권한 오류를 error dialog 표시
        }
    }
    @Override
    public void onLocationChanged(Location location) {
        double latitude = location.getLatitude(), longtitude = location.getLongitude();

        if (currentMarker != null) currentMarker.remove();
        currentLocation = location;
        MarkerOptions markerOptions = new MarkerOptions();
        markerOptions.position(new LatLng(latitude, longtitude));
        currentMarker =  googleMap.addMarker(markerOptions);


        googleMap.animateCamera(CameraUpdateFactory.newLatLngZoom(
                new LatLng(currentLocation.getLatitude(), currentLocation.getLongitude()), 18));
        if(walkState){  //걸음 시작 버튼이 눌렸을 때
            endLatLng = new LatLng(latitude, longtitude);        //현재 위치를 끝점으로 설정
            drawPath();                                            //polyline 그리기
            startLatLng = new LatLng(latitude, longtitude);        //시작점을 끝점으로 다시 설정
        }
    }

    private void enableMyLocation() {
        if (ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION)
                != PackageManager.PERMISSION_GRANTED) {
            // Permission to access the location is missing.
            PermissionUtils.requestPermission((AppCompatActivity) getActivity(), LOCATION_PERMISSION_REQUEST_CODE,
                    Manifest.permission.ACCESS_FINE_LOCATION, true);
        } else if (googleMap != null) {
            currentLocation = LocationServices.FusedLocationApi.getLastLocation(googleApiClient);
            // Start location updates.
            LocationServices.FusedLocationApi.requestLocationUpdates(
                    googleApiClient, locationRequest, this);

            if (currentLocation != null) {
                Log.i("Location", "Latitude: " + currentLocation.getLatitude()
                        + ", Longitude: " + currentLocation.getLongitude());
            }
        }
    }
    protected void createLocationRequest() {
        locationRequest = new LocationRequest();
        locationRequest.setInterval(10000);
        locationRequest.setFastestInterval(5000);
        locationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);
    }
    
    public String getCurrentAddress( double latitude, double longitude) {

        //지오코더 - GPS를 주소로 변환
        Geocoder geocoder = new Geocoder(getActivity(), Locale.getDefault());

        List<Address> addresses;

        try {

            addresses = geocoder.getFromLocation(
                    latitude,
                    longitude,
                    7);
        } catch (IOException ioException) { //네트워크 문제
            Toast.makeText(getActivity(), "위치값을 위도, 경도로 표시할 수 없습니다", Toast.LENGTH_LONG).show();
            return "위치값을 위도, 경도로 표시할 수 없습니다";
        } catch (IllegalArgumentException illegalArgumentException) {
            Toast.makeText(getActivity(), "잘못된 GPS 좌표", Toast.LENGTH_LONG).show();
            return "잘못된 GPS 좌표";
        }

        if (addresses == null || addresses.size() == 0) {
            Toast.makeText(getActivity(), "주소 미발견", Toast.LENGTH_LONG).show();
            return "주소 미발견";
        }

        Address address = addresses.get(0);
        return address.getAddressLine(0).toString()+"\n";
    }

    @Override
    public void onConnected(@Nullable Bundle bundle) {
        enableMyLocation();
    }

    @Override
    public void onConnectionSuspended(int i) {

    }

    @Override
    public void onConnectionFailed(@NonNull ConnectionResult connectionResult) {

    }


    // 시간 카운트 체크용
    Handler myTimer = new Handler(){
        public void handleMessage(Message msg){
            myTime.setText(getTimeOut()+"\n시간");

            //sendEmptyMessage 는 비어있는 메세지를 Handler 에게 전송하는겁니다.
            myTimer.sendEmptyMessage(0);
        }
    };
    //현재시간을 계속 구해서 출력하는 메소드
    String getTimeOut(){
        long now = SystemClock.elapsedRealtime(); // 애플리케이션이 실행되고나서 실제로 경과된 시간;
        long outTime = now - myBaseTime;
        calTime=outTime;
        String easy_outTime = String.format("%02d:%02d:%02d", (outTime/1000/60)/60, (outTime/1000)/60,(outTime/1000)%60);
        return easy_outTime;

    }

    // 거리 체크용
    Handler myDisCheck = new Handler(){
        public void handleMessage(Message msg){
            myDistance.setText(getDistance()+"\n킬로미터");

            // sendEmptyMessage 는 비어있는 메세지를 Handler 에게 전송하는겁니다.
            myDisCheck.sendEmptyMessage(0);
        }
    };
    //현재시간을 계속 구해서 출력하는 메소드
    String getDistance(){
        int outDistance = mSteps/15;
        String disFormat = String.format("%1d.%1d%1d", outDistance/100, outDistance/10, outDistance%10);

        return disFormat;
    }

    // 칼로리 체크용
    Handler myCalCheck = new Handler(){
        public void handleMessage(Message msg){
            myCalorie.setText(getCalorie()+"\n칼로리");

            // sendEmptyMessage 는 비어있는 메세지를 Handler 에게 전송하는겁니다.
            myCalCheck.sendEmptyMessage(0);
        }
    };
    //현재시간을 계속 구해서 출력하는 메소드
    String getCalorie(){
        int outCalorie = (int)calTime/1000/11;
        String calFormat = String.format("%d", outCalorie);

        return calFormat;
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if(event.sensor.getType() == Sensor.TYPE_STEP_COUNTER){

            //stepcountsenersor는 앱이 꺼지더라도 초기화 되지않는다. 그러므로 우리는 초기값을 가지고 있어야한다.
            if (mCounterSteps < 1) {
                // 초기 값
                mCounterSteps = (int) event.values[0];
            }

            // (리셋 안된 값 + 현재값) - 리셋 안된 값
            mSteps = (int) event.values[0] - mCounterSteps;
            myWalkNum.setText(Integer.toString(mSteps)+"\n걸음");
            Log.i("log: ", "New step detected by STEP_COUNTER sensor. Total step count: " + mSteps );
        }

    }

    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}