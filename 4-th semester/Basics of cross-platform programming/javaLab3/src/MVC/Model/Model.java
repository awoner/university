package MVC.Model;

public class Model {
    private SecondOrderCurves curve;
    private SecondOrderCurves tempCurve;

    public Model(){
        curve = new SecondOrderCurves();
        tempCurve = new SecondOrderCurves();
    }

    public SecondOrderCurves getCurve(){
        return this.tempCurve;
    }

    public SecondOrderCurves getTempParabola() {
        return tempCurve;
    }
}
