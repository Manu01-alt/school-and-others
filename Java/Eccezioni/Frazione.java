public class Frazione {
    public int numeratore;
    public int denominatore;

public Frazione(int numeratore, int denominatore) throws ArithmeticException {
    //Uncheked: programmatore non obbligato all'uso del try catch
    //Checked: programmatore obbligato all'uso del try catch
    if(denominatore == 0) {
        throw new ArithmeticException("il denominatore non puo'  essere 0");
    } else {
        this.numeratore=numeratore;
        this.denominatore=denominatore;
    }
}

    public double toFloat()  {
    return numeratore/denominatore;
}


    public static void main(String[] args) {
        Frazione f1 = null;
        
            f1 = new Frazione(15,0);
            System.out.println(f1.numeratore);
            System.out.println(f1.denominatore);
        
        }

    }
