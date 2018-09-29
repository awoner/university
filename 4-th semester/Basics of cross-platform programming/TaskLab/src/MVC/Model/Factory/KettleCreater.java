package MVC.Model.Factory;

import MVC.Model.ElectricalAppliances.ElectricalAppliances;
import MVC.Model.ElectricalAppliances.Kettle;

public class KettleCreater implements ElectricalAppliancesCreater {
    public ElectricalAppliances create(){
        return new Kettle();
    }
}