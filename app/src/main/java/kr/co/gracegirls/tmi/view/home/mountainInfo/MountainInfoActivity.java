package kr.co.gracegirls.tmi.view.home.mountainInfo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.AppCompatImageView;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.bumptech.glide.Glide;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FirebaseConfig;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class MountainInfoActivity extends AppCompatActivity {

    private AppCompatImageView imageView;
    private TextView name, location, height, level, description;
    private Intent intent;
    private MountainListItem mountainListItem;
    private ConstraintLayout loadingView;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mountain_info);

        init();
    }

    private void init() {
        TitleBar titleBar = findViewById(R.id.mountain_info_title);
        titleBar.init("산 상세정보", true);
        titleBar.backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });

        loadingView = findViewById(R.id.loadingView);
        loadingView.setVisibility(View.VISIBLE);
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                hideLoadingView();
            }
        }, 800);

        intent = getIntent();
        mountainListItem = intent.getParcelableExtra(FirebaseConfig.MOUNTAIN);
        Log.d("TAG_A", "init: " + mountainListItem.toString());

        imageView = findViewById(R.id.mountain_image);
        Glide.with(this)
                .load(mountainListItem.getImgPath())
                .into(imageView);

        name = findViewById(R.id.mountain_name_text);
        name.setText(mountainListItem.getName());
        location = findViewById(R.id.mountain_location);
        location.setText(mountainListItem.getLocation());
        height = findViewById(R.id.mountain_height);
        height.setText(mountainListItem.getHeight());

        level = findViewById(R.id.mountain_level);
        int heightNumber = Integer.parseInt(mountainListItem.getHeight());
        if (heightNumber >= 1500) {
            level.setText("최상");
        } else if (heightNumber >= 1000) {
            level.setText("상");
        } else if (heightNumber >= 500) {
            level.setText("중");
        } else {
            level.setText("하");
        }


        description = findViewById(R.id.mountain_description);
        description.setText(mountainListItem.getDescription());
    }

    private void hideLoadingView() {
        loadingView.setVisibility(View.GONE);
    }
}