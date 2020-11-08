package kr.co.gracegirls.tmi.view.home;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.MountainListItem;
import kr.co.gracegirls.tmi.module.TitleBar;

public class HomeFragment extends Fragment {

    private RecyclerView recyclerView;
    private HomeMountainAdapter homeMountainAdapter;
    private List<MountainListItem> mountainListItems;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        TitleBar titleBar = view.findViewById(R.id.home_title_bar);

        titleBar.init(getString(R.string.appName), false);
        recyclerView = view.findViewById(R.id.mountain_list);

        mountainListItems = new ArrayList<>();
        mountainListItems.add(new MountainListItem("산0", 0, "우리집이다"));
        mountainListItems.add(new MountainListItem("산1", 10, "우리집이다1"));
        mountainListItems.add(new MountainListItem("산2", 20, "우리집이다2"));
        mountainListItems.add(new MountainListItem("산3", 30, "우리집이다3"));
        mountainListItems.add(new MountainListItem("산4", 40, "우리집이다4"));
        mountainListItems.add(new MountainListItem("산5", 50, "우리집이다5"));

        homeMountainAdapter = new HomeMountainAdapter(getContext(), mountainListItems);
        recyclerView.setNestedScrollingEnabled(false);
        recyclerView.setAdapter(homeMountainAdapter);

        return view;
    }
}