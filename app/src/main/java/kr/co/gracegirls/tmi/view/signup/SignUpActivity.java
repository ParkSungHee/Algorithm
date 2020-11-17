package kr.co.gracegirls.tmi.view.signup;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.module.TitleBar;

public class SignUpActivity extends AppCompatActivity {

    ConstraintLayout emailContentBox, nickNameContentBox, passwordContentBox, passwordDuplicateContentBox;
    Button signUpDoneButton;

    private Context context;
    private Animation translateUp, translateDown;

    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        init();
    }

    private void init() {
        context = this;
        TitleBar titleBar = findViewById(R.id.signUpTitleBar);
        titleBar.init("회원가입", false);

        emailContentBox = findViewById(R.id.emailContentBox);
        nickNameContentBox = findViewById(R.id.nicknameContentBox);
        passwordContentBox = findViewById(R.id.passwordContentBox);
        passwordDuplicateContentBox = findViewById(R.id.passwordDuplicateContentBox);
        signUpDoneButton = findViewById(R.id.signUpDoneButton);

        translateUp = AnimationUtils.loadAnimation(context, R.anim.translate_up);
        translateDown = AnimationUtils.loadAnimation(context, R.anim.translate_down);

        OpenMenuAnimationListener openMenuAnimationListener = new OpenMenuAnimationListener();
        translateUp.setAnimationListener(openMenuAnimationListener);
        translateDown.setAnimationListener(openMenuAnimationListener);
    }


    private void showNickNameInput() {
        nickNameContentBox.startAnimation(translateDown);
        nickNameContentBox.setVisibility(View.VISIBLE);
    }

    private void hideNickNameInput() {
        nickNameContentBox.startAnimation(translateUp);
        nickNameContentBox.setVisibility(View.GONE);
    }


    private void showPasswordInput() {
        passwordContentBox.startAnimation(translateDown);
        passwordContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordInput() {
        passwordContentBox.startAnimation(translateUp);
        passwordContentBox.setVisibility(View.GONE);
    }

    private void showPasswordDuplicateInput() {
        passwordDuplicateContentBox.startAnimation(translateDown);
        passwordDuplicateContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordDuplicateInput() {
        passwordDuplicateContentBox.startAnimation(translateUp);
        passwordDuplicateContentBox.setVisibility(View.VISIBLE);
    }

    class OpenMenuAnimationListener implements Animation.AnimationListener {

        @Override
        public void onAnimationStart(Animation animation) {

        }

        @Override
        public void onAnimationEnd(Animation animation) {

        }

        @Override
        public void onAnimationRepeat(Animation animation) {

        }
    }

}