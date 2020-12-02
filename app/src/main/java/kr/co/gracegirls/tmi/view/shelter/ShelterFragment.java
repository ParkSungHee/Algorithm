package kr.co.gracegirls.tmi.view.shelter;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;

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
import kr.co.gracegirls.tmi.data.firebase.FireStoreAccessor;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.home.HomeMountainAdapter;

public class ShelterFragment extends Fragment implements OnMapReadyCallback {

    private GoogleMap mMap;
    private RecyclerView recyclerView;
    private ShelterListAdapter shelterListAdapter;
    private List<ShelterListItem> shelterListItems;
    private ShelterListListener shelterListListener;
    private FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();

    private ImageButton shelterSearch;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_shelter, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("대피소 현황", false);

        recyclerView = view.findViewById(R.id.shelter_list);

        shelterSearch=view.findViewById(R.id.search_button);

        // 검색용
        shelterSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                initShelterList();
                //fireStoreAccessor.getMountainInformation(mountainListListener);
            }
        });


        //initShelterList();

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.shelter_map);

        mapFragment.getMapAsync(this);

        return view;
    }

    private void initShelterList() {
        shelterListListener = new ShelterListListener() {
            @Override
            public void setShelterList(ArrayList<ShelterListItem> shelterListItems) {
                List<ShelterListItem> shelterListItems2=new ArrayList<>();
                shelterListItems2.add(shelterListItems.get(0));
                shelterListItems2.add(shelterListItems.get(5));
                shelterListItems2.add(shelterListItems.get(6));
                shelterListItems2.add(shelterListItems.get(8));
                shelterListItems2.add(shelterListItems.get(9));

                shelterListAdapter = new ShelterListAdapter(shelterListItems2);
                recyclerView.setNestedScrollingEnabled(false);
                recyclerView.setAdapter(shelterListAdapter);
            }
        };
        fireStoreAccessor.getShelterList(shelterListListener);
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