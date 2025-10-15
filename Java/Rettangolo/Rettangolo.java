public class Rettangolo {
    private double base;
    private double altezza;
    private Punto centro;

    //costruttore
    public Rettangolo(double base, double altezza, Punto centro) {
        this.base = base;
        this.altezza = altezza;
        this.centro = centro;
    }

    //setter
    public void setBase(double base) {
        this.base = base;
    }
    public void setAltezza(double altezza) {
        this.altezza = altezza;
    }
    public void setCentro(Punto centro) {
        this.centro = centro;
    }
    //getter
    public double getBase() {
        return base;
    }
    public double getAltezza() {
        return altezza;
    }
    public Punto getCentro() {
        return centro;
    }

    //metodi
    /**
     * Calcola e restituisce il vertice A del rettangolo
     * @return (double) vertice A
     */
    public Punto VerticeA() {

        return new Punto(centro.getX() - (this.base / 2), centro.getY() + (this.altezza / 2));
    }

    /**
     * Calcola e restituisce il vertice B del rettangolo
     * @return (double) vertice B
     */
    public Punto VerticeB() {

        return new Punto(centro.getX() + (this.base / 2), centro.getY() + (this.altezza / 2));
    }

    /**
     * Calcola e restituisce il vertice C del rettangolo
     * @return (double) vertice C
     */
    public Punto VerticeC() {

        return new Punto(centro.getX() - (this.base / 2), centro.getY() - (this.altezza / 2));
    }

    /**
     * Calcola e restituisce il vertice D del rettangolo
     * @return (double) vertice D
     */
    public Punto VerticeD() {

        return new Punto(centro.getX() + (this.base / 2), centro.getY() - (this.altezza / 2));
    }
    
    /**
     * Controlla se il punto P appartiene al rettangolo
     * @param P (Punto) punto da controllare
     * @return (boolean) true se il punto appartiene al rettangolo, false se non appartiene al rettangolo
     */
    public boolean Appartiene(Punto P) {
        if (P.getX() >= this.VerticeC().getX() && P.getX() <= this.VerticeD().getX() && P.getY() >= this.VerticeC().getY() && P.getY() <= this.VerticeA().getY())
            return true;
        return false;
    }

    /**
     * Calcola e restituisce il vertice del rettangolo piu' vicino all'origine degli assi
     * @return (Punto) vertice piu' vicino all'origine degli assi
     */
    public Punto VerticeVicinoOrigine() {

        if (this.VerticeA().distanza(new Punto(0.0,0.0)) <= this.VerticeB().distanza(new Punto(0.0,0.0)) && this.VerticeA().distanza(new Punto(0.0,0.0)) <= this.VerticeC().distanza(new Punto(0.0,0.0)) && this.VerticeA().distanza(new Punto(0.0,0.0)) <= this.VerticeD().distanza(new Punto(0.0,0.0)))
            return this.VerticeA();
        else if (this.VerticeB().distanza(new Punto(0.0,0.0)) <= this.VerticeA().distanza(new Punto(0.0,0.0)) && this.VerticeB().distanza(new Punto(0.0,0.0)) <= this.VerticeC().distanza(new Punto(0.0,0.0)) && this.VerticeB().distanza(new Punto(0.0,0.0)) <= this.VerticeD().distanza(new Punto(0.0,0.0)))
            return this.VerticeB();
        else if (this.VerticeC().distanza(new Punto(0.0,0.0)) <= this.VerticeA().distanza(new Punto(0.0,0.0)) && this.VerticeC().distanza(new Punto(0.0,0.0)) <= this.VerticeB().distanza(new Punto(0.0,0.0)) && this.VerticeC().distanza(new Punto(0.0,0.0)) <= this.VerticeD().distanza(new Punto(0.0,0.0)))
            return this.VerticeC();
        else 
            return this.VerticeD(); 
    }
    
    public static void main(String[] args) {
        Rettangolo R1 = new Rettangolo (10, 5, new Punto(5, 2));
        System.out.println("Vertice A: " + R1.VerticeA().ToString());
        System.out.println("Vertice B: " + R1.VerticeB().ToString());
        System.out.println("Vertice C: " + R1.VerticeC().ToString());
        System.out.println("Vertice D: " + R1.VerticeD().ToString());

        Punto P1 = new Punto(6, 3);
        if (R1.Appartiene(P1))
            System.out.println("Il punto " + P1.ToString() + " appartiene al rettangolo R1");
        else
            System.out.println("Il punto " + P1.ToString() + " non appartiene al rettangolo R1");


        System.out.println("Il vertice del rettangolo R1 piu' vicino all'origine e': " + R1.VerticeVicinoOrigine().ToString());
    }
}