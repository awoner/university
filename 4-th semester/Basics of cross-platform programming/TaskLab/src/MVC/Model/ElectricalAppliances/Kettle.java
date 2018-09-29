package MVC.Model.ElectricalAppliances;

import java.util.Random;

public class Kettle extends ElectricalAppliances {
    @Override
    public void calculatePower() {
        Random random = new Random(700);
        this.setPower(random.nextInt(3000));
    }
}
