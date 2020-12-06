package kr.co.gracegirls.tmi.view.shelter;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.os.Bundle;

import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.Toast;

import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;

import java.util.ArrayList;
import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FireStoreAccessor;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class ShelterFragment extends Fragment implements OnMapReadyCallback {

    public static final int MY_PERMISSIONS_REQUEST_LOCATION = 99;

    private RecyclerView recyclerView;
    private ShelterListAdapter shelterListAdapter;
    private List<ShelterListItem> shelterListItems;
    private ShelterListListener shelterListListener;
    private FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();

    private ImageButton shelterSearch;
    private GoogleMap googleMap;

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
            }
        });

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
        this.googleMap = googleMap;

        if(ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            this.googleMap.setMyLocationEnabled(true);
        } else {
            checkLocationPermissionWithRationale();
        }
    }

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
                        googleMap.setMyLocationEnabled(true);
                    }
                } else {
                    Toast.makeText(getActivity(), "권한이 없습니다.\n설정 -> 권한 설정을 해주세요.", Toast.LENGTH_LONG).show();
                }
                return;
            }
        }
    }
}