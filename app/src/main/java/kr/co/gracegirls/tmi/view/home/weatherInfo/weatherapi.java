package kr.co.gracegirls.tmi.view.home.weatherInfo;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Query;

public interface weatherapi {
    @GET("weather")
    Call<Weather> getweather(@Query("q") String cityname,
                             @Query("appid") String apikey);
}
