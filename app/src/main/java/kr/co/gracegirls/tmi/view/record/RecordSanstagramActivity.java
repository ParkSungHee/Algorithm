package kr.co.gracegirls.tmi.view.record;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

import kr.co.gracegirls.tmi.R;

public class RecordSanstagramActivity extends AppCompatActivity {
    private Intent intent;
    private ImageView imageView;

    private FragmentManager fragmentManager;
    private RecordTrackActivity recordTrackActivity;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sanstagram);
        intent = getIntent();

        fragmentManager = getSupportFragmentManager();
        imageView=findViewById(R.id.sansta_img);
        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                startMypageActivity();
            }
        });

    }


    private void startMypageActivity() {
        Intent intent = new Intent(this, RecordTrackActivity.class);
        startActivity(intent);

    }
}
