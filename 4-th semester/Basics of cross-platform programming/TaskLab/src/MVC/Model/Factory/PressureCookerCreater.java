package MVC.Model.Factory;

import MVC.Model.ElectricalAppliances.ElectricalAppliances;
import MVC.Model.ElectricalAppliances.PressureCooker;

public class PressureCookerCreater  implements ElectricalAppliancesCreater {
    public ElectricalAppliances create(){
        return new PressureCooker();
    }
}