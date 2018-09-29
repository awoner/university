package MVC.Model;

import java.util.ArrayList;
import java.util.List;

public class Model {
    private ArrayList<Abonent> model = new ArrayList<Abonent>();

    public Abonent addAbonent(String name, String surname, String patronymic, String adress, String telephone){
        Abonent abonent = new Abonent();
        abonent.setName(name);
        abonent.setSurname(surname);
        abonent.setPatronymic(patronymic);
        abonent.setAdress(adress);
        abonent.setTelephone(telephone);
        model.add(abonent);
        return abonent;
        //model.add(new Abonent(name, surname, patronymic, adress, telephone));
    }

    public static Model getInstance(){
        return new Model();
    }

    public List<Abonent> getModel() {
        return model;
    }
}
