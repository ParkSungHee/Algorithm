package kr.co.gracegirls.tmi.view.home;

import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapsInitializer;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.maps.model.PolylineOptions;

import java.util.ArrayList;
import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class HomeFragment extends Fragment implements OnMapReadyCallback,  GoogleMap.OnMapClickListener {
    private PolylineOptions polylineOptions;
    private GoogleMap mMap;
    private RecyclerView recyclerView;
    private HomeMountainAdapter homeMountainAdapter;
    private List<MountainListItem> mountainListItems;
    private List<LatLng> arrayPoints = new ArrayList<>();
    private List<MarkerOptions> arrayMarkerOptions = new ArrayList<>();

    // polyline 생성
    public void drawPolyline() {
        polylineOptions = new PolylineOptions();
        polylineOptions.color(Color.RED);
        polylineOptions.width(5);
        polylineOptions.addAll(arrayPoints);
        mMap.addPolyline(polylineOptions);
    }

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
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

        // BitmapDescriptorFactory 생성하기 위한 소스
        MapsInitializer.initialize(getActivity().getApplicationContext());

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.home_map);

        mapFragment.getMapAsync(this);

        return view;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        mMap.setOnMapClickListener(this);

        final LatLng center = new LatLng(35.1434021, 126.7988363);

        GooglePlayServicesUtil.isGooglePlayServicesAvailable(getActivity().getBaseContext());

        CameraPosition cameraPosition = new CameraPosition.Builder()
                .target(center).zoom(15).build();

        mMap.moveCamera(CameraUpdateFactory
                .newCameraPosition(cameraPosition));

            Marker marker = mMap.addMarker(new MarkerOptions()
                    .position(new LatLng(35.1434021, 126.7988363))
                    .title("광주소프트웨어마이스터고등학교"));
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
}