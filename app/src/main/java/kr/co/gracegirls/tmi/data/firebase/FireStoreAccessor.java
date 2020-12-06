package kr.co.gracegirls.tmi.data.firebase;

import android.util.Log;

import androidx.annotation.NonNull;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QueryDocumentSnapshot;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;
import kr.co.gracegirls.tmi.data.metadata.SignUpMetaData;
import kr.co.gracegirls.tmi.view.home.MountainListListener;
import kr.co.gracegirls.tmi.view.login.LoginActionListener;
import kr.co.gracegirls.tmi.view.shelter.ShelterListAdapter;
import kr.co.gracegirls.tmi.view.shelter.ShelterListListener;
import kr.co.gracegirls.tmi.view.signup.SignUpListener;

public class FireStoreAccessor {

    private FirebaseFirestore db = FirebaseFirestore.getInstance();
    private FirebaseAuth firebaseAuth = FirebaseAuth.getInstance();

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

    public void getMountainInformation(MountainListListener mountainListListener) {
        db.collection(FirebaseConfig.MOUNTAIN)
                .orderBy(FirebaseConfig.RISK_POINT, Query.Direction.ASCENDING)
                .get()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        ArrayList<MountainListItem> mountainListItems = new ArrayList<>();
                        for (DocumentSnapshot snap : Objects.requireNonNull(task.getResult())) {
                            Map<String, Object> shot = snap.getData();
                            String documentID = String.valueOf(snap.getId());
                            String name = String.valueOf(shot.get(FirebaseConfig.NAME));
                            String location = String.valueOf(shot.get(FirebaseConfig.LOCATION));
                            String imgPath = String.valueOf(shot.get(FirebaseConfig.IMG_PATH));
                            String riskPoint = String.valueOf(shot.get(FirebaseConfig.RISK_POINT));
                            String height = String.valueOf(shot.get(FirebaseConfig.HEIGHT));
                            String description =String.valueOf(shot.get(FirebaseConfig.DESCRIPTION));
                            mountainListItems.add(new MountainListItem(documentID, name, location, imgPath, height, riskPoint, description));
                        }
                        mountainListListener.setMountainList(mountainListItems);
                    }
                });
    }

    public void getShelterList(ShelterListListener shelterListListener) {
        db.collection(FirebaseConfig.SHELTER)
                .get()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        ArrayList<ShelterListItem> shelterListItems = new ArrayList<>();
                        for (DocumentSnapshot snap : Objects.requireNonNull(task.getResult())) {
                            Map<String, Object> shot = snap.getData();
                            String name = String.valueOf(shot.get(FirebaseConfig.NAME));
                            String address = String.valueOf(shot.get(FirebaseConfig.ADDRESS));
                            String height = String.valueOf(shot.get(FirebaseConfig.HEIGHT));
                            String people = String.valueOf(shot.get(FirebaseConfig.PEOPLE));
                            String latitude = String.valueOf(shot.get(FirebaseConfig.LATITUDE));
                            String longitude = String.valueOf(shot.get(FirebaseConfig.LONGITUDE));
                            shelterListItems.add(new ShelterListItem(name, address, latitude, longitude, height, people));
                        }
                        shelterListListener.setShelterList(shelterListItems);
                    }
                });
    }


    public void getMountainShelterList(MountainListListener mountainListListener, String mountainId) {
        db.collection(FirebaseConfig.SHELTER)
                .get()
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        ArrayList<ShelterListItem> shelterListItems = new ArrayList<>();
                        for (DocumentSnapshot snap : Objects.requireNonNull(task.getResult())) {
                            Map<String, Object> shot = snap.getData();
                            if (mountainId.equals(String.valueOf(shot.get(FirebaseConfig.MOUNTAIN_ID)))) {
                                String name = String.valueOf(shot.get(FirebaseConfig.NAME));
                                String address = String.valueOf(shot.get(FirebaseConfig.ADDRESS));
                                String height = String.valueOf(shot.get(FirebaseConfig.HEIGHT));
                                String people = String.valueOf(shot.get(FirebaseConfig.PEOPLE));
                                String latitude = String.valueOf(shot.get(FirebaseConfig.LATITUDE));
                                String longitude = String.valueOf(shot.get(FirebaseConfig.LONGITUDE));
                                shelterListItems.add(new ShelterListItem(name, address, latitude, longitude, height, people));
                            }
                        }
                        mountainListListener.setShelterList(shelterListItems);
                    }
                });
    }

    public void registerNewUserInAuth(SignUpListener signUpListener, SignUpMetaData data) {
        data.setPassword(data.getPassword() + "11");
        firebaseAuth.createUserWithEmailAndPassword(data.getEmail(), data.getPassword()).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    FirebaseUser user = firebaseAuth.getCurrentUser();
                    data.setUID(user.getUid());
                    HashMap<String, Object> inputData = new HashMap<>();
                    inputData.put(FirebaseConfig.EMAIL, data.getEmail());
                    inputData.put(FirebaseConfig.NICKNAME, data.getNickname());
                    inputData.put(FirebaseConfig.UID, data.getUID());
                    inputData.put(FirebaseConfig.PASSWORD, data.getPassword());

                    db.collection(FirebaseConfig.USER).document(data.getUID()).set(inputData).addOnCompleteListener(new OnCompleteListener<Void>() {
                        @Override
                        public void onComplete(@NonNull Task<Void> task) {
                            if (task.isSuccessful()) {
                                signUpListener.checkSignUpIsSuccessful(true);
                            } else {
                                signUpListener.checkSignUpIsSuccessful(false);
                            }
                        }
                    }).addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            signUpListener.checkSignUpIsSuccessful(false);
                            Log.e("Error", "Register Failed : ", e);
                        }
                    });
                }
            }
        }).addOnFailureListener(new OnFailureListener() {
            @Override
            public void onFailure(@NonNull Exception e) {
                Log.d("Error", "SignUp Failed: ", e);
                signUpListener.checkSignUpIsSuccessful(false);
            }
        });
    }

    public void loginUser(String email, String password, LoginActionListener loginActionListener) {
        firebaseAuth.signInWithEmailAndPassword(email, password).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    loginActionListener.login(true);
                } else {
                    loginActionListener.login(false);
                }
            }
        }).addOnFailureListener(new OnFailureListener() {
            @Override
            public void onFailure(@NonNull Exception e) {
                loginActionListener.login(false);
                Log.e("Error", "Sign In Failed : ", e);
            }
        });
    }
}