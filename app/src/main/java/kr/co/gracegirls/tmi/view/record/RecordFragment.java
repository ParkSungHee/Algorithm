package kr.co.gracegirls.tmi.view.record;

import android.hardware.Sensor;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import com.google.android.gms.maps.OnMapReadyCallback;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;

public class RecordFragment extends Fragment implements OnMapReadyCallback, SensorEventListener {
    private GoogleMap googleMap;

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

        return view;
    }



    @Override
    public void onMapReady(GoogleMap googleMap) {
        this.googleMap = googleMap;

        final LatLng center = new LatLng(35.1434021, 126.7988363);

        CameraPosition cameraPosition = new CameraPosition.Builder()
                .target(center).zoom(15).build();
        this.googleMap.moveCamera(CameraUpdateFactory
                .newCameraPosition(cameraPosition));

        Marker marker = this.googleMap.addMarker(new MarkerOptions()
                .position(new LatLng(35.1434021, 126.7988363))
                .title("광주소프트웨어마이스터고등학교"));
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

    // 걸음 수 체크용 함수들
    public void onStart() {
        super.onStart();
        if(stepCountSensor !=null){
            //센서의 속도 설정
            sensorManager.registerListener(this,stepCountSensor,SensorManager.SENSOR_DELAY_GAME);
        }
    }
    public void onStop(){
        super.onStop();
        if(sensorManager!=null){
            sensorManager.unregisterListener(this);
        }
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