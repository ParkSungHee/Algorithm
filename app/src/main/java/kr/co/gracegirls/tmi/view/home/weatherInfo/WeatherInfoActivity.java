package kr.co.gracegirls.tmi.view.home.weatherInfo;

import android.annotation.SuppressLint;
import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.text.SimpleDateFormat;
import java.util.Date;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class WeatherInfoActivity extends AppCompatActivity {
    private Intent intent;
    private String data;

    // 날짜 선택용 변수
    private DatePickerDialog.OnDateSetListener callBackMethodDate;
    private TextView datePick;
    // 시간 선택용 변수
    private TimePickerDialog.OnTimeSetListener callBackMethodTime;
    private TextView timePick;

    EditText weather_search;
    TextView weather_info;
    String apikey = "1cd6d5d7944f94aaa2bbea173ec5e2bf";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_weather);

        weather_search = findViewById(R.id.weather_search);
        weather_info = findViewById(R.id.weather_information);

        intent = getIntent();
        data = intent.getStringExtra("mountainName");


        init();

        // 날짜, 시간 초기화
        datePick = this.findViewById(R.id.weather_date_button);
        timePick = this.findViewById(R.id.weather_time_button);

        // 현재 날짜, 시각
        long start=System.currentTimeMillis();
        Date date=new Date(start);
        SimpleDateFormat sdfd=new SimpleDateFormat("yyyy-MM-dd");
        SimpleDateFormat sdft=new SimpleDateFormat("kk:mm");
        String getDate=sdfd.format(date);
        String getTime=sdft.format(date);
        datePick.setText("Date: "+getDate);
        timePick.setText("Time: "+getTime);


        // 날짜 선택용
        this.InitializeListenerDate();
        datePick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String[] date=getDate.split("-");
                String year=date[0];
                String month=date[1];
                String day=date[2];
                DatePickerDialog dialog=new DatePickerDialog(WeatherInfoActivity.this, callBackMethodDate, Integer.parseInt(year), Integer.parseInt(month)-1, Integer.parseInt(day));
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
                TimePickerDialog dialog=new TimePickerDialog(WeatherInfoActivity.this, callBackMethodTime, Integer.parseInt(hour), Integer.parseInt(min), true);
                dialog.show();
            }
        });

    }
    @SuppressLint("SetTextI18n")
    private void init() {
        weather_search.setText(data);

        TitleBar titleBar = findViewById(R.id.weather_TitleBar);
        titleBar.init("날씨", true);
        titleBar.backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });
    }

    public void getweather(View v) {
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://api.openweathermap.org/data/2.5/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        weatherapi myapi = retrofit.create(weatherapi.class);
        Call<WeatherInfo> examplecall = myapi.getweather(weather_search.getText().toString().trim(), apikey); //TODO : 영어로 바꿔서 넣어야 API 사용가능
        examplecall.enqueue(new Callback<WeatherInfo>() {

            @Override
            public void onResponse(Call<WeatherInfo> call, Response<WeatherInfo> response) {
                if (response.code() == 404) {
                    Toast.makeText(WeatherInfoActivity.this, "도시 입력해주세요", Toast.LENGTH_LONG).show();
                }
                else if (!(response.isSuccessful())) {
                    Toast.makeText(WeatherInfoActivity.this, response.code(), Toast.LENGTH_LONG).show();
                }
                WeatherInfo mydata = response.body();
                Main main = mydata.getMain();
                Double temp = main.getTemp();
                Integer temperature = (int) (temp - 273.15);
                Double cloudspeed = response.body().getWind().getSpeed();
                Integer humidity = response.body().getMain().getHumidity();
                weather_info.setText("기온 : " + String.valueOf(temperature) + "C"
                            +"\n풍속 : " + cloudspeed
                            + "\n습도 : " + humidity);
            }


            @Override
            public void onFailure(Call<WeatherInfo> call, Throwable t) {
                Toast.makeText(WeatherInfoActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
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
}