package MVC.Model.Factory;

import MVC.Model.ElectricalAppliances.CoffeeMachine;
import MVC.Model.ElectricalAppliances.ElectricalAppliances;

public class CoffeeMachineCreater  implements ElectricalAppliancesCreater {
    public ElectricalAppliances create(){
        return new CoffeeMachine();
    }
}