package kr.co.gracegirls.tmi.view.home;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FirebaseConfig;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.common.CommonConfig;
import kr.co.gracegirls.tmi.view.home.mountainshelter.MountainShelterActivity;

public class MountainDetailActivity extends AppCompatActivity implements View.OnClickListener {

    private Intent intent;
    private MountainListItem data;
    private ImageView imageView;
    private TextView mountainTitle, choiceDay, showWeather, showDetail, showShelter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mountain_detail);

        intent = getIntent();
        data = intent.getParcelableExtra(CommonConfig.ITEM);

        init();
    }

    @SuppressLint("SetTextI18n")
    private void init() {
        TitleBar titleBar = findViewById(R.id.detailTitleBar);
        titleBar.init(data.getName(), true);
        titleBar.backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });

        imageView = findViewById(R.id.risk_index);
        mountainTitle = findViewById(R.id.mountain_title);
        choiceDay = findViewById(R.id.choice_day);
        choiceDay.setOnClickListener(this);
        showWeather = findViewById(R.id.show_weather);
        showWeather.setOnClickListener(this);
        showDetail = findViewById(R.id.show_detail);
        showDetail.setOnClickListener(this);
        showShelter = findViewById(R.id.show_shelter);
        showShelter.setOnClickListener(this);

        mountainTitle.setText("위험지수 : " + data.getRiskPoint());

        if (Integer.parseInt(data.getRiskPoint()) <= 5) {
            imageView.setImageResource(R.drawable.icon_safe);
        } else if (Integer.parseInt(data.getRiskPoint()) <= 10) {
            imageView.setImageResource(R.drawable.icon_caution);
        } else {
            imageView.setImageResource(R.drawable.icon_danger);
        }
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.show_shelter:
                startMountainShelterListActivity();
                break;
        }

    }

    private void startMountainShelterListActivity() {
        Intent intent = new Intent(this, MountainShelterActivity.class);
        intent.putExtra(FirebaseConfig.MOUNTAIN_ID, data.getDocumentID());
        startActivity(intent);
    }
}