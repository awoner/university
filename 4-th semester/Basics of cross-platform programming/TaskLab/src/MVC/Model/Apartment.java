package MVC.Model;

import MVC.Model.ElectricalAppliances.ElectricalAppliances;
import MVC.Model.Factory.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;

public class Apartment {
    private Random random = new Random();
    private ArrayList<ElectricalAppliances> electricalAppliances = new ArrayList<>();
    private Integer workingAppliances = 0;
    private Integer powerConsumption = 0;

    private static Comparator<ElectricalAppliances> PowerComparator = new Comparator<ElectricalAppliances>() {
        @Override
        public int compare(ElectricalAppliances e1, ElectricalAppliances e2) {
            return e1.getPower() - e2.getPower();
        }
    };

    public void createApartment(int countOfAppliances){
        for (int i = 0; i < countOfAppliances; i++) {
            ElectricalAppliancesCreater electricalAppliancesCreater = createAppliancesByName(
                    NamesOfAppliances.values()[random.nextInt(NamesOfAppliances.values().length)].getName()
            );
            if(electricalAppliancesCreater != null)
                electricalAppliances.add(electricalAppliancesCreater.create());
        }
    }

    private static ElectricalAppliancesCreater createAppliancesByName(String name) {
        switch (name) {
            case "Kettle":
                return new KettleCreater();
            case "Mixer":
                return new MixerCreater();
            case "PressureCooker":
                return new PressureCookerCreater();
            case "Toaster":
                return new ToasterCreater();
            case "CoffeeMachine":
                return new CoffeeMachineCreater();
            default:
                System.out.println("Error! Undefined appliance!");
        }
        return null;
    }

    public void turnOnSeveralAppliances() {
        Integer workingAppliances = random.nextInt(electricalAppliances.size());
        if(workingAppliances == 0){ workingAppliances += 1; }
        for (int i = 0; i < workingAppliances; i++) {
            electricalAppliances.get(random.nextInt(electricalAppliances.size())).on();
        }
        this.workingAppliances = workingAppliances - 1;
    }

    public void calculatePowerConsumption() {
        electricalAppliances.sort(PowerComparator);

        for (ElectricalAppliances ea : electricalAppliances) {
            if(ea.isOn()) {
                powerConsumption += ea.getPower();
            }
        }
    }

    public ArrayList<ElectricalAppliances> findAppliances(Integer firstLimit, Integer secondLimit){
        ArrayList<ElectricalAppliances> someAppliances = new ArrayList<>();
        for (ElectricalAppliances ea : electricalAppliances) {
            if(ea.getPower() >= firstLimit && ea.getPower() <= secondLimit){
                someAppliances.add(ea);
            }
        }
        return someAppliances;
    }

    public Integer getPowerConsumption() {
        return powerConsumption;
    }

    public Integer getWorkingAppliances() {
        return workingAppliances;
    }

    public ArrayList<ElectricalAppliances> getElectricalAppliances() {
        return electricalAppliances;
    }
}


