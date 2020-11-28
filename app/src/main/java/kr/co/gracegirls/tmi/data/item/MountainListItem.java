package kr.co.gracegirls.tmi.data.item;

public class MountainListItem {

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

    public void setRiskPoint(String riskPoint) {
        this.riskPoint = riskPoint;
    }
}
