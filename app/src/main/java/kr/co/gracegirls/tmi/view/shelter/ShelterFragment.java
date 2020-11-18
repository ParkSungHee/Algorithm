package kr.co.gracegirls.tmi.view.shelter;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

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

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.ShelterLIstItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class ShelterFragment extends Fragment implements OnMapReadyCallback {

    private GoogleMap mMap;
    private RecyclerView recyclerView;
    private ShelterListAdapter shelterListAdapter;
    private List<ShelterLIstItem> shelterLIstItems;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_shelter, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("대피소 현황", false);

        recyclerView = view.findViewById(R.id.shelter_list);

        shelterLIstItems = new ArrayList<>();
        shelterLIstItems.add(new ShelterLIstItem("대피소1", "강원도 속초시 설악동 산 1", "위도 : 11.111\n경도 : 11.111\n고도 : 11.111m", "수용인원 : 10\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소2", "강원도 속초시 설악동 산 2", "위도 : 22.222\n경도 : 22.222\n고도 : 22.222m", "수용인원 : 20\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소3", "강원도 속초시 설악동 산 3", "위도 : 33.333\n경도 : 33.333\n고도 : 33.333m", "수용인원 : 30\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소4", "강원도 속초시 설악동 산 4", "위도 : 44.444\n경도 : 44.444\n고도 : 44.444m", "수용인원 : 40\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소5", "강원도 속초시 설악동 산 5", "위도 : 55.555\n경도 : 55.555\n고도 : 55.555m", "수용인원 : 50\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소6", "강원도 속초시 설악동 산 6", "위도 : 66.666\n경도 : 66.666\n고도 : 66.666m", "수용인원 : 60\n예약 방법 : 인터넷"));
        shelterLIstItems.add(new ShelterLIstItem("대피소7", "강원도 속초시 설악동 산 7", "위도 : 77.777\n경도 : 77.777\n고도 : 77.777m", "수용인원 : 70\n예약 방법 : 인터넷"));
        shelterListAdapter = new ShelterListAdapter(shelterLIstItems);
        recyclerView.setNestedScrollingEnabled(false);
        recyclerView.setAdapter(shelterListAdapter);

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.shelter_map);

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