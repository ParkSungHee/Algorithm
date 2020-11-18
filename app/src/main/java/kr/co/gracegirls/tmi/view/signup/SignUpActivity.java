package kr.co.gracegirls.tmi.view.signup;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.constraintlayout.widget.ConstraintSet;

import kr.co.gracegirls.tmi.R;
import kr.co.gracegirls.tmi.data.firebase.FireStoreAccessor;
import kr.co.gracegirls.tmi.data.metadata.SignUpMetaData;
import kr.co.gracegirls.tmi.module.TitleBar;

public class SignUpActivity extends AppCompatActivity implements View.OnClickListener {

    ConstraintLayout emailContentBox, nickNameContentBox, passwordContentBox, passwordDuplicateContentBox;
    Button emailDuplicationCheckButton, emailCheckDoneButton, signUpDoneButton;
    EditText emailInput, nicknameInput, passwordInput, passwordInput2;

    private Context context;
    private Animation translateUp, translateDown;


    private String email, nickName, password, passwordDuplicate;
    FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();
    private SignUpListener signUpListener;

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

        listenerInit();

        emailContentBox = findViewById(R.id.emailContentBox);
        nickNameContentBox = findViewById(R.id.nicknameContentBox);
        passwordContentBox = findViewById(R.id.passwordContentBox);
        passwordDuplicateContentBox = findViewById(R.id.passwordDuplicateContentBox);
        emailDuplicationCheckButton = findViewById(R.id.emailDuplicationCheckButton);
        emailDuplicationCheckButton.setOnClickListener(this);
        emailCheckDoneButton = findViewById(R.id.emailDuplicationCheckButton2);
        signUpDoneButton = findViewById(R.id.signUpDoneButton);
        signUpDoneButton.setOnClickListener(this);

        emailInput = findViewById(R.id.emailInput);
        nicknameInput = findViewById(R.id.nicknameInput);
        passwordInput = findViewById(R.id.passwordInput);
        passwordInput2 = findViewById(R.id.passwordDuplicateInput);

        translateUp = AnimationUtils.loadAnimation(context, R.anim.translate_up);
        translateDown = AnimationUtils.loadAnimation(context, R.anim.translate_down);

        OpenMenuAnimationListener openMenuAnimationListener = new OpenMenuAnimationListener();
        translateUp.setAnimationListener(openMenuAnimationListener);
        translateDown.setAnimationListener(openMenuAnimationListener);

    }

    private void listenerInit() {
        signUpListener = new SignUpListener() {
            @Override
            public boolean checkEmailDuplicate(String email) {
                return fireStoreAccessor.isEmailDuplicate(email);
            }

            @Override
            public boolean checkSignUpIsSuccessful(SignUpMetaData metaData) {
                return true;
            }
        };
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

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.emailDuplicationCheckButton:
                emailDuplicateCheck();
                break;
            case R.id.signUpDoneButton:

                break;
        }

    }

    private void emailDuplicateCheck() {
        email = emailInput.getText().toString();
        if (signUpListener.checkEmailDuplicate(email)) {
            emailDuplicationCheckButton.setClickable(false);
            emailInput.setClickable(false);
            emailCheckDoneButton.setVisibility(View.VISIBLE);
            emailDuplicationCheckButton.setVisibility(View.GONE);
            ConstraintLayout constraintLayout = findViewById(R.id.emailContentBox);
            ConstraintSet constraintSet = new ConstraintSet();
            constraintSet.clone(constraintLayout);
            constraintSet.connect(R.id.emailInput, ConstraintSet.END, R.id.emailDuplicationCheckButton2, ConstraintSet.START);
            constraintSet.applyTo(constraintLayout);
            showNickNameInput();
        } else {
            Toast.makeText(this, "존재하는 이메일입니다.", Toast.LENGTH_SHORT).show();
        }
    }

    static class OpenMenuAnimationListener implements Animation.AnimationListener {

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