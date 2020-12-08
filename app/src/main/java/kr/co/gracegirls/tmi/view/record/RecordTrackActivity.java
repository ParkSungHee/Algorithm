package kr.co.gracegirls.tmi.view.record;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

import kr.co.gracegirls.tmi.R;

public class RecordTrackActivity extends AppCompatActivity {
    private Intent intent;
    private ImageView imageView;

    private FragmentManager fragmentManager;
    private RecordSanstagramActivity recordSanstagramActivity;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_record_final);
        intent = getIntent();
        imageView=(ImageView)findViewById(R.id.sansta_img_final);
        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                startMypageActivity();
            }
        });

    }
    private void startMypageActivity() {
        Intent intent = new Intent(this, RecordSanstagramActivity.class);
        startActivity(intent);
        //finish();
    }

}
