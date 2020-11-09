package kr.co.gracegirls.tmi.view.record;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

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

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;


public class RecordFragment extends Fragment implements OnMapReadyCallback {
    private GoogleMap mMap;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_record, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("기록", false);

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.record_map);

        mapFragment.getMapAsync(this);

        return view;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        final LatLng center = new LatLng(35.1434021, 126.7988363);

        CameraPosition cameraPosition = new CameraPosition.Builder()
                .target(center).zoom(15).build();
        mMap.moveCamera(CameraUpdateFactory
                .newCameraPosition(cameraPosition));

        Marker marker = mMap.addMarker(new MarkerOptions()
                .position(new LatLng(35.1434021, 126.7988363))
                .title("광주소프트웨어마이스터고등학교"));
    }
}