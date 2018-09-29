package model.entities;

public class Abonent {
    private String name;
    private String surname;
    private String patronymic;
    private String address;

    public Abonent(){}

    public Abonent(String name, String surname, String patronymic, String address){
        this.name = name;
        this.surname = surname;
        this.patronymic = patronymic;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public void setPatronymic(String patronymic) {
        this.patronymic = patronymic;
    }

    public String getAddress() {
        return address;
    }

    public void setAdress(String adress) {
        this.address = adress;
    }

    @Override
    public String toString() {
        return "Abonent{" +
                "name='" + name + '\'' +
                ", surname='" + surname + '\'' +
                ", patronymic='" + patronymic + '\'' +
                ", address='" + address + '\'' +
                '}';
    }
}
