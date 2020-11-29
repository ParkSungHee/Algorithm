package kr.co.gracegirls.tmi.view.record;

import android.Manifest;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.Toast;
import android.view.View.OnClickListener;

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

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;


public class RecordFragment extends Fragment implements OnMapReadyCallback,
        GoogleApiClient.ConnectionCallbacks,
        GoogleApiClient.OnConnectionFailedListener,
        ActivityCompat.OnRequestPermissionsResultCallback,
        LocationListener {
    private GoogleMap googleMap;
    private GpsTracker gpsTracker;
    private Polyline polylines;

    private static final int LOCATION_PERMISSION_REQUEST_CODE = 1;

    private GoogleApiClient mGoogleApiClient;
    private LocationRequest mLocationRequest;
    private Location mCurrentLocation;
    private Marker mCurrentMarker;
    private LatLng startLatLng = new LatLng(0, 0);        //polyline 시작점
    private LatLng endLatLng = new LatLng(0, 0);         //polyline 끝점
    private boolean walkState = false;                          //걸음 상태


    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_record, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("기록", false);

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.record_map);

        mapFragment.getMapAsync(this);

        if (mGoogleApiClient == null) {
            mGoogleApiClient = new GoogleApiClient.Builder(getActivity())
                    .addApi(LocationServices.API)
                    .addConnectionCallbacks(this)
                    .addOnConnectionFailedListener(this)
                    .build();
        }
        createLocationRequest();


        ImageButton start_button = view.findViewById(R.id.startButton);
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
        mGoogleApiClient.connect();
    }

    @Override
    public void onStop() {
        super.onStop();
        mGoogleApiClient.disconnect();
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

        if (mCurrentMarker != null) mCurrentMarker.remove();
        mCurrentLocation = location;
        MarkerOptions markerOptions = new MarkerOptions();
        markerOptions.position(new LatLng(latitude, longtitude));
        mCurrentMarker =  googleMap.addMarker(markerOptions);


        googleMap.animateCamera(CameraUpdateFactory.newLatLngZoom(
                new LatLng(mCurrentLocation.getLatitude(), mCurrentLocation.getLongitude()), 18));
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
            mCurrentLocation = LocationServices.FusedLocationApi.getLastLocation(mGoogleApiClient);
            // Start location updates.
            LocationServices.FusedLocationApi.requestLocationUpdates(
                    mGoogleApiClient, mLocationRequest, this);

            if (mCurrentLocation != null) {
                Log.i("Location", "Latitude: " + mCurrentLocation.getLatitude()
                        + ", Longitude: " + mCurrentLocation.getLongitude());
            }
        }
    }
    protected void createLocationRequest() {
        mLocationRequest = new LocationRequest();
        mLocationRequest.setInterval(10000);
        mLocationRequest.setFastestInterval(5000);
        mLocationRequest.setPriority(LocationRequest.PRIORITY_HIGH_ACCURACY);
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
            Toast.makeText(getActivity(), "지오코더 서비스 사용불가", Toast.LENGTH_LONG).show();
            return "지오코더 서비스 사용불가";
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
}