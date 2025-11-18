public class Abitazione {
    protected String città;
    protected String indirizzo;
    protected int numeroStanze;
    protected double superficie;
    
    //costruttore
    public Abitazione(String città, String indirizzo, int numeroStanze, double superficie) {
        this.città = città;
        this.indirizzo = indirizzo;
        this.numeroStanze = numeroStanze;
        this.superficie = superficie;
        
    }

    //getter
    public String getCittà() {
        return città;
    }
    public String getIndirizzo() {
        return indirizzo;
    }
    public int getnumeroStanze() {
        return numeroStanze;
    }
    public double getSuperficie() {
        return superficie;
    }   

    //setter
    public void setCittà(String città) {
        this.città = città;
    }
    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }
    public void setnumeroStanze(int numeroStanze) {
        this.numeroStanze = numeroStanze;
    }
    public void setSuperficie(double superficie) {
        this.superficie = superficie;
    }

    //metodi    
    public String toString() {
        return "Citta': " + città + ", Indirizzo: " + indirizzo + ", Numero Stanze: " + numeroStanze + ", Superficie: " + superficie + " mq";
    }

    public boolean equals(Abitazione A) {
        return this.città.equals(A.città) && this.indirizzo.equals(A.indirizzo) && this.numeroStanze == A.numeroStanze && this.superficie == A.superficie;
    }
}