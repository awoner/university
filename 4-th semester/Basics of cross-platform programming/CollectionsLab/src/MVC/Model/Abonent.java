package MVC.Model;

import java.util.Objects;

public class Abonent {
    private String name;
    private String surname;
    private String patronymic;
    private String adress;
    private String telephone;

    Abonent(){}

    Abonent(String name, String surname, String patronymic, String adress, String telephone){
        this.name = name;
        this.surname = surname;
        this.patronymic = patronymic;
        this.adress = adress;
        this.telephone = telephone;
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

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public String getTelephone() {
        return telephone;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Abonent abonent = (Abonent) o;
        return Objects.equals(name, abonent.name) &&
                Objects.equals(surname, abonent.surname) &&
                Objects.equals(patronymic, abonent.patronymic) &&
                Objects.equals(adress, abonent.adress) &&
                Objects.equals(telephone, abonent.telephone);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, surname, patronymic, adress, telephone);
    }

    @Override
    public String toString() {
        return "Abonent{" +
                "name='" + name + '\'' +
                ", surname='" + surname + '\'' +
                ", patronymic='" + patronymic + '\'' +
                ", adress='" + adress + '\'' +
                ", telephone='" + telephone + '\'' +
                '}';
    }
}