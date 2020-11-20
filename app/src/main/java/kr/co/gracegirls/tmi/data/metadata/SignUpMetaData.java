package kr.co.gracegirls.tmi.data.metadata;

public class SignUpMetaData {
    private String email;
    private String nickname;
    private String UID;


    public SignUpMetaData(String email, String nickname, String UID) {
        this.email = email;
        this.nickname = nickname;
        this.UID = UID;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getNickname() {
        return nickname;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public String getUID() {
        return UID;
    }

    public void setUID(String UID) {
        this.UID = UID;
    }

    @Override
    public String toString() {
        return "SignUpMetaData{" +
                "email='" + email + '\'' +
                ", nickname='" + nickname + '\'' +
                ", UID='" + UID + '\'' +
                '}';
    }
}
