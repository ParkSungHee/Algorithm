package kr.co.gracegirls.tmi.data.item;

public class MountainListItem {

    private String title;
    private int riskPoint;
    private String location;

    public MountainListItem(String name, int riskPoint, String location) {
        this.title = name;
        this.riskPoint = riskPoint;
        this.location = location;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public int getRiskPoint() {
        return riskPoint;
    }

    public void setRiskPoint(int riskPoint) {
        this.riskPoint = riskPoint;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    @Override
    public String toString() {
        return "MountainListItem{" +
                "name='" + title + '\'' +
                ", riskPoint=" + riskPoint +
                ", address='" + location + '\'' +
                '}';
    }
}
