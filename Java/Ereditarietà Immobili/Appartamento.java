public class Appartamento extends Abitazione {
    protected int piano;
    protected int numeroTerrazzi;
    protected boolean ascensore;

    //costruttore
    public Appartamento(String città, String indirizzo, int numeroStanze, double superficie, int piano, int numeroTerrazzi, boolean ascensore) {
        super(città, indirizzo, numeroStanze, superficie);
        this.piano = piano;
        this.numeroTerrazzi = numeroTerrazzi;
        this.ascensore = ascensore;
    }

    //getter
    public int getPiano() {
        return piano;
    }
    public int getNumeroTerrazzi() {
        return numeroTerrazzi;
    }   
    public boolean hasAscensore() {
        return ascensore;
    }

    //setter
    public void setPiano(int piano) {
        this.piano = piano;
    }
    public void setNumeroTerrazzi(int numeroTerrazzi) {
        this.numeroTerrazzi = numeroTerrazzi;
    }
    public void setAscensore(boolean ascensore) {
        this.ascensore = ascensore;
    }

    //metodi
    public String toString() {
        return super.toString() + "Piano: " + piano + ", Numero Terrazzi: " + numeroTerrazzi + ", Ascensore: " + ascensore;
    }

    public boolean equals(Appartamento A) {
        return super.equals(A) && this.piano == A.piano && this.numeroTerrazzi == A.numeroTerrazzi && this.ascensore == A.ascensore;
    }
}