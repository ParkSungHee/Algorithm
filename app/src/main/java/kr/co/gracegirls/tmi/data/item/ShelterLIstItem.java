package kr.co.gracegirls.tmi.data.item;

public class ShelterLIstItem {

    private String title;
    private String location;
    private String al;
    private String tmp;

    public ShelterLIstItem(String title, String location, String al, String tmp) {
        this.title = title;
        this.location = location;
        this.al = al;
        this.tmp = tmp;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getAl() {
        return al;
    }

    public void setAl(String al) {
        this.al = al;
    }

    public String getTmp() {
        return tmp;
    }

    public void setTmp(String tmp) {
        this.tmp = tmp;
    }

    @Override
    public String toString() {
        return "ShelterLIstItem{" +
                "title='" + title + '\'' +
                ", location='" + location + '\'' +
                ", al='" + al + '\'' +
                ", tmp='" + tmp + '\'' +
                '}';
    }
}
