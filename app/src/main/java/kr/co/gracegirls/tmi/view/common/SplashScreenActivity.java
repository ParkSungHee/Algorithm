package kr.co.gracegirls.tmi.view.common;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.gun0912.tedpermission.PermissionListener;
import com.gun0912.tedpermission.TedPermission;

import java.util.List;

import kr.co.gracegirls.tmi.view.login.LoginActivity;

import static kr.co.gracegirls.tmi.view.common.CommonConfig.START_ACTIVITY_STATUS;
import static kr.co.gracegirls.tmi.view.common.CommonConfig.START_FROM_SPLASH;

public class SplashScreenActivity extends AppCompatActivity {
    private CheckPermissionListener checkPermissionListener = new CheckPermissionListener();
    private Context context = this;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        TedPermission.with(this)
                .setPermissionListener(checkPermissionListener)
                .setDeniedMessage("설정에 들어가서 권한 설정 부탁드립니다.")
                .setPermissions(Manifest.permission.ACCESS_FINE_LOCATION, Manifest.permission.ACCESS_COARSE_LOCATION)
                .check();
        ;
    }

    private void startMainActivity() {
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                Intent intent = new Intent(SplashScreenActivity.this, LoginActivity.class);
                intent.putExtra(START_ACTIVITY_STATUS, START_FROM_SPLASH);
                startActivity(intent);
                finish();
            }
        }, 1000);
    }

    private class CheckPermissionListener implements PermissionListener {

        @Override
        public void onPermissionGranted() {
            startMainActivity();
        }

        @Override
        public void onPermissionDenied(List<String> deniedPermissions) {
            Toast.makeText(context, "권한 설정 후 앱을 사용 해주세요!", Toast.LENGTH_SHORT).show();
            finishAffinity();
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        finishAffinity();
    }
}

