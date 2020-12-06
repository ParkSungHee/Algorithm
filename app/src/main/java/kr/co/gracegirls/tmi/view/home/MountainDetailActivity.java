package kr.co.gracegirls.tmi.view.home;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.DatePicker;
import android.widget.ImageView;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Date;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FirebaseConfig;
import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.common.CommonConfig;
import kr.co.gracegirls.tmi.view.home.mountainInfo.MountainInfoActivity;
import kr.co.gracegirls.tmi.view.home.mountainshelter.MountainShelterActivity;
import kr.co.gracegirls.tmi.view.home.weatherInfo.WeatherInfoActivity;

public class MountainDetailActivity extends AppCompatActivity implements View.OnClickListener {

    private Intent intent;
    private MountainListItem data;
    private ImageView imageView;
    private TextView mountainTitle, choiceDay, showWeather, showDetail, showShelter;

    // 날짜 선택용 변수
    TextView datePick;
    private String getDate;

    // 날짜 선택용 변수
    private DatePickerDialog.OnDateSetListener callBackMethodDate;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mountain_detail);

        intent = getIntent();
        data = intent.getParcelableExtra(CommonConfig.ITEM);
        Log.d("TAG_A", "onCreate: " + data.toString());

        init();
        this.InitializeListenerDate();
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

        // 날짜 초기화
        datePick = findViewById(R.id.choice_day);
        long start = System.currentTimeMillis();
        Date date = new Date(start);
        SimpleDateFormat sdfd = new SimpleDateFormat("yyyy-MM-dd");
        getDate = sdfd.format(date);
        datePick.setText("Date: " + getDate);

        if (Double.parseDouble(data.getRiskPoint()) <= 75.0) {
            imageView.setImageResource(R.drawable.icon_safe);
        } else if (Double.parseDouble(data.getRiskPoint()) < 80.0) {
            imageView.setImageResource(R.drawable.icon_caution);
        } else {
            imageView.setImageResource(R.drawable.icon_danger);
        }
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.choice_day:
                String[] date = getDate.split("-");
                String year = date[0];
                String month = date[1];
                String day = date[2];
                DatePickerDialog dialog = new DatePickerDialog(this, callBackMethodDate, Integer.parseInt(year), Integer.parseInt(month) - 1, Integer.parseInt(day));
                dialog.show();
                break;

            case R.id.show_weather:
                startWeatherInfoActivity();
                break;

            case R.id.show_detail:
                startMountainInfoActivity();
                break;

            case R.id.show_shelter:
                startMountainShelterListActivity();
                break;
        }
    }

    // datedialog에서 선택한 날짜 출력
    public void InitializeListenerDate() {
        callBackMethodDate = new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker datePicker, int year, int month, int date) {
                datePick.setText(String.format("%04d-%02d-%02d", year, month + 1, date));
            }
        };
    }

    private void startMountainShelterListActivity() {
        Intent intent = new Intent(this, MountainShelterActivity.class);
        intent.putExtra(FirebaseConfig.MOUNTAIN_ID, data.getDocumentID());
        startActivity(intent);
    }

    private void startMountainInfoActivity() {
        Intent intent = new Intent(this, MountainInfoActivity.class);
        intent.putExtra(FirebaseConfig.MOUNTAIN, data);
        Log.d("TAG_A", "startMountainInfoActivity: " + data.toString());
        startActivity(intent);
    }

    private void startWeatherInfoActivity(){
        Intent intent = new Intent(this, WeatherInfoActivity.class);
        intent.putExtra("mountainName", data.getName());
        startActivity(intent);
    }
}