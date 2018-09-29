package MVC.Controller;
import MVC.Model.*;
import MVC.View.*;

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
        setX(scanner);
        setA(scanner);
        setB(scanner);
        SecondOrderCurves parabola1 = new SecondOrderCurves(model.getCurve());
        parabola1.calculateY();
        view.printlnMsg("\nParabola1");
        view.printlnMsg("---------------");
        view.printMsg(parabola1.toString());
        view.printlnMsg("---------------\n");

        setY(scanner);
        setA(scanner);
        setB(scanner);
        SecondOrderCurves parabola2 = new SecondOrderCurves(model.getCurve());
        parabola2.calculateY();
        view.printlnMsg("\nParabola2");
        view.printlnMsg("---------------");
        view.printMsg(parabola1.toString());
        view.printlnMsg("---------------\n");
    }

    void setX(Scanner scanner){
        view.printMsg(TextConstants.INPUT_X_DATA);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(RegexContainer.REGEX_NUMS)){
            view.printMsg(TextConstants.WRONG_INPUT_DATA);
            inputStr = scanner.nextLine();
        }
        model.getTempParabola().setX(inputStr);
    }
    void setY(Scanner scanner){
        view.printMsg(TextConstants.INPUT_Y_DATA);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(RegexContainer.REGEX_NUMS)){
            view.printMsg(TextConstants.WRONG_INPUT_DATA);
            inputStr = scanner.nextLine();
        }
        model.getTempParabola().setY(inputStr);
    }
    void setA(Scanner scanner){
        view.printMsg(TextConstants.INPUT_A_DATA);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(RegexContainer.REGEX_NUMS)){
            view.printMsg(TextConstants.WRONG_INPUT_DATA);
            inputStr = scanner.nextLine();
        }
        model.getTempParabola().setA(inputStr);
    }
    void setB(Scanner scanner){
        view.printMsg(TextConstants.INPUT_B_DATA);
        String inputStr = scanner.nextLine();
        while (!inputStr.matches(RegexContainer.REGEX_NUMS)){
            view.printMsg(TextConstants.WRONG_INPUT_DATA);
            inputStr = scanner.nextLine();
        }
        model.getTempParabola().setB(inputStr);
    }

}
