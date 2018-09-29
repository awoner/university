package mvc.Controller;
import mvc.Model.*;
import mvc.View.View;

import java.util.Scanner;

public class Controller {
    private Model model;
    private View view;

    public Controller(Model model, View view){
        this.model = model;
        this.view = view;
    }

    public void processUser(){
        Scanner scanner = new Scanner(System.in);
        Scanner scanner1 = new Scanner(System.in);
        do {
            view.printMsg("1.Add new note\n");
            view.printMsg("2.Print all notes\n");
            view.printMsg("3.Exit\n");
            view.printMsg("Please enter your choice: ");
            int a = scanner1.nextInt();
            switch (a) {
                case 1:
                    setName(scanner);
                    setSurname(scanner);
                    setPatronymic(scanner);
                    setNickname(scanner);
                    setComment(scanner);
                    setGroup(scanner);
                    setHomePhone(scanner);
                    setFirstMobilePhone(scanner);
                    setSecondMobilePhone(scanner);
                    setEmail(scanner);
                    setSkype(scanner);
                    setAddressIndex(scanner);
                    setAddressCity(scanner);
                    setAddressStreet(scanner);
                    setAddressHouseNumber(scanner);
                    setAddressApartmentNumber(scanner);
                    setCreatingDate(scanner);
                    setModificationDate(scanner);

                    model.setNote();

                    break;
                case 2:
                    if(model.getAllNotes() != null) {
                        for (Note n : model.getAllNotes()) {
                            view.printMsg(n.toString());
                        }
                    }else{
                        view.printMsg("No notes yet!\n");
                    }
                    break;
                case 3:
                    return;
                default:
                    view.printMsg("Wrong choice!");
                    break;
            }
        }while (true);
    }

    public void setName(Scanner scanner){
        view.printMsg(view.NAME_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})")){
            view.printErrorMsg(view.NAME_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setSubName(inputStr);
    }

    public void setSurname(Scanner scanner){
        view.printMsg(view.SURNAME_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?)|([А-Я][а-я]{1,20}([-][А-Я][а-я]{1,20})?)")){
            view.printErrorMsg(view.SURNAME_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setSubSurname(inputStr);
    }

    public void setPatronymic(Scanner scanner){
        view.printMsg(view.SURNAME_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([A-Z][a-z]{1,20})|([А-Я][а-я]{1,20})")){
            view.printErrorMsg(view.PATRONYMIC_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setSubPatronymic(inputStr);
        model.getTempNote().setSubShortName(view);
    }

    public void setNickname(Scanner scanner){
        view.printMsg(view.NICKNAME_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\w]+")){
            view.printErrorMsg(view.NICKNAME_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setNickname(inputStr);
    }

    public void setComment(Scanner scanner){
        view.printMsg(view.COMMENT_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(".+")){
            view.printErrorMsg(view.COMMENT_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setComment(inputStr);
    }

    public void setGroup(Scanner scanner){
        view.printMsg(view.GROUP_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([\\w^[0-9]])+|([А-Яа-я_])+")){
            view.printErrorMsg(view.GROUP_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setGroup(inputStr.toUpperCase());
    }

    public void setHomePhone(Scanner scanner){
        view.printMsg(view.HOME_PHONE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[1-9]{3}[\\-]?[\\d]{2}[\\-]?[\\d]{2}")){
            view.printErrorMsg(view.HOME_PHONE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setHomePhone(inputStr);
    }

    public void setFirstMobilePhone(Scanner scanner){
        view.printMsg(view.FIRST_MOBILE_PHONE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([\\+]?38)?(([\\(]0[1-9]{2}[\\)])|(0[1-9]{2}))[\\d]{7}")){
            view.printErrorMsg(view.FIRST_MOBILE_PHONE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setFirstMobilePhone(inputStr);
    }

    public void setSecondMobilePhone(Scanner scanner){
        view.printMsg(view.SECOND_MOBILE_PHONE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("(([\\+]?38)?(([\\(]0[1-9]{2}[\\)])|(0[1-9]{2}))[\\d]{7})?")){
            view.printErrorMsg(view.SECOND_MOBILE_PHONE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setSecondMobilePhone(inputStr);
    }

    public void setEmail(Scanner scanner){
        view.printMsg(view.EMAIL_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\w]{1,20}[\\@][A-Za-z]{1,20}[\\.][a-z]{3}")){
            view.printErrorMsg(view.EMAIL_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setEmail(inputStr);
    }

    public void setSkype(Scanner scanner){
        view.printMsg(view.SKYPE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\w\\-]+")){
            view.printErrorMsg(view.SKYPE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setSkype(inputStr);
    }

    public void setAddressIndex(Scanner scanner){
        view.printMsg(view.ADDRESS_INDEX_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\d]{5}")){
            view.printErrorMsg(view.ADDRESS_INDEX_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setAddressIndex(inputStr);
    }

    public void setAddressCity(Scanner scanner){
        view.printMsg(view.ADDRESS_CITY_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("([A-Z][a-z]{1,20}([-][A-Z][a-z]{1,20})?)|([А-Я][а-я]{1,20}([-][А-Я][а-я]{1,20})?)")){
            view.printErrorMsg(view.ADDRESS_CITY_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setAddressCity(inputStr);
    }

    public void setAddressStreet(Scanner scanner){
        view.printMsg(view.ADDRESS_STREET_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("(([A-Za-z]{2,3}\\.)?[\\s]?[A-Z][a-z]+)|((ул\\.)?[\\s]?[А-Я][а-я]+)")){
            view.printErrorMsg(view.ADDRESS_STREET_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setAddressStreet(inputStr);
    }

    public void setAddressHouseNumber(Scanner scanner){
        view.printMsg(view.ADDRESS_HOUSE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\d]+")){
            view.printErrorMsg(view.ADDRESS_HOUSE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setAddressHouseNumber(inputStr);
    }

    public void setAddressApartmentNumber(Scanner scanner){
        view.printMsg(view.ADDRESS_APATRTMENT_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("[\\d]+")){
            view.printErrorMsg(view.ADDRESS_APATRTMENT_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setAddressApartmentNumber(inputStr);
        model.getTempNote().setFullAddress(view);
    }

    public void setCreatingDate(Scanner scanner){
        view.printMsg(view.CREATE_DATE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("((0[1-9])|([12][0-9])|(3[01]))(\\.)((0[1-9])|(1[012]))(\\.)((19|20)[\\d][\\d])")){
            view.printErrorMsg(view.CREATE_DATE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setCreatingDate(inputStr);
    }

    public void setModificationDate(Scanner scanner){
        view.printMsg(view.MODIFICATION_DATE_INVITATION);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches("((0[1-9])|([12][0-9])|(3[01]))(\\.)((0[1-9])|(1[012]))(\\.)((19|20)[\\d][\\d])")){
            view.printErrorMsg(view.MODIFICATION_DATE_INVITATION);
            inputStr = scanner.nextLine();
        }
        model.getTempNote().setModificationDate(inputStr);
    }
}
