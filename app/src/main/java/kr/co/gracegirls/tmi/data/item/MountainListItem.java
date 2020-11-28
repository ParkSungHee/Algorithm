package kr.co.gracegirls.tmi.data.item;

import android.os.Parcel;
import android.os.Parcelable;

public class MountainListItem implements Parcelable {

    private String documentID;
    private String name;
    private String location;
    private String imgPath;
    private String height;
    private String riskPoint;

    public MountainListItem(String documentID, String name, String location, String imgPath, String height, String riskPoint) {
        this.documentID = documentID;
        this.name = name;
        this.location = location;
        this.imgPath = imgPath;
        this.height = height;
        this.riskPoint = riskPoint;
    }

    protected MountainListItem(Parcel in) {
        documentID = in.readString();
        name = in.readString();
        location = in.readString();
        imgPath = in.readString();
        height = in.readString();
        riskPoint = in.readString();
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(documentID);
        dest.writeString(name);
        dest.writeString(location);
        dest.writeString(imgPath);
        dest.writeString(height);
        dest.writeString(riskPoint);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<MountainListItem> CREATOR = new Creator<MountainListItem>() {
        @Override
        public MountainListItem createFromParcel(Parcel in) {
            return new MountainListItem(in);
        }

        @Override
        public MountainListItem[] newArray(int size) {
            return new MountainListItem[size];
        }
    };

    public String getDocumentID() {
        return documentID;
    }

    public void setDocumentID(String documentID) {
        this.documentID = documentID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getImgPath() {
        return imgPath;
    }

    public void setImgPath(String imgPath) {
        this.imgPath = imgPath;
    }

    public String getHeight() {
        return height;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String getRiskPoint() {
        return riskPoint;
    }
}
