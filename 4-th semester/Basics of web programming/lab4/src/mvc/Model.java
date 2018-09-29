package mvc;

import java.util.Date;

public class Model {
    private String name;
    private String surname;
    private String patronimic;
    private String nsp;
    private String nickname;
    private String comment;
    private String groups;
    private String email;
    private String skype;
    private String address;
    private String mobile_number1;
    private String mobile_number2;
    private Date set_date;
    private Date change_date;
    public Model(){}
    private Model(String name, String surname, String patronimic,
                  String nickname, String comment, String groups,
                  String email, String skype, String index, String city,
                  String street, String home_number, String room_number,
                  String mobile_number1, String mobile_number2, Date set_date) {
        this.name = name;
        this.surname = surname;
        this.patronimic = patronimic;
        this.nsp = surname + " " + name.charAt(0) + ".";
        this.nickname = nickname;
        this.comment = comment;
        this.groups = groups;
        this.email = email;
        this.skype = skype;
        this.address = String.join(",", index, city, street, home_number, room_number);
        this.mobile_number1 = mobile_number1;
        this.mobile_number2 = mobile_number2;
        this.set_date = set_date;
        this.change_date = set_date;
    }

    static Model create(String name, String surname, String patronimic,
                        String nickname, String comment, String groups,
                        String email, String skype, String index, String city,
                        String street, String home_number, String room_number,
                        String mobile_number1, String mobile_number2, Date set_date) {

        return new Model(name, surname, patronimic, nickname,
                        comment, groups, email, skype, index,
                        city, street, home_number, room_number,
                        mobile_number1, mobile_number2, set_date);
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getPatronimic() {
        return patronimic;
    }

    public String getNsp() {
        return nsp;
    }

    public String getNickname() {
        return nickname;
    }

    public String getComment() {
        return comment;
    }

    public String getGroups() {
        return groups;
    }

    public String getEmail() {
        return email;
    }

    public String getSkype() {
        return skype;
    }

    public String getAddress() {
        return address;
    }


    public String getMobile_number1() {
        return mobile_number1;
    }

    public String getMobile_number2() {
        return mobile_number2;
    }

    public Date getSet_date() {
        return set_date;
    }

    public Date getChange_date() {
        return change_date;
    }
}
