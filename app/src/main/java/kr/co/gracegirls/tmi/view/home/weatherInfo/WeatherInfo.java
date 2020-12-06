package kr.co.gracegirls.tmi.view.home.weatherInfo;

import com.google.gson.annotations.SerializedName;

public class WeatherInfo {
    @SerializedName("main") Main main;
    @SerializedName("wind") Wind wind;

    public Main getMain() {
        return main;
    }

    public Wind getWind() {
        return wind;
    }

    public void setMain(Main main) {
        this.main = main;
    }

}
