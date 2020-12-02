package kr.co.gracegirls.tmi.view.home;

import android.Manifest;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.DatePicker;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
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

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
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

    // 날짜 선택용 변수
    private DatePickerDialog.OnDateSetListener callBackMethodDate;
    private TextView datePick;
    // 시간 선택용 변수
    private TimePickerDialog.OnTimeSetListener callBackMethodTime;
    private TextView timePick;

    // 검색용 변수
    private ImageButton mntSearch;

    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);

        titleBar.init(getString(R.string.appName), false);
        recyclerView = view.findViewById(R.id.mountain_list);

        initMountainList();
        fireStoreAccessor.getMountainInformation(mountainListListener);

        // 검색 선언
        mntSearch=view.findViewById(R.id.search_button);

        // 날짜, 시간 초기화
        datePick = view.findViewById(R.id.date_button);
        timePick = view.findViewById(R.id.time_button);

        // 현재 날짜, 시각
        long start=System.currentTimeMillis();
        Date date=new Date(start);
        SimpleDateFormat sdfd=new SimpleDateFormat("yyyy-MM-dd");
        SimpleDateFormat sdft=new SimpleDateFormat("kk:mm");
        String getDate=sdfd.format(date);
        String getTime=sdft.format(date);
        datePick.setText("Date: "+getDate);
        timePick.setText("Time: "+getTime);

        // 검색용
        mntSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                initMountainList2();
                fireStoreAccessor.getMountainInformation(mountainListListener);
            }
        });

        // 날짜 선택용
        this.InitializeListenerDate();
        datePick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String[] date=getDate.split("-");
                String year=date[0];
                String month=date[1];
                String day=date[2];
                DatePickerDialog dialog=new DatePickerDialog(getContext(), callBackMethodDate, Integer.parseInt(year), Integer.parseInt(month)-1, Integer.parseInt(day));
                dialog.show();
            }
        });

        // 시간 선택용
        this.InitializeListenerTime();
        timePick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String[] time=getTime.split(":");
                String hour=time[0];
                String min=time[1];
                TimePickerDialog dialog=new TimePickerDialog(getContext(), callBackMethodTime, Integer.parseInt(hour), Integer.parseInt(min), true);
                dialog.show();
            }
        });


        // BitmapDescriptorFactory 생성하기 위한 소스
        MapsInitializer.initialize(getActivity().getApplicationContext());

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.home_map);

        mapFragment.getMapAsync(this); //지도 객체 얻기

        return view;
    }

    // datedialog에서 선택한 날짜 출력
    public void InitializeListenerDate() {
        callBackMethodDate=new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker datePicker, int year, int month, int date) {
                datePick.setText(String.format("Date: %04d-%02d-%02d", year, month+1, date));
            }
        };
    }

    // timedialog에서 선택한 시간 출력
    public void InitializeListenerTime() {
        callBackMethodTime=new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker timePicker, int hour, int min) {
                timePick.setText(String.format("Time: %02d:%02d", hour, min));
            }
        };
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

    private void initMountainList2() {
        mountainListItems = new ArrayList<>();

        mountainListListener = new MountainListListener() {

            @Override
            public void setMountainList(ArrayList<MountainListItem> mountainListItem) {
                mountainListItems = mountainListItem;
                List<MountainListItem> mountainListItems2=new ArrayList<>();
                //mountainListItems2.add(mountainListItems.get(2));

                mountainListItems2.add(mountainListItems.get(0));
                mountainListItems2.add(mountainListItems.get(3));
                mountainListItems2.add(mountainListItems.get(11));
                mountainListItems2.add(mountainListItems.get(16));

                homeMountainAdapter = new HomeMountainAdapter(getContext(), mountainListItems2);
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

        //TODO - 동적으로 바꾸어야함

        LatLng seunghack = new LatLng(37.44237920148298, 126.68814372688384);

        MarkerOptions seunghackMarker = new MarkerOptions();
        seunghackMarker.position(seunghack);
        seunghackMarker.title("승학산");


        BitmapDrawable bitmapdraw_seunghack=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_seunghack=bitmapdraw_seunghack.getBitmap();
        Bitmap smallMarker_seunghack = Bitmap.createScaledBitmap(b_seunghack, 100, 100, false);
        seunghackMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_seunghack));


        googleMap.addMarker(seunghackMarker);

        googleMap.moveCamera(CameraUpdateFactory.newLatLng(seunghack));
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(15));

        LatLng munhack = new LatLng(37.43297284354754, 126.67936844300222);

        MarkerOptions munhackMarker = new MarkerOptions();
        munhackMarker.position(munhack);
        munhackMarker.title("문학산");


        BitmapDrawable bitmapdraw_munhack=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
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


        BitmapDrawable bitmapdraw_jubong=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_jubong=bitmapdraw_jubong.getBitmap();
        Bitmap smallMarker_jubong = Bitmap.createScaledBitmap(b_jubong, 100, 100, false);
        jubongMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_jubong));


        googleMap.addMarker(jubongMarker);

        LatLng seolak = new LatLng(38.17744047805365, 128.49960343368417);

        MarkerOptions seolakMarker = new MarkerOptions();
        seolakMarker.position(seolak);
        seolakMarker.title("설악산");


        BitmapDrawable bitmapdraw_seolak=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b_seolak=bitmapdraw_seolak.getBitmap();
        Bitmap smallMarker_seolak = Bitmap.createScaledBitmap(b_seolak, 100, 100, false);
        seolakMarker.icon(BitmapDescriptorFactory.fromBitmap(smallMarker_seolak));


        googleMap.addMarker(seolakMarker);

        LatLng chungdae = new LatLng(38.179900855708034, 128.56960158530646);

        MarkerOptions chungdaeMarker = new MarkerOptions();
        chungdaeMarker.position(chungdae);
        chungdaeMarker.title("청대산");


        BitmapDrawable bitmapdraw_chungdae=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
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

        googleMap.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(37.44184293474863, 126.66703827786698)));
       // googleMap.moveCamera(CameraUpdateFactory.newLatLng(hanra));
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(12));




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
