import mvc.Controller.Controller;
import mvc.Model.Model;
import mvc.View.View;


public class Main {
    static public void main(String []args){
        Model model =  new Model();
        View view = new View();
        Controller controller = new Controller(model, view);
        controller.processUser();
    }
}
