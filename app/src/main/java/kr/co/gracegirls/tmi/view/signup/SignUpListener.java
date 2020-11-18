package kr.co.gracegirls.tmi.view.signup;

import kr.co.gracegirls.tmi.data.metadata.SignUpMetaData;

public interface SignUpListener {

    boolean checkEmailDuplicate(String email);

    boolean checkSignUpIsSuccessful(SignUpMetaData data);
}
