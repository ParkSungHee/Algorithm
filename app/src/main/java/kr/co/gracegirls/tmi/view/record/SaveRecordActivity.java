package kr.co.gracegirls.tmi.view.record;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

import kr.co.gracegirls.tmi.R;


public class SaveRecordActivity extends AppCompatActivity {
   private Intent intent;
   private ImageView imageView;
    private final int GET_GALLERY_IMAGE = 200;
    private ImageView imageview;
    private Button uploadBtn;

    private FragmentManager fragmentManager;
    private RecordSanstagramActivity mySanstagramFragment;
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
        uploadBtn=findViewById(R.id.upload_btn);
        uploadBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                moveSanstagram();


            }
        });


    }
    private void moveSanstagram() {
        Intent intent = new Intent(this, RecordSanstagramActivity.class);
        //recordSanstagramActivity시작
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
