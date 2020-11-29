package kr.co.gracegirls.tmi.view.signup;

import kr.co.gracegirls.tmi.data.metadata.SignUpMetaData;

public interface SignUpListener {

    void checkEmailDuplicate(boolean isExist);

    boolean checkSignUpIsSuccessful(SignUpMetaData data);
}
