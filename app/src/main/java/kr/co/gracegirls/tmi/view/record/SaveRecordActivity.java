package kr.co.gracegirls.tmi.view.record;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FirebaseConfig;
import kr.co.gracegirls.tmi.view.common.CommonConfig;
import kr.co.gracegirls.tmi.view.common.MainActivity;
import kr.co.gracegirls.tmi.view.home.mountainshelter.MountainShelterActivity;
import kr.co.gracegirls.tmi.view.mypage.MyPageFragment;
import kr.co.gracegirls.tmi.view.record.RecordSanstagram;


public class SaveRecordActivity extends AppCompatActivity {
   private Intent intent;
   private ImageView imageView;
    private final int GET_GALLERY_IMAGE = 200;
    private ImageView imageview;
    private Button uploadBtn;

    private FragmentManager fragmentManager;
    private RecordSanstagram mySanstagramFragment;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_save);
        imageview = (ImageView)findViewById(R.id.user_image);
        imageview.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

                Intent intent = new Intent(Intent.ACTION_PICK);
                intent. setDataAndType(android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI, "image/*");
                startActivityForResult(intent, GET_GALLERY_IMAGE);
            }
        });

        fragmentManager = getSupportFragmentManager();
        uploadBtn=(Button) findViewById(R.id.upload_btn);
        uploadBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                moveSanstagram();


            }
        });


    }
    private void moveSanstagram() {
        Intent intent = new Intent(this, RecordSanstagram.class);
//        intent.putExtra(FirebaseConfig.MOUNTAIN_ID, data.getDocumentID());
        startActivity(intent);
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(0,0,null);
        if (requestCode == GET_GALLERY_IMAGE && resultCode == RESULT_OK && data != null && data.getData() != null) {

            Uri selectedImageUri = data.getData();
            imageview.setImageURI(selectedImageUri);

        }

    }


    

}
