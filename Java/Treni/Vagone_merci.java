public class Vagone_merci extends Vagone {
    private double volume_carico;
    private double peso_massimo_carico;
    private double peso_effettivo_carico;

    public Vagone_merci(int codice, double peso_a_vuoto, String azienda_costruttrice, int anno_costruzione, double volume_carico, double peso_massimo_carico, double peso_effettivo_carico) {
        super(codice, peso_a_vuoto, azienda_costruttrice, anno_costruzione);
        this.volume_carico = volume_carico;
        this.peso_massimo_carico = peso_massimo_carico;
        this.peso_effettivo_carico = peso_effettivo_carico;
    }

    //getter
    public double getVolume_carico() {
        return volume_carico;
    }
    public double getPeso_massimo_carico() {
        return peso_massimo_carico;
    }
    public double getPeso_effettivo_carico() {
        return peso_effettivo_carico;
    }

    //setter
    public void setVolume_carico(double volume_carico) {
        this.volume_carico = volume_carico;
    }
    public void setPeso_massimo_carico(double peso_massimo_carico) {
        this.peso_massimo_carico = peso_massimo_carico;
    }
    public void setPeso_effettivo_carico(double peso_effettivo_carico) {
        this.peso_effettivo_carico = peso_effettivo_carico;
    }

    public String toString() {
        return super.toString() +
                ", volume_carico=" + volume_carico +
                ", peso_massimo_carico=" + peso_massimo_carico +
                ", peso_effettivo_carico=" + peso_effettivo_carico +
                '}';
    }
}