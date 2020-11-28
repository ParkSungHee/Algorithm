package kr.co.gracegirls.tmi.data.firebase;

import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.QueryDocumentSnapshot;

import kr.co.gracegirls.tmi.view.signup.SignUpListener;

public class FireStoreAccessor {

    private FirebaseFirestore db = FirebaseFirestore.getInstance();

    public void checkEmailDuplicate(String email, SignUpListener signUpListener) {
        db.collection(FirebaseConfig.USER)
                .get()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        for (QueryDocumentSnapshot data : task.getResult()) {
                            String checkEmail = (String) data.get(FirebaseConfig.EMAIL);
                            if (email.equals(checkEmail)) {
                                signUpListener.checkEmailDuplicate(true);
                                return;
                            }
                        }
                        signUpListener.checkEmailDuplicate(false);
                    }
                });
    }
}