package kr.co.gracegirls.tmi.view.record;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;

public class RecordFragment extends Fragment {

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_record, container, false);

        TitleBar titleBar = view.findViewById(R.id.shelter_title_bar);
        titleBar.init("기록", false);

        return view;
    }
}