public class Punto {
    private double x;
    private double y;

    //costruttore
    public Punto() {
        this.x = 0;
        this.y = 0;
    }

    public Punto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    //setter
    public void setX(double x) {
        this.x = x;
    }
    public void setY(double y) {
        this.y = y;
    }
    //getter
    /**
     * restituisce l'attributo X
     * @return (double) x
     */
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    //metodi
    public double distanza(Punto p2) {
        return Math.sqrt(Math.pow((this.x - p2.getX()), 2) + Math.pow((this.y - p2.getY()), 2));
    }

    public boolean equals(Punto p1, Punto p2) {
        if (p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
            return true;
        }
       return false;
    }

    public String ToString() {
        return ("(" + this.x + "," + this.y + ")");
    }

    
    public static void main(String[] args) {
        Punto p1 = new Punto(1,2);
        Punto p2 = new Punto();
        p1.setX(3);
        p1.setY(4);
        p2.setX(6);
        p2.setY(8);
        System.out.println("Distanza punto 1 da punto 2: " + p1.distanza(p2));
        System.out.println("I due punti sono uguali? " + p1.equals(p1, p2));
        System.out.println("Punto 1: " + p1.ToString());
        System.out.println("Punto 2: " + p1.ToString());
    }
        
}  