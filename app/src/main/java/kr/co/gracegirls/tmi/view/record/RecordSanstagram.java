package kr.co.gracegirls.tmi.view.record;

import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.mypage.MyPageFragment;

public class RecordSanstagram extends AppCompatActivity {
    private Intent intent;
    private ImageView imageView;

    private FragmentManager fragmentManager;
    private RecordTrack recordTrack;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_sanstagram);
        intent = getIntent();

        fragmentManager = getSupportFragmentManager();
        imageView=(ImageView)findViewById(R.id.sansta_img);
        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                startMypageActivity();
            }
        });

    }


    private void startMypageActivity() {
        Intent intent = new Intent(this, RecordTrack.class);
        startActivity(intent);
        //finish();
    }
}
