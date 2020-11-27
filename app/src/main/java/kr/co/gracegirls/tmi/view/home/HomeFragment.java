package kr.co.gracegirls.tmi.view.home;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.location.Location;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

import java.util.ArrayList;
import java.util.List;

import Njava.util.function.MaybeUtil;
import io.reactivex.Maybe;
import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class HomeFragment extends Fragment implements OnMapReadyCallback,
        ActivityCompat.OnRequestPermissionsResultCallback,
        GoogleMap.OnMapClickListener {

    private GoogleMap mMap;
    private RecyclerView recyclerView;
    private HomeMountainAdapter homeMountainAdapter;
    private List<MountainListItem> mountainListItems;
    private List<LatLng> arrayPoints = new ArrayList<>();
    private List<MarkerOptions> arrayMarkerOptions = new ArrayList<>();
    private Marker marker;

    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);

        titleBar.init(getString(R.string.appName), false);
        recyclerView = view.findViewById(R.id.mountain_list);

        mountainListItems = new ArrayList<>();
        mountainListItems.add(new MountainListItem("산0", 0, "우리집이다"));
        mountainListItems.add(new MountainListItem("산1", 10, "우리집이다1"));
        mountainListItems.add(new MountainListItem("산2", 20, "우리집이다2"));
        mountainListItems.add(new MountainListItem("산3", 30, "우리집이다3"));
        mountainListItems.add(new MountainListItem("산4", 40, "우리집이다4"));
        mountainListItems.add(new MountainListItem("산5", 50, "우리집이다5"));

        homeMountainAdapter = new HomeMountainAdapter(getContext(), mountainListItems);
        recyclerView.setNestedScrollingEnabled(false);
        recyclerView.setAdapter(homeMountainAdapter);

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.home_map);

        mapFragment.getMapAsync(this); //지도 객체 얻기

        return view;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        final LatLng center = new LatLng(35.1434021, 126.7988363);
        googleMap.moveCamera(CameraUpdateFactory.newLatLng(center));
        googleMap.moveCamera(CameraUpdateFactory.zoomTo(15));

        Marker marker = mMap.addMarker(new MarkerOptions()
                .position(center)
                .title("송정공원역"));

        if(ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            mMap.setMyLocationEnabled(true);
        } else {
            checkLocationPermissionWithRationale();
        }
    }
    public static final int MY_PERMISSIONS_REQUEST_LOCATION = 99;

    private void checkLocationPermissionWithRationale() {
        if (ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            if (ActivityCompat.shouldShowRequestPermissionRationale(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION)) {
                new AlertDialog.Builder(getActivity())
                        .setTitle("위치정보")
                        .setMessage("이 앱을 사용하기 위해서는 위치정보에 접근이 필요합니다. 위치정보 접근을 허용하여 주세요.")
                        .setPositiveButton("확인", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                ActivityCompat.requestPermissions(getActivity(), new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, MY_PERMISSIONS_REQUEST_LOCATION);
                            }
                        }).create().show();
            } else {
                ActivityCompat.requestPermissions(getActivity(), new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, MY_PERMISSIONS_REQUEST_LOCATION);
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_LOCATION: {
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    if (ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
                        mMap.setMyLocationEnabled(true);
                    }
                } else {
                    Toast.makeText(getActivity(), "permission denied", Toast.LENGTH_LONG).show();
                }
                return;
            }
        }
    }

    @Override
    public void onMapClick(LatLng latLng) {
        MarkerOptions markerOptions = new MarkerOptions();

        //add marker
        markerOptions.position(latLng);
        markerOptions.title("출발");

        mMap.addMarker(markerOptions).showInfoWindow();

        // 맵셋팅
        arrayPoints.add(latLng);
        arrayMarkerOptions.add(markerOptions);
    }

    public void setDrawMaker(Maybe<Location> myLocationMaybe) {
                MaybeUtil.Subscribe(myLocationMaybe,

                location -> {
                    // Creating a LatLng object for the current location
                    LatLng latLng = new LatLng(location.getLatitude(), location.getLongitude());

                    CameraPosition cp = new CameraPosition.Builder().target((latLng)).
                            zoom(17).
                            build();

                    // Showing the current location in Google Map
                    mMap.moveCamera(CameraUpdateFactory.newCameraPosition(cp));

                    // 기존 마커 삭제.
                    if (marker != null) {
                        marker.remove();
                    }

                    // 마커 설정.
                    MarkerOptions optFirst = new MarkerOptions().
                            position(latLng).
                            //icon(BitmapDescriptorFactory.fromResource(R.mipmap.ic_marker_pink)).
                            title("현재위치");
                            //title(MiRunResourceUtil.GetString(R.string.label_record_current_position));

                    marker = mMap.addMarker(optFirst);
                },
                () -> MiRunViewUtil.ShowToast("hi"));
    }
}
