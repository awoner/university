package MVC.Model.Factory;

import MVC.Model.ElectricalAppliances.ElectricalAppliances;
import MVC.Model.ElectricalAppliances.Toaster;

public class ToasterCreater implements ElectricalAppliancesCreater {
    public ElectricalAppliances create(){
        return new Toaster();
    }
}