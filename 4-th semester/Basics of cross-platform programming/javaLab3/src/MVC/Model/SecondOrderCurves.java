package MVC.Model;
import MVC.View.*;

import java.util.Objects;

public class SecondOrderCurves implements Cloneable{
    private double x;
    private double y;
    private double a;
    private double b;

    public SecondOrderCurves(){
        x = 0;
        y = 0;
        a = 0;
        b = 0;
    }

    public SecondOrderCurves(SecondOrderCurves secondOrderCurves){
        this.x = secondOrderCurves.x;
        this.y = secondOrderCurves.y;
        this.a = secondOrderCurves.a;
        this.b = secondOrderCurves.b;
    }

    public double getX(){ return this.x; }
    public double getY(){ return this.y; }
    public double getA(){ return this.a; }
    public double getB(){ return this.b; }

    public void setX(String str) { this.x = Double.parseDouble(str); }
    public void setY(String str) { this.y = Double.parseDouble(str); }
    public void setA(String str) { this.a = Double.parseDouble(str); }
    public void setB(String str) { this.b = Double.parseDouble(str); }

    public void calculateX(){
        x = Math.sqrt(Math.abs((1.0 + (Math.pow(y, 2.0) / Math.pow(b, 2.0))) / Math.pow(a, 2.0)));
    }
    public void calculateY(){
        y = Math.sqrt(Math.abs((1.0 + (Math.pow(x, 2.0) / Math.pow(a, 2.0))) / Math.pow(b, 2.0)));
    }

    @Override
    public String toString(){
        View view = new View();
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append(TextConstants.OUTPUT_X_DATA).append(x).append("\n")
                .append(TextConstants.OUTPUT_Y_DATA).append(y).append("\n")
                .append(TextConstants.OUTPUT_A_DATA).append(a).append("\n")
                .append(TextConstants.OUTPUT_B_DATA).append(b).append("\n");
        return stringBuffer.toString();
    }

    @Override
    public boolean equals(Object obj){
        if(obj instanceof SecondOrderCurves){
            return ((SecondOrderCurves) obj).getA() == this.a &&
                    ((SecondOrderCurves) obj).getB() == this.b &&
                    ((SecondOrderCurves) obj).getX() == this.x &&
                    ((SecondOrderCurves) obj).getY() == this.y;
        }
        else return false;
    }

    @Override
    public int hashCode() {
        return ((((int)x) * 37 + (int)y) * 37 + (int)a) * 37 + (int)b;
    }

    @Override
    public Object clone(){
        try{
            return super.clone();
        }catch(CloneNotSupportedException e){
            throw new AssertionError("Error! " + e.getMessage());
        }
    }
}
