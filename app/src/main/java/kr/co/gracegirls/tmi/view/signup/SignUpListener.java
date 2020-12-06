package kr.co.gracegirls.tmi.view.signup;

public interface SignUpListener {

    void checkEmailDuplicate(boolean isExist);

    void checkSignUpIsSuccessful(boolean isSuccessful);
}
