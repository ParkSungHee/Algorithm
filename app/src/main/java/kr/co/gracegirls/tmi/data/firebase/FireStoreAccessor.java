package kr.co.gracegirls.tmi.data.firebase;

import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.QueryDocumentSnapshot;

public class FireStoreAccessor {

    private FirebaseFirestore db = FirebaseFirestore.getInstance();
    private boolean emailCheckFlag = true;

    public boolean isEmailDuplicate(String email) {
        db.collection(FirebaseConfig.USER)
                .get()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        for (QueryDocumentSnapshot data : task.getResult()) {
                            String checkEmail = (String) data.get(FirebaseConfig.EMAIL);
                            if (email.equals(checkEmail)) {
                                emailCheckFlag = false;
                                break;
                            }
                        }
                    }
                });
        return emailCheckFlag;
    }
}
