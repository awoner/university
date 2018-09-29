package MVC.Model.ElectricalAppliances;

import java.util.Random;

public class PressureCooker extends ElectricalAppliances{
    @Override
    public void calculatePower() {
        Random random = new Random(1000);
        this.setPower(random.nextInt(2000));
    }
}
