public class Frazione {
    public int numeratore;
    public int denominatore;
    
    public Frazione(int numeratore, int denominatore) throws ArithmeticException {
        if (denominatore == 0) {
            throw new ArithmeticException("Denominatore non puo' essere zero.");
        }
        else {
        this.numeratore = numeratore;
        this.denominatore = denominatore;
        }
    }

    public double toFloat() {
        return (double) numeratore / denominatore;
    }

    public static void main(String[] args) {
        Frazione f1 = null;
        try{
            f1 = new Frazione(15, 2);
        } catch(ArithmeticException e){
            System.out.println(e.getMessage());
        }
        if (f1 != null) {
        System.out.println("Frazione: " + f1.numeratore + "/" + f1.denominatore);
        }
    }
}

