package kr.co.gracegirls.tmi.view.home.mountainshelter;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;

import java.util.ArrayList;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FireStoreAccessor;
import kr.co.gracegirls.tmi.data.firebase.FirebaseConfig;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.home.MountainListListener;
import kr.co.gracegirls.tmi.view.shelter.ShelterListAdapter;

public class MountainShelterActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private MountainListListener mountainListListener;
    private ArrayList<ShelterListItem> shelterListItems;
    private ShelterListAdapter shelterListAdapter;
    private ConstraintLayout shelterExistView, shelterNoExistView, loadingView;
    private FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();

    private Intent intent;
    private String mountainId;

    @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mountain_shelter);

        TitleBar titleBar = findViewById(R.id.mountain_shelter_title);
        titleBar.init("대피소", true);
        titleBar.backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });

        intent = getIntent();
        mountainId = intent.getStringExtra(FirebaseConfig.MOUNTAIN_ID);


        recyclerView = findViewById(R.id.shelter_list);
        shelterExistView = findViewById(R.id.shelter_list_view);
        shelterExistView.setVisibility(View.GONE);
        shelterNoExistView = findViewById(R.id.shelter_non_view);
        shelterNoExistView.setVisibility(View.GONE);
        loadingView = findViewById(R.id.loadingView);
        loadingView.setVisibility(View.VISIBLE);

        mountainListListener = new MountainListListener() {
            @Override
            public void setMountainList(ArrayList<MountainListItem> mountainListItems) {
            }

            @Override
            public void setShelterList(ArrayList<ShelterListItem> shelterListItems) {
                Handler handler = new Handler();
                handler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        hideLoadingView();
                        if (shelterListItems.size() == 0) {
                            showNoExistView();
                        } else {
                            shelterListAdapter = new ShelterListAdapter(shelterListItems);
                            recyclerView.setNestedScrollingEnabled(false);
                            recyclerView.setAdapter(shelterListAdapter);
                            showExistView();
                        }

                    }
                }, 800);
            }
        };

        fireStoreAccessor.getMountainShelterList(mountainListListener, mountainId);
    }

    public void hideLoadingView() {
        loadingView.setVisibility(View.GONE);
    }

    public void showExistView() {
        shelterExistView.setVisibility(View.VISIBLE);
    }

    public void showNoExistView() {
        shelterNoExistView.setVisibility(View.VISIBLE);
    }
}