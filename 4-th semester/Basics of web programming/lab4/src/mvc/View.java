package mvc;


public class View {
    private final String WRONG_INPUT_DATA = "Wrong input! Repeat please!";
    public final String NAME_INVITATION = "Subscriber's name: ";
    public final String SURNAME_INVITATION = "Subscriber's surname: ";
    public final String PATRONYMIC_INVITATION = "Subscriber's patronymic: ";
    public final String NICKNAME_INVITATION = "Subscriber's nickname: ";
    public final String COMMENT_INVITATION = "Subscriber's comment: ";
    public final String GROUP_INVITATION = "Subscriber's group: ";
    public final String HOME_PHONE_INVITATION = "Subscriber's home phone: ";
    public final String FIRST_MOBILE_PHONE_INVITATION = "Subscriber's 1-st mobile phone: ";
    public final String SECOND_MOBILE_PHONE_INVITATION = "Subscriber's 2-nd mobile phone: ";
    public final String EMAIL_INVITATION = "Subscriber's e-mail: ";
    public final String SKYPE_INVITATION = "Subscriber's Skype: ";
    public final String ADDRESS_INDEX_INVITATION = "Subscriber's city index: ";
    public final String ADDRESS_CITY_INVITATION = "Subscriber's city: ";
    public final String ADDRESS_STREET_INVITATION = "Subscriber's street: ";
    public final String ADDRESS_HOUSE_INVITATION = "Subscriber's number of house: ";
    public final String ADDRESS_APATRTMENT_INVITATION = "Subscriber's number of apartment: ";
    public final String CREATE_DATE_INVITATION = "The date of create this note(Ex: 01.01.2018): ";
    public final String MODIFICATION_DATE_INVITATION = "The date of last modifying this note: ";
    public final String OUTPUT_SHORT_NAME = "Subscriber's name: ";
    public final String OUTPUT_FULL_ADDRESS = "Subscriber's adress: ";

    void printMsg(String msg) {
        System.out.println(msg);
    }

    private String concatenationString(String... message) {
        StringBuilder concatString = new StringBuilder();
        for (String v : message) {
            concatString = concatString.append(v);
        }
        return new String(concatString);
    }

    public void printErrorMsg(String errInv){
        System.out.print(WRONG_INPUT_DATA + " " + errInv);
    }

}
