package MVC.Model.ElectricalAppliances;

import java.util.Random;

public class CoffeeMachine extends ElectricalAppliances{
    @Override
    public void calculatePower() {
        Random random = new Random(500);
        this.setPower(random.nextInt(1000));
    }
}
