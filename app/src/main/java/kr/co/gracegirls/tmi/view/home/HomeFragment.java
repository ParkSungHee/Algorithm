package kr.co.gracegirls.tmi.view.home;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
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
import com.google.android.gms.maps.MapsInitializer;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
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

public class HomeFragment extends Fragment implements OnMapReadyCallback,
        ActivityCompat.OnRequestPermissionsResultCallback,
        GoogleMap.OnMapClickListener {

    private GoogleMap googleMap;
    private RecyclerView recyclerView;
    private HomeMountainAdapter homeMountainAdapter;
    private List<MountainListItem> mountainListItems;
    private List<LatLng> arrayPoints = new ArrayList<>();
    private List<MarkerOptions> arrayMarkerOptions = new ArrayList<>();
    private Marker marker;

    private MountainListListener mountainListListener;
    private FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();

    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);

        titleBar.init(getString(R.string.appName), false);
        recyclerView = view.findViewById(R.id.mountain_list);

        initMountainList();
        fireStoreAccessor.getMountainInformation(mountainListListener);


        // BitmapDescriptorFactory 생성하기 위한 소스
        MapsInitializer.initialize(getActivity().getApplicationContext());

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.home_map);

        mapFragment.getMapAsync(this); //지도 객체 얻기

        return view;
    }

    private void initMountainList() {
        mountainListItems = new ArrayList<>();

        mountainListListener = new MountainListListener() {
            @Override
            public void setMountainList(ArrayList<MountainListItem> mountainListItem) {
                mountainListItems = mountainListItem;
                homeMountainAdapter = new HomeMountainAdapter(getContext(), mountainListItems);
                recyclerView.setNestedScrollingEnabled(false);
                recyclerView.setAdapter(homeMountainAdapter);
            }

            @Override
            public void setShelterList(ArrayList<ShelterListItem> shelterListItems) {
            }
        };
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        this.googleMap = googleMap;


        googleMap.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(37.441706637533, 126.66733865898013)));
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(12));

        LatLng seunghack = new LatLng(37.44237920148298, 126.68814372688384);

        MarkerOptions seunghackMarker = new MarkerOptions();
        seunghackMarker.position(seunghack);
        seunghackMarker.title("승학산");


        BitmapDrawable bitmapdraw_seunghack=(BitmapDrawable)getResources().getDrawable(R.drawable.danger);
        Bitmap b_seunghack=bitmapdraw_seunghack.getBitmap();
        Bitmap smallMarker_seunghack = Bitmap.createScaledBitmap(b_seunghack, 100, 100, false);
        seunghackMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_seunghack));


        googleMap.addMarker(seunghackMarker);

    
        LatLng munhack = new LatLng(37.43297284354754, 126.67936844300222);

        MarkerOptions munhackMarker = new MarkerOptions();
        munhackMarker.position(munhack);
        munhackMarker.title("문학산");


        BitmapDrawable bitmapdraw_munhack=(BitmapDrawable)getResources().getDrawable(R.drawable.danger);
        Bitmap b_munhack=bitmapdraw_munhack.getBitmap();
        Bitmap smallMarker_munhack = Bitmap.createScaledBitmap(b_munhack, 100, 100, false);
        munhackMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_munhack));


        googleMap.addMarker(munhackMarker);

        LatLng subong = new LatLng(37.459951290094594, 126.66331831339058);

        MarkerOptions subongMarker = new MarkerOptions();
        subongMarker.position(subong);
        subongMarker.title("수봉산");


        BitmapDrawable bitmapdraw_subong=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_subong=bitmapdraw_subong.getBitmap();
        Bitmap smallMarker_subong = Bitmap.createScaledBitmap(b_subong, 100, 100, false);
        subongMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_subong));


        googleMap.addMarker(subongMarker);

        LatLng chung = new LatLng(37.42161694299056, 126.65797311321575);

        MarkerOptions chungMarker = new MarkerOptions();
        chungMarker.position(chung);
        chungMarker.title("청량산");


        BitmapDrawable bitmapdraw_chung=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b_chung=bitmapdraw_chung.getBitmap();
        Bitmap smallMarker_chung = Bitmap.createScaledBitmap(b_chung, 100, 100, false);
        chungMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_chung));


        googleMap.addMarker(chungMarker);

        LatLng jubong = new LatLng(38.17428213313527, 128.54178643183315);

        MarkerOptions jubongMarker = new MarkerOptions();
        jubongMarker.position(jubong);
        jubongMarker.title("주봉산");


        BitmapDrawable bitmapdraw_jubong=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b_jubong=bitmapdraw_jubong.getBitmap();
        Bitmap smallMarker_jubong = Bitmap.createScaledBitmap(b_jubong, 100, 100, false);
        jubongMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_jubong));


        googleMap.addMarker(jubongMarker);

        LatLng seolak = new LatLng(38.17744047805365, 128.49960343368417);

        MarkerOptions seolakMarker = new MarkerOptions();
        seolakMarker.position(seolak);
        seolakMarker.title("설악산");


        BitmapDrawable bitmapdraw_seolak=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b_seolak=bitmapdraw_seolak.getBitmap();
        Bitmap smallMarker_seolak = Bitmap.createScaledBitmap(b_seolak, 100, 100, false);
        seolakMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_seolak));


        googleMap.addMarker(seolakMarker);

        LatLng chungdae = new LatLng(38.179900855708034, 128.56960158530646);

        MarkerOptions chungdaeMarker = new MarkerOptions();
        chungdaeMarker.position(chungdae);
        chungdaeMarker.title("청대산");


        BitmapDrawable bitmapdraw_chungdae=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b_chungdae=bitmapdraw_chungdae.getBitmap();
        Bitmap smallMarker_chungdae = Bitmap.createScaledBitmap(b_chungdae, 100, 100, false);
        chungdaeMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_chungdae));


        googleMap.addMarker(chungdaeMarker);

        LatLng gucksa = new LatLng(38.222634396570406, 128.56193099467598);

        MarkerOptions gucksaMarker = new MarkerOptions();
        gucksaMarker.position(gucksa);
        gucksaMarker.title("국사봉");


        BitmapDrawable bitmapdraw_gucksa=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_gucksa=bitmapdraw_gucksa.getBitmap();
        Bitmap smallMarker_gucksa = Bitmap.createScaledBitmap(b_gucksa, 100, 100, false);
        gucksaMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_gucksa));


        googleMap.addMarker(gucksaMarker);

        LatLng hanra = new LatLng(33.36302691656733, 126.52950980078691);

        MarkerOptions hanraMarker = new MarkerOptions();
        hanraMarker.position(hanra);
        hanraMarker.title("한라산");


        BitmapDrawable bitmapdraw_hanra=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_hanra=bitmapdraw_hanra.getBitmap();
        Bitmap smallMarker_hanra = Bitmap.createScaledBitmap(b_hanra, 100, 100, false);
        hanraMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_hanra));


        googleMap.addMarker(hanraMarker);





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
                        googleMap.setMyLocationEnabled(true);
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

        googleMap.addMarker(markerOptions).showInfoWindow();

        // 맵셋팅
        arrayPoints.add(latLng);
        arrayMarkerOptions.add(markerOptions);
    }
}
