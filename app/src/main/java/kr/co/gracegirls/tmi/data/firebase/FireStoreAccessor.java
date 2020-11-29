package kr.co.gracegirls.tmi.data.firebase;

import android.util.Log;

import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QueryDocumentSnapshot;

import java.util.ArrayList;
import java.util.Map;
import java.util.Objects;

import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;
import kr.co.gracegirls.tmi.view.home.MountainListListener;
import kr.co.gracegirls.tmi.view.shelter.ShelterListAdapter;
import kr.co.gracegirls.tmi.view.shelter.ShelterListListener;
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
                            mountainListItems.add(new MountainListItem(documentID, name, location, imgPath, height, riskPoint));
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
}