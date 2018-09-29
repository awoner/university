package mvc;
import java.util.Scanner;

public class Controler {
    private Model model;
    private View view;
    public Controler(Model model, View view)
    {
        this.model = model;
        this.view = view;
    }

    public void procesUser()
    {
        Scanner sc = new Scanner(System.in);
        String name = input(sc,Regex.name, view.NAME_INVITATION);
        String surname = input(sc, Regex.surName, view.SURNAME_INVITATION);
        String patronimic = input(sc, Regex.patronimic, view.PATRONYMIC_INVITATION);
        String nickname = input(sc, Regex.userName,view.NICKNAME_INVITATION);
        String comment = input(sc, Regex.comment, view.COMMENT_INVITATION);
        String groups = input(sc, Regex.groups, view.GROUP_INVITATION);
        String email = input(sc, Regex.emeil, view.EMAIL_INVITATION);
        String skype = input(sc, Regex.skype, view.SKYPE_INVITATION);
        String index = input(sc, Regex.index, view.ADDRESS_INDEX_INVITATION);
        String city = input(sc, Regex.city, view.ADDRESS_CITY_INVITATION);
        String street = input(sc, Regex.street, view.ADDRESS_STREET_INVITATION);
        String homeNumber = input(sc, Regex.setHomeNumber, view.ADDRESS_HOUSE_INVITATION);
        String roomNumber = input(sc, Regex.roomNumber, view.ADDRESS_APATRTMENT_INVITATION);
        String mobile_number1 = input(sc, Regex.phoneNumber, view.FIRST_MOBILE_PHONE_INVITATION);
        String mobile_number2 = input(sc, Regex.phoneNumber + "|(\\s+)",view.SECOND_MOBILE_PHONE_INVITATION);


    }

    public String input(Scanner scanner, String regex,String msg){
        view.printMsg(msg);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(regex)){
            view.printErrorMsg(msg);
            inputStr = scanner.nextLine();
        }
        return inputStr;
    }
}
