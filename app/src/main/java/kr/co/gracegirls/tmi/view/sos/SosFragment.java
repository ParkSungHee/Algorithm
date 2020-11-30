package kr.co.gracegirls.tmi.view.sos;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.record.GpsTracker;

public class SosFragment extends Fragment {
    private GpsTracker gpsTracker;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.fragment_sos, container, false);

        TitleBar titleBar = view.findViewById(R.id.sos_title_bar);
        titleBar.init("자동 구조 요청", false);

        TextView lat = view.findViewById(R.id.text1);
        TextView lng = view.findViewById(R.id.text2);

        gpsTracker = new GpsTracker(getActivity());

        double latitude = gpsTracker.getLatitude();
        double longitude = gpsTracker.getLongitude();

        TextView current_location = view.findViewById(R.id.current_location_button);
        current_location.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                lat.setText("현재 위도: "+Double.toString(latitude));
                lng.setText("현재 경도: "+Double.toString(longitude));
            }
        });


        ImageButton sos_button = view.findViewById(R.id.sos_button);
        sos_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getActivity(), "구조를 요청했습니다.", Toast.LENGTH_LONG).show();
            }
        });
        return view;
    }
}