package MVC.Model.ElectricalAppliances;

import java.util.Random;

public class Mixer extends ElectricalAppliances {
    @Override
    public void calculatePower() {
        Random random = new Random(140);
        this.setPower(random.nextInt(270));
    }
}
