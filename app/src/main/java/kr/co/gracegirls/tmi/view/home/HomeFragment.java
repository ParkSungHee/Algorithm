package kr.co.gracegirls.tmi.view.home;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.location.Location;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
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
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;

import java.util.ArrayList;
import java.util.List;

import Njava.util.function.MaybeUtil;
import io.reactivex.Maybe;
import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.util.GCGViewUtil;

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

        // BitmapDescriptorFactory 생성하기 위한 소스
        MapsInitializer.initialize(getActivity().getApplicationContext());

        SupportMapFragment mapFragment = (SupportMapFragment) getChildFragmentManager()
                .findFragmentById(R.id.home_map);

        mapFragment.getMapAsync(this); //지도 객체 얻기

        return view;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        this.googleMap = googleMap;

        LatLng seunghack = new LatLng(37.44237920148298, 126.68814372688384);

        MarkerOptions markerOptions1 = new MarkerOptions();
        markerOptions1.position(seunghack);
        markerOptions1.title("승학산");


        BitmapDrawable bitmapdraw1=(BitmapDrawable)getResources().getDrawable(R.drawable.danger);
        Bitmap b1=bitmapdraw1.getBitmap();
        Bitmap smallMarker1 = Bitmap.createScaledBitmap(b1, 100, 100, false);
        markerOptions1.icon(BitmapDescriptorFactory.fromBitmap(smallMarker1));


        googleMap.addMarker(markerOptions1);

        googleMap.moveCamera(CameraUpdateFactory.newLatLng(seunghack));
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(15));

        LatLng munhack = new LatLng(37.43297284354754, 126.67936844300222);

        MarkerOptions markerOptions2 = new MarkerOptions();
        markerOptions2.position(munhack);
        markerOptions2.title("문학산");


        BitmapDrawable bitmapdraw2=(BitmapDrawable)getResources().getDrawable(R.drawable.danger);
        Bitmap b2=bitmapdraw2.getBitmap();
        Bitmap smallMarker2 = Bitmap.createScaledBitmap(b2, 100, 100, false);
        markerOptions2.icon(BitmapDescriptorFactory.fromBitmap(smallMarker2));


        googleMap.addMarker(markerOptions2);

        LatLng subong = new LatLng(37.459951290094594, 126.66331831339058);

        MarkerOptions markerOptions3 = new MarkerOptions();
        markerOptions3.position(subong);
        markerOptions3.title("수봉산");


        BitmapDrawable bitmapdraw3=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b3=bitmapdraw3.getBitmap();
        Bitmap smallMarker3 = Bitmap.createScaledBitmap(b3, 100, 100, false);
        markerOptions3.icon(BitmapDescriptorFactory.fromBitmap(smallMarker3));


        googleMap.addMarker(markerOptions3);

        LatLng chung = new LatLng(37.42161694299056, 126.65797311321575);

        MarkerOptions markerOptions4 = new MarkerOptions();
        markerOptions4.position(chung);
        markerOptions4.title("청량산");


        BitmapDrawable bitmapdraw4=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b4=bitmapdraw4.getBitmap();
        Bitmap smallMarker4 = Bitmap.createScaledBitmap(b4, 100, 100, false);
        markerOptions4.icon(BitmapDescriptorFactory.fromBitmap(smallMarker4));


        googleMap.addMarker(markerOptions4);

        LatLng jubong = new LatLng(38.17428213313527, 128.54178643183315);

        MarkerOptions markerOptions5 = new MarkerOptions();
        markerOptions5.position(jubong);
        markerOptions5.title("주봉산");


        BitmapDrawable bitmapdraw5=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b5=bitmapdraw5.getBitmap();
        Bitmap smallMarker5 = Bitmap.createScaledBitmap(b5, 100, 100, false);
        markerOptions5.icon(BitmapDescriptorFactory.fromBitmap(smallMarker5));


        googleMap.addMarker(markerOptions5);

        LatLng seolak = new LatLng(38.17744047805365, 128.49960343368417);

        MarkerOptions markerOptions6 = new MarkerOptions();
        markerOptions6.position(seolak);
        markerOptions6.title("설악산");


        BitmapDrawable bitmapdraw6=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b6=bitmapdraw6.getBitmap();
        Bitmap smallMarker6 = Bitmap.createScaledBitmap(b6, 100, 100, false);
        markerOptions6.icon(BitmapDescriptorFactory.fromBitmap(smallMarker6));


        googleMap.addMarker(markerOptions6);

        LatLng chungdae = new LatLng(38.179900855708034, 128.56960158530646);

        MarkerOptions markerOptions7 = new MarkerOptions();
        markerOptions7.position(chungdae);
        markerOptions7.title("청대산");


        BitmapDrawable bitmapdraw7=(BitmapDrawable)getResources().getDrawable(R.drawable.watchout);
        Bitmap b7=bitmapdraw7.getBitmap();
        Bitmap smallMarker7 = Bitmap.createScaledBitmap(b7, 100, 100, false);
        markerOptions7.icon(BitmapDescriptorFactory.fromBitmap(smallMarker7));


        googleMap.addMarker(markerOptions7);

        LatLng gucksa = new LatLng(38.222634396570406, 128.56193099467598);

        MarkerOptions markerOptions8 = new MarkerOptions();
        markerOptions8.position(gucksa);
        markerOptions8.title("국사봉");


        BitmapDrawable bitmapdraw8=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b8=bitmapdraw8.getBitmap();
        Bitmap smallMarker8 = Bitmap.createScaledBitmap(b8, 100, 100, false);
        markerOptions8.icon(BitmapDescriptorFactory.fromBitmap(smallMarker8));


        googleMap.addMarker(markerOptions8);

        LatLng hanra = new LatLng(33.36302691656733, 126.52950980078691);

        MarkerOptions markerOptions9 = new MarkerOptions();
        markerOptions9.position(hanra);
        markerOptions9.title("한라산");


        BitmapDrawable bitmapdraw9=(BitmapDrawable)getResources().getDrawable(R.drawable.safe);
        Bitmap b9=bitmapdraw9.getBitmap();
        Bitmap smallMarker9 = Bitmap.createScaledBitmap(b9, 100, 100, false);
        markerOptions9.icon(BitmapDescriptorFactory.fromBitmap(smallMarker9));


        googleMap.addMarker(markerOptions9);

       // googleMap.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(37.44184293474863, 126.66703827786698)));
        googleMap.moveCamera(CameraUpdateFactory.newLatLng(hanra));
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(12));
        //TODO - 동적으로 바꾸어야함
        /*final LatLng munhack = new LatLng(37.43297284354754, 126.67936844300222);
        googleMap.moveCamera(CameraUpdateFactory.newLatLng(munhack));
        googleMap.moveCamera(CameraUpdateFactory.zoomTo(10));

        //ImageView img = (ImageView)findViewById(R.id.image);
        Resources res = getResources();
        Bitmap bitmap = BitmapFactory.decodeResource(res, R.drawable.danger);
        Bitmap bitmap2 = Bitmap.createScaledBitmap(bitmap, 1,1,false);


        Marker marker = this.googleMap.addMarker(new MarkerOptions()
                .position(munhack)
                .title("문학산"));

        Marker marker1 = this.googleMap.addMarker(new MarkerOptions()
                .position(new LatLng(37.44237920148298, 126.68814372688384))
                .title("승학산"));

        Marker subong = this.googleMap.addMarker(new MarkerOptions()
                .position(new LatLng(37.459951290094594, 126.66331831339058))
                .title("수봉산"));

        Marker marker3 = this.googleMap.addMarker(new MarkerOptions()
                .position(new LatLng(37.42161694299056, 126.65797311321575))
                .title("청량산"));
        if(ContextCompat.checkSelfPermission(getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            this.googleMap.setMyLocationEnabled(true);
        } else {
            checkLocationPermissionWithRationale();
        }

*/
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
