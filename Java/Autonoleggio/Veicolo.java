public abstract class Veicolo {
    protected String targa;
    protected int numero_di_matricola;
    protected String marca;
    protected String modello;
    protected double cilindrata;
    protected int anno_di_acquisto;
    protected double capacita_serbatoio; // in litri

    //costruttore
    public Veicolo(String targa, int numero_di_matricola, String marca, String modello, double cilindrata, int anno_di_acquisto, double capacita_serbatoio) {
        this.targa = targa;
        this.numero_di_matricola = numero_di_matricola;
        this.marca = marca;
        this.modello = modello;
        this.cilindrata = cilindrata;
        this.anno_di_acquisto = anno_di_acquisto;
        this.capacita_serbatoio = capacita_serbatoio;
    }

    //getter e setter
    public String getTarga() {
        return targa;
    }
    public void setTarga(String targa) {
        this.targa = targa;
    }

    public int getNumero_di_matricola() {
        return numero_di_matricola;
    }
    public void setNumero_di_matricola(int numero_di_matricola) {
        this.numero_di_matricola = numero_di_matricola;
    }

    public String getMarca() {
        return marca;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModello() {
        return modello;
    }
    public void setModello(String modello) {
        this.modello = modello;
    }

    public double getCilindrata() {
        return cilindrata;
    }
    public void setCilindrata(double cilindrata) {
        this.cilindrata = cilindrata;
    }
    
    public int getAnno_di_acquisto() {
        return anno_di_acquisto;
    }
    public void setAnno_di_acquisto(int anno_di_acquisto) {
        this.anno_di_acquisto = anno_di_acquisto;
    }

    public double getCapacita_serbatoio() {
        return capacita_serbatoio;
    }
    public void setCapacita_serbatoio(double capacita_serbatoio)
    {
        this.capacita_serbatoio = capacita_serbatoio;
    }

    //metodo 
    
    public abstract double calcolaConsumo(double kmPercorsi, double carburanteUsato, int giorni);

    public String toString() {
        return "Veicolo: targa=" + targa + ", numero_di_matricola=" + numero_di_matricola + ", marca=" + marca
                + ", modello=" + modello + ", cilindrata=" + cilindrata + ", anno_di_acquisto=" + anno_di_acquisto
                + ", capacita_serbatoio=" + capacita_serbatoio;
    }
}