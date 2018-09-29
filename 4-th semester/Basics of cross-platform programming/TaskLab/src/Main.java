import MVC.Model.*;
import MVC.View.*;
import MVC.Controller.*;

public class Main {
    static public void main(String[] args) {
        Model model =  new Model();
        View view = new View();
        Controller controller = new Controller(model, view);
        controller.processUser();
    }
}