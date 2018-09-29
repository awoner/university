package MVC.View;

import MVC.Model.Apartment;
import MVC.Model.ElectricalAppliances.ElectricalAppliances;

import java.util.ArrayList;
import java.util.Locale;
import java.util.ResourceBundle;

public class View {
    private ResourceBundle bundle =  ResourceBundle.getBundle(
    TextConstants.MESSAGES_BUNDLE_NAME,
            //new Locale("en"));
            new Locale("ua"));

    public void printErrorMsg(String errstr){
        System.out.println("ERROR!!!" + errstr);
    }

    public void printlnBundleMsg(String message){
        System.out.println(bundle.getString(message));
    }

    public void printBundleMsg(String message){
        System.out.print(bundle.getString(message));
    }

    public void printlnMsg(String message){
        System.out.println(message);
    }

    public void printMsg(String message){
        System.out.print(message);
    }


    public String concatenationString(String... messages) {
        StringBuilder concatString = new StringBuilder();
        for (String msg : messages) {
            concatString = concatString.append(msg);
        }
        return new String(concatString);
    }

    public void getInformation(ArrayList<ElectricalAppliances> arrlst){
        for (ElectricalAppliances electricalAppliances
                : arrlst) {
           printlnMsg(electricalAppliances.toString());
        }
    }
}
