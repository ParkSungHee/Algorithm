package kr.co.gracegirls.tmi.view.signup;

import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Patterns;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
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
    Button emailDuplicationCheckButton, emailCheckDoneButton, signUpDoneButton, signUpDoneButton2, nickNameUseButton, nickNameUseButton2;
    EditText emailInput, nicknameInput, passwordInput, passwordInput2;

    TextView passwordDuplicateTrue, passwordDuplicateFalse;

    private Context context;
    private Animation translateUp, translateDown;


    private String email, nickName, password, passwordDuplicate;
    FireStoreAccessor fireStoreAccessor = new FireStoreAccessor();
    private SignUpListener signUpListener;

    private boolean nicknameOpen, passwordOpen, passwordOpen2;

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
        emailCheckDoneButton.setOnClickListener(this);
        emailCheckDoneButton.setClickable(false);
        signUpDoneButton = findViewById(R.id.signUpDoneButton);
        signUpDoneButton.setOnClickListener(this);
        signUpDoneButton2 = findViewById(R.id.signUpDoneButton2);
        nickNameUseButton = findViewById(R.id.nicknameUseButton);
        nickNameUseButton.setOnClickListener(this);
        nickNameUseButton2 = findViewById(R.id.nicknameUseButton2);
        nickNameUseButton2.setOnClickListener(this);
        nickNameUseButton2.setClickable(false);

        emailInput = findViewById(R.id.emailInput);
        nicknameInput = findViewById(R.id.nicknameInput);
        passwordInput = findViewById(R.id.passwordInput);
        passwordInput2 = findViewById(R.id.passwordDuplicateInput);
        passwordDuplicateTrue = findViewById(R.id.passwordDuplicateTrue);
        passwordDuplicateFalse = findViewById(R.id.passwordDuplicateFalse);
        textChanging();

        translateUp = AnimationUtils.loadAnimation(context, R.anim.translate_up);
        translateDown = AnimationUtils.loadAnimation(context, R.anim.translate_down);

        OpenMenuAnimationListener openMenuAnimationListener = new OpenMenuAnimationListener();
        translateUp.setAnimationListener(openMenuAnimationListener);
        translateDown.setAnimationListener(openMenuAnimationListener);
    }

    private void textChanging() {
        passwordInput.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                if (charSequence.length() == 4) {
                    showPasswordDuplicateInput();
                } else {
                    hidePasswordDuplicateInput();
                }
            }

            @Override
            public void afterTextChanged(Editable editable) {
            }
        });

        passwordInput2.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            }

            @Override
            public void afterTextChanged(Editable editable) {
                password = passwordInput.getText().toString();
                passwordDuplicate = passwordInput2.getText().toString();
                if (password.equals(passwordDuplicate)) {
                    passwordDuplicateTrue.setVisibility(View.VISIBLE);
                    passwordDuplicateFalse.setVisibility(View.GONE);
                    signUpDoneButton.setVisibility(View.VISIBLE);
                    signUpDoneButton2.setVisibility(View.GONE);
                } else {
                    passwordDuplicateTrue.setVisibility(View.GONE);
                    passwordDuplicateFalse.setVisibility(View.VISIBLE);
                    signUpDoneButton.setVisibility(View.GONE);
                    signUpDoneButton2.setVisibility(View.VISIBLE);
                }
            }
        });
    }

    private void showNickNameInput() {
        nicknameOpen = true;
        nickNameContentBox.startAnimation(translateDown);
        nickNameContentBox.setVisibility(View.VISIBLE);
    }

    private void hideNickNameInput() {
        if (nicknameOpen) {
            nicknameInput.setText("");
            nickNameContentBox.startAnimation(translateUp);
            nickNameContentBox.setVisibility(View.GONE);
            nicknameOpen = false;
        }
    }


    private void showPasswordInput() {
        passwordOpen = true;
        passwordContentBox.startAnimation(translateDown);
        passwordContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordInput() {
        if (passwordOpen) {
            passwordInput.setText("");
            passwordContentBox.startAnimation(translateUp);
            passwordContentBox.setVisibility(View.GONE);
            passwordOpen = false;
        }
    }

    private void showPasswordDuplicateInput() {
        passwordOpen2 = true;
        passwordDuplicateContentBox.startAnimation(translateDown);
        passwordDuplicateContentBox.setVisibility(View.VISIBLE);
    }

    private void hidePasswordDuplicateInput() {
        if (passwordOpen2) {
            passwordInput2.setText("");
            passwordDuplicateTrue.setVisibility(View.GONE);
            passwordDuplicateFalse.setVisibility(View.GONE);
            passwordDuplicateContentBox.startAnimation(translateUp);
            passwordDuplicateContentBox.setVisibility(View.GONE);
            passwordOpen2 = false;
        }
    }

    private void listenerInit() {
        signUpListener = new SignUpListener() {
            @Override
            public void checkEmailDuplicate(boolean isExist) {
                emailDuplicateCheck(isExist);
            }

            @Override
            public boolean checkSignUpIsSuccessful(SignUpMetaData data) {
                return false;
            }
        };
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.emailDuplicationCheckButton:
                email = emailInput.getText().toString();
                if (Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
                    fireStoreAccessor.checkEmailDuplicate(email, signUpListener);
                } else {
                    Toast.makeText(context, getString(R.string.email_validation_check_false), Toast.LENGTH_SHORT).show();
                }
                break;
            case R.id.emailDuplicationCheckButton2:
                emailResetting();
                break;
            case R.id.nicknameUseButton:
                nickNameUsingThis(true);
                break;
            case R.id.nicknameUseButton2:
                nickNameUsingThis(false);
                break;
            case R.id.signUpDoneButton:

                break;
        }

    }

    private void nickNameUsingThis(boolean flag) {
        ConstraintLayout constraintLayout = findViewById(R.id.nicknameContentBox);
        ConstraintSet constraintSet = new ConstraintSet();
        if (flag) {
            nickName = nicknameInput.getText().toString();
            nickNameUseButton.setVisibility(View.GONE);
            nicknameInput.setFocusable(false);
            nickNameUseButton2.setVisibility(View.VISIBLE);
            nickNameUseButton2.setClickable(true);
            constraintSet.clone(constraintLayout);
            constraintSet.connect(R.id.nicknameInput, ConstraintSet.END, R.id.nicknameUseButton2, ConstraintSet.START);
            constraintSet.applyTo(constraintLayout);
            showPasswordInput();
        } else {
            nickNameUseButton.setClickable(true);
            nickNameUseButton.setVisibility(View.VISIBLE);
            nicknameInput.setFocusable(true);
            nickNameUseButton2.setVisibility(View.GONE);
            nickNameUseButton2.setClickable(false);
            constraintSet.clone(constraintLayout);
            constraintSet.connect(R.id.nicknameInput, ConstraintSet.END, R.id.nicknameUseButton, ConstraintSet.START);
            constraintSet.applyTo(constraintLayout);
            hidePasswordInput();
            hidePasswordDuplicateInput();
        }
    }

    private void emailDuplicateCheck(boolean isExist) {
        if (!isExist) {
            emailDuplicationCheckButton.setClickable(false);
            emailInput.setClickable(false);
            emailCheckDoneButton.setVisibility(View.VISIBLE);
            emailCheckDoneButton.setClickable(true);
            emailDuplicationCheckButton.setVisibility(View.GONE);
            ConstraintLayout constraintLayout = findViewById(R.id.emailContentBox);
            ConstraintSet constraintSet = new ConstraintSet();
            constraintSet.clone(constraintLayout);
            constraintSet.connect(R.id.emailInput, ConstraintSet.END, R.id.emailDuplicationCheckButton2, ConstraintSet.START);
            constraintSet.applyTo(constraintLayout);
            Toast.makeText(this, "사용가능한 이메일입니다.", Toast.LENGTH_SHORT).show();
            showNickNameInput();
        } else {
            Toast.makeText(this, "존재하는 이메일입니다.", Toast.LENGTH_SHORT).show();
        }
    }

    private void emailResetting() {
        emailInput.setText("");
        emailInput.setClickable(true);
        emailCheckDoneButton.setVisibility(View.GONE);
        emailDuplicationCheckButton.setVisibility(View.VISIBLE);
        emailDuplicationCheckButton.setClickable(true);
        ConstraintLayout constraintLayout = findViewById(R.id.emailContentBox);
        ConstraintSet constraintSet = new ConstraintSet();
        constraintSet.clone(constraintLayout);
        constraintSet.connect(R.id.emailInput, ConstraintSet.END, R.id.emailDuplicationCheckButton, ConstraintSet.START);
        constraintSet.applyTo(constraintLayout);
        hideNickNameInput();
        hidePasswordInput();
        hidePasswordDuplicateInput();
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