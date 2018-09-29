package MVC.View;

import java.util.Locale;
import java.util.ResourceBundle;

public interface TextConstants {
    static String MESSAGES_BUNDLE_NAME = "Messages";
    public static final ResourceBundle bundle =
            ResourceBundle.getBundle(
                    MESSAGES_BUNDLE_NAME,
                    new Locale("ua", "UA"));  // Ukrainian
                    //new Locale("en"));        // English
    public static final String INPUT_X_DATA = bundle.getString("input.x.data");
    public static final String INPUT_Y_DATA = bundle.getString("input.y.data");
    public static final String INPUT_A_DATA = bundle.getString("input.a.data");
    public static final String INPUT_B_DATA = bundle.getString("input.b.data");
    public static final String OUTPUT_X_DATA = "x: ";
    public static final String OUTPUT_Y_DATA = "y: ";
    public static final String OUTPUT_A_DATA = "a: ";
    public static final String OUTPUT_B_DATA = "b: ";
    public static final String WRONG_INPUT_DATA = bundle.getString("input.wrong.data");
}
