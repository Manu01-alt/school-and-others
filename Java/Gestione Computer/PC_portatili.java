public class PC_portatili extends PC {
    protected double peso;
    protected double altezza;
    protected double larghezza;
    protected double profondita;
    protected double dimensioneVideo; //in pollici
    protected boolean interfacciaReteWireless;

    //constructor
    public PC_portatili(String processore, int memoria_ram, int memoria_massa, String marca, String modello, String sistemaOperativo, double peso, double altezza, double larghezza, double profondita, double dimensioneVideo, boolean interfacciaReteWireless) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo);
        this.peso = peso;
        this.altezza = altezza;
        this.larghezza = larghezza;
        this.profondita = profondita;
        this.dimensioneVideo = dimensioneVideo;
        this.interfacciaReteWireless = interfacciaReteWireless;
    }

    //Getter
    public double getPeso() {
        return peso;
    }
    public double getAltezza() {
        return altezza;
    }
    public double getLarghezza() {
        return larghezza;
    }
    public double getProfondita() {
        return profondita;
    }
    public double getDimensioneVideo() {
        return dimensioneVideo;
    }
    public boolean isInterfacciaReteWireless() {
        return interfacciaReteWireless;
    }

    //Setter
    public void setPeso(double peso) {
        this.peso = peso;
    }
    public void setAltezza(double altezza) {
        this.altezza = altezza;
    }
    public void setLarghezza(double larghezza) {
        this.larghezza = larghezza;
    }
    public void setProfondita(double profondita) {
        this.profondita = profondita;
    }
    public void setDimensioneVideo(double dimensioneVideo) {
        this.dimensioneVideo = dimensioneVideo;
    }
    public void setInterfacciaReteWireless(boolean interfacciaReteWireless) {
        this.interfacciaReteWireless = interfacciaReteWireless;
    }

    //Method
    public String toString() {
        return "PC_portatili: " + super.toString() + ", peso=" + peso + ", altezza=" + altezza + ", larghezza=" + larghezza
                + ", profondita=" + profondita + ", dimensioneVideo=" + dimensioneVideo
                + ", interfacciaReteWireless=" + interfacciaReteWireless;
    }

    public boolean equals(PC_portatili other) {
        return super.equals(other) &&
               this.peso == other.peso &&
               this.altezza == other.altezza &&
               this.larghezza == other.larghezza &&
               this.profondita == other.profondita &&
               this.dimensioneVideo == other.dimensioneVideo &&
               this.interfacciaReteWireless == other.interfacciaReteWireless;
    }
}
