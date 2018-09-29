package MVC.View;
import java.util.ResourceBundle;
import java.util.Locale;

public class View {
    static String MESSAGES_BUNDLE_NAME = "Messages";
    public static final ResourceBundle bundle =
            ResourceBundle.getBundle(
                    MESSAGES_BUNDLE_NAME,
                    //new Locale("ua", "UA"));  // Ukrainian
                    new Locale("en"));        // English

    public void printMsg(String message){
        System.out.print(message);
    }

    public void printlnMsg(String message){
        System.out.println(message);
    }

    public String concatenationString(String... messages){
        StringBuilder concatString = new StringBuilder();
        for(String msg : messages) {
            concatString = concatString.append(msg);
        }
        return new String(concatString);
    }
}
