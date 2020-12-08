package kr.co.gracegirls.tmi.view.common;

import android.os.Bundle;
import android.os.Handler;
import android.view.MenuItem;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import com.google.android.material.bottomnavigation.BottomNavigationView;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.view.home.HomeFragment;
import kr.co.gracegirls.tmi.view.mypage.MyPageFragment;
import kr.co.gracegirls.tmi.view.record.RecordFragment;
import kr.co.gracegirls.tmi.view.record.RecordSanstagramActivity;
import kr.co.gracegirls.tmi.view.shelter.ShelterFragment;
import kr.co.gracegirls.tmi.view.sos.SosFragment;

public class MainActivity extends AppCompatActivity {

    private FragmentManager fragmentManager;
    private HomeFragment homeFragment;
    private RecordFragment recordFragment;
    private SosFragment sosFragment;
    private ShelterFragment shelterFragment;
    private MyPageFragment myPageFragment;
    private BottomNavigationView bottomNavigationView;
    private RecordSanstagramActivity recordSanstagramActivity;
    private ConstraintLayout loadingView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        bottomNavigationView = findViewById(R.id.nav_view);
        bottomNavigationView.setOnNavigationItemSelectedListener(new ItemSelectedListener());
        loadingView = findViewById(R.id.loadingView);
        loadingView.setVisibility(View.VISIBLE);
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                loadingView.setVisibility(View.GONE);
            }
        }, 1500);

        fragmentManager = getSupportFragmentManager();
        homeFragment = new HomeFragment();
        FragmentTransaction transaction = fragmentManager.beginTransaction();
        transaction.replace(R.id.frameLayout, homeFragment).commit();
    }

    class ItemSelectedListener implements BottomNavigationView.OnNavigationItemSelectedListener {


        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.home:
                    if (homeFragment == null) {
                        homeFragment = new HomeFragment();
                        fragmentManager.beginTransaction().add(R.id.frameLayout, homeFragment).commit();
                    }
                    if (homeFragment != null) {
                        fragmentManager.beginTransaction().show(homeFragment).commit();
                    }
                    if (recordFragment != null) {
                        fragmentManager.beginTransaction().hide(recordFragment).commit();
                    }
                    if (sosFragment != null) {
                        fragmentManager.beginTransaction().hide(sosFragment).commit();
                    }
                    if (shelterFragment != null) {
                        fragmentManager.beginTransaction().hide(shelterFragment).commit();
                    }
                    if (myPageFragment != null) {
                        fragmentManager.beginTransaction().hide(myPageFragment).commit();
                    }
                    break;
                case R.id.record:
                    if (recordFragment == null) {
                        recordFragment = new RecordFragment();
                        fragmentManager.beginTransaction().add(R.id.frameLayout, recordFragment).commit();
                    }
                    if (homeFragment != null) {
                        fragmentManager.beginTransaction().hide(homeFragment).commit();
                    }
                    if (recordFragment != null) {
                        fragmentManager.beginTransaction().show(recordFragment).commit();
                    }
                    if (sosFragment != null) {
                        fragmentManager.beginTransaction().hide(sosFragment).commit();
                    }
                    if (shelterFragment != null) {
                        fragmentManager.beginTransaction().hide(shelterFragment).commit();
                    }
                    if (myPageFragment != null) {
                        fragmentManager.beginTransaction().hide(myPageFragment).commit();
                    }
                    break;
                case R.id.sos:
                    if (sosFragment == null) {
                        sosFragment = new SosFragment();
                        fragmentManager.beginTransaction().add(R.id.frameLayout, sosFragment).commit();
                    }
                    if (homeFragment != null) {
                        fragmentManager.beginTransaction().hide(homeFragment).commit();
                    }
                    if (recordFragment != null) {
                        fragmentManager.beginTransaction().hide(recordFragment).commit();
                    }
                    if (sosFragment != null) {
                        fragmentManager.beginTransaction().show(sosFragment).commit();
                    }
                    if (shelterFragment != null) {
                        fragmentManager.beginTransaction().hide(shelterFragment).commit();
                    }
                    if (myPageFragment != null) {
                        fragmentManager.beginTransaction().hide(myPageFragment).commit();
                    }
                    break;
                case R.id.shelter:
                    if (shelterFragment == null) {
                        shelterFragment = new ShelterFragment();
                        fragmentManager.beginTransaction().add(R.id.frameLayout, shelterFragment).commit();
                    }
                    if (homeFragment != null) {
                        fragmentManager.beginTransaction().hide(homeFragment).commit();
                    }
                    if (recordFragment != null) {
                        fragmentManager.beginTransaction().hide(recordFragment).commit();
                    }
                    if (sosFragment != null) {
                        fragmentManager.beginTransaction().hide(sosFragment).commit();
                    }
                    if (shelterFragment != null) {
                        fragmentManager.beginTransaction().show(shelterFragment).commit();
                    }
                    if (myPageFragment != null) {
                        fragmentManager.beginTransaction().hide(myPageFragment).commit();
                    }
                    break;
                case R.id.myPage:
                    if (myPageFragment == null) {
                        myPageFragment = new MyPageFragment();
                        fragmentManager.beginTransaction().add(R.id.frameLayout, myPageFragment).commit();
                    }
                    if (homeFragment != null) {
                        fragmentManager.beginTransaction().hide(homeFragment).commit();
                    }
                    if (recordFragment != null) {
                        fragmentManager.beginTransaction().hide(recordFragment).commit();
                    }
                    if (sosFragment != null) {
                        fragmentManager.beginTransaction().hide(sosFragment).commit();
                    }
                    if (shelterFragment != null) {
                        fragmentManager.beginTransaction().hide(shelterFragment).commit();
                    }
                    if (myPageFragment != null) {
                        fragmentManager.beginTransaction().show(myPageFragment).commit();
                    }
                    break;


            }
            return true;
        }
    }

}