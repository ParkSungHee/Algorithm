package kr.co.gracegirls.tmi.view.sos;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;

public class SosFragment extends Fragment {

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_sos, container, false);

        TitleBar titleBar = view.findViewById(R.id.sos_title_bar);
        titleBar.init("자동 구조 요청", false);

        return view;
    }
}