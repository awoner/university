package MVC.Model.Factory;

import MVC.Model.ElectricalAppliances.ElectricalAppliances;
import MVC.Model.ElectricalAppliances.Mixer;

public class MixerCreater implements ElectricalAppliancesCreater {
    public ElectricalAppliances create(){
        return new Mixer();
    }
}
