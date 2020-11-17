package kr.co.gracegirls.tmi.view.signup;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;

public class SignUpActivity extends AppCompatActivity {

    ConstraintLayout emailContentBox, nickNameContentBox, passwordContentBox, passwordDuplicateContentBox;
    Button signUpDoneButton;

    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        init();
    }

    private void init() {
        TitleBar titleBar = findViewById(R.id.signUpTitleBar);
        titleBar.init("회원가입", false);

        emailContentBox = findViewById(R.id.emailContentBox);
        nickNameContentBox = findViewById(R.id.nicknameContentBox);
        passwordContentBox = findViewById(R.id.passwordContentBox);
        passwordDuplicateContentBox = findViewById(R.id.passwordDuplicateContentBox);
        signUpDoneButton = findViewById(R.id.signUpDoneButton);

        hideNickNameInput();
        hidePasswordInput();
        hidePasswordDuplicateInput();
    }


    private void showNickNameInput() {
        nickNameContentBox.setVisibility(View.VISIBLE);

    }

    private void hideNickNameInput() {
        nickNameContentBox.setVisibility(View.GONE);
    }


    private void showPasswordInput() {
        passwordContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordInput() {
        passwordContentBox.setVisibility(View.GONE);
    }

    private void showPasswordDuplicateInput() {
        passwordDuplicateContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordDuplicateInput() {
        passwordDuplicateContentBox.setVisibility(View.VISIBLE);
    }

}