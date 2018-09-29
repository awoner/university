package MVC.Controller;

import MVC.Model.Apartment;
import MVC.Model.Model;
import MVC.View.TextConstants;
import MVC.View.View;

import javax.lang.model.type.ErrorType;
import java.util.ResourceBundle;
import java.util.Scanner;

public class Controller {
    private Model model;
    private View view;

    public Controller(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    public void processUser() {
        try {
            Scanner scanner = new Scanner(System.in);
            menu(scanner);
        }catch (Exception ex){
            view.printErrorMsg(ex.getMessage());
        }
    }

    public void menu(Scanner scanner){
        Apartment apartment = new Apartment();
        boolean flg = false;
        do{
            view.printlnBundleMsg(TextConstants.MENU);
            view.printBundleMsg(TextConstants.MENU_INVITATION);
            switch (scanner.nextInt()){
                case 1:
                    view.printBundleMsg(TextConstants.INPUT_COUNT);
                    apartment.createApartment(scanner.nextInt());
                    flg = true;
                    break;
                case 2:
                    if(flg != false) {
                        apartment.turnOnSeveralAppliances();
                        view.printBundleMsg(TextConstants.OUTPUT_WORKING_APPS);
                        view.printlnMsg(apartment.getWorkingAppliances().toString());
                    }else{
                        view.printlnBundleMsg(TextConstants.WRONG_APARTMENT_INPUT);
                    }
                    break;
                case 3:
                    if(flg != false) {
                        apartment.calculatePowerConsumption();
                        view.printBundleMsg(TextConstants.OUTPUT_TOTAL_POWER);
                        view.printlnMsg(apartment.getPowerConsumption().toString() + " watt");
                    }else{
                        view.printlnBundleMsg(TextConstants.WRONG_APARTMENT_INPUT);
                    }
                    break;
                case 4:
                    if(flg != false) {
                        Integer a, b;
                        view.printBundleMsg(TextConstants.INPUT_FIRST_LIMIT);
                        a = scanner.nextInt();
                        view.printBundleMsg(TextConstants.INPUT_SECOND_LIMIT);
                        b = scanner.nextInt();
                        view.getInformation(apartment.findAppliances(a, b));
                    }else{
                        view.printlnBundleMsg(TextConstants.WRONG_APARTMENT_INPUT);
                    }
                    break;
                case 5:
                    if(flg != false) {
                        view.getInformation(apartment.getElectricalAppliances());
                    }else{
                        view.printlnBundleMsg(TextConstants.WRONG_APARTMENT_INPUT);
                    }
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    view.printlnBundleMsg(TextConstants.WRONG_MENU_INPUT);
                    break;
            }
        }
        while(true);
    }
}
