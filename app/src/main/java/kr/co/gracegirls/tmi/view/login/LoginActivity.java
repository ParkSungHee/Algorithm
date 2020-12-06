package kr.co.gracegirls.tmi.view.login;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.common.SignInButton;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FireStoreAccessor;
import kr.co.gracegirls.tmi.module.TitleBar;
import kr.co.gracegirls.tmi.view.common.MainActivity;
import kr.co.gracegirls.tmi.view.signup.SignUpActivity;
import kr.co.gracegirls.tmi.view.signup.SignUpDoneActivity;

import static kr.co.gracegirls.tmi.view.common.CommonConfig.START_ACTIVITY_STATUS;
import static kr.co.gracegirls.tmi.view.common.CommonConfig.START_FROM_SPLASH;

public class LoginActivity extends AppCompatActivity implements View.OnClickListener {

    private Context context = this;

    EditText emailInput, passwordInput;
    private String email, password;

    private FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();
    private LoginActionListener loginActionListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        Intent intent = getIntent();
        String startFrom = intent.getStringExtra(START_ACTIVITY_STATUS);

        TitleBar titleBar = findViewById(R.id.loginTitleBar);
        if (startFrom.equals(START_FROM_SPLASH)) {
            showWithoutLoginButton();
            titleBar.init(getString(R.string.login), false);
        } else {
            titleBar.init(getString(R.string.login), true);
        }

        findViewById(R.id.withoutLoginButton).setOnClickListener(this);
        findViewById(R.id.googleSignIn).setOnClickListener(this);
        findViewById(R.id.loginButton).setOnClickListener(this);
        findViewById(R.id.signUpText).setOnClickListener(this);

        emailInput = findViewById(R.id.emailInput);
        passwordInput = findViewById(R.id.passwordInput);

        loginActionListener = new LoginActionListener() {
            @Override
            public void login(boolean isSuccessful) {
                if (isSuccessful) {
                    Toast.makeText(context, "로그인 성공", Toast.LENGTH_SHORT).show();
                    startMainActivity();
                } else {
                    Toast.makeText(context, "로그인 실패", Toast.LENGTH_SHORT).show();
                }
            }
        };
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.withoutLoginButton:
                startMainActivity();
                break;

            case R.id.googleSignIn:
                Toast.makeText(context, "구글 로그인", Toast.LENGTH_SHORT).show();
                break;

            case R.id.loginButton:
                attemptLogin();
                break;

            case R.id.signUpText:
                startSignUpActivity();
                break;
        }
    }

    private void attemptLogin() {
        email = emailInput.getText().toString();
        password = passwordInput.getText().toString();
        if (!email.isEmpty() && !password.isEmpty()) {
            fireStoreAccessor.loginUser(email, password + "11", loginActionListener);
        } else {
            Toast.makeText(context, "이메일과 비밀번호를 바르게 입력해주세요.", Toast.LENGTH_SHORT).show();
        }
    }

    private void startMainActivity() {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }

    private void showWithoutLoginButton() {
        findViewById(R.id.withoutLoginButton).setVisibility(View.VISIBLE);
    }

    private void startSignUpActivity() {
        Intent intent = new Intent(this, SignUpActivity.class);
        startActivity(intent);
    }
}