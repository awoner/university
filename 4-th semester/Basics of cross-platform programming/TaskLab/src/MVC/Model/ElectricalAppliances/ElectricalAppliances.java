package MVC.Model.ElectricalAppliances;

public abstract class ElectricalAppliances {
    private Integer power = 0;
    private boolean isOn = false;
    private String name = getClass().getSimpleName();

    protected void setPower(Integer power) {
        this.power = power;
    }

    ElectricalAppliances(){
        calculatePower();
    }

    public boolean isOn() {
        return isOn;
    }

    public void on() {
        isOn = true;
    }

    public void off() {
        isOn = false;
    }

    public Integer getPower() {
        return power;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name
               + "\t[Power: " + power + "]"
               + "\t[Status: " + ((isOn) ? "on" : "off") +"]";
    }

    protected abstract void calculatePower();
}
