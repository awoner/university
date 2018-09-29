package MVC.Model;

public enum NamesOfAppliances {
    KETTLE("Kettle"), MIXER("Mixer"), PRESSURECOOKER("PressureCooker"),
    TOASTER("Toaster"), COFFEEMACHINE("CoffeeMachine");

    private String name;

    NamesOfAppliances(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }

    @Override
    public String toString() {
        return "PreciousStoneNames{" +
                "name='" + name + '\'' +
                '}';
    }
}