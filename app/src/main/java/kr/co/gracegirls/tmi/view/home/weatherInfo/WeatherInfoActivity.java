package kr.co.gracegirls.tmi.view.home.weatherInfo;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import kr.co.gracegirls.tmi.R;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class WeatherInfoActivity extends AppCompatActivity {
    EditText et;
    TextView tv;
    String apikey = "1cd6d5d7944f94aaa2bbea173ec5e2bf";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_weather);

        et = findViewById(R.id.et);
        tv = findViewById(R.id.tv);

    }

    public void getweather(View v) {
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://api.openweathermap.org/data/2.5/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        weatherapi myapi = retrofit.create(weatherapi.class);
        Call<Weather> examplecall = myapi.getweather(et.getText().toString().trim(), apikey);
        examplecall.enqueue(new Callback<Weather>() {

            @Override
            public void onResponse(Call<Weather> call, Response<Weather> response) {
                if (response.code() == 404) {
                    Toast.makeText(WeatherInfoActivity.this, "도시 입력해주세요", Toast.LENGTH_LONG).show();
                }
                else if (!(response.isSuccessful())) {
                    Toast.makeText(WeatherInfoActivity.this, response.code(), Toast.LENGTH_LONG).show();
                }
                Weather mydata = response.body();
                Main main = mydata.getMain();
                Double temp = main.getTemp();
                Integer temperature = (int) (temp - 273.15);
                tv.setText(String.valueOf(temperature) + "C");
            }

            @Override
            public void onFailure(Call<Weather> call, Throwable t) {
                Toast.makeText(WeatherInfoActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }
}