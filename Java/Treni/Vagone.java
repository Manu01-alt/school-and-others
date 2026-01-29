public abstract class Vagone {
    protected int codice;
    protected double peso_a_vuoto;
    protected String azienda_costruttrice;
    protected int anno_costruzione;

    public Vagone(int codice, double peso_a_vuoto, String azienda_costruttrice, int anno_costruzione) {
        this.codice = codice;
        this.peso_a_vuoto = peso_a_vuoto;
        this.azienda_costruttrice = azienda_costruttrice;
        this.anno_costruzione = anno_costruzione;
    }

    //getter 
    public int getCodice() {
        return codice;
    }
    public double getPeso_a_vuoto() {
        return peso_a_vuoto;
    }
    public String getAzienda_costruttrice() {
        return azienda_costruttrice;
    }
    public int getAnno_costruzione() {
        return anno_costruzione;
    }
 

    //setter
    public void setCodice(int codice) {
        this.codice = codice;
    }
    public void setPeso_a_vuoto(double peso_a_vuoto) {
        this.peso_a_vuoto = peso_a_vuoto;
    }
    public void setAzienda_costruttrice(String azienda_costruttrice) {
        this.azienda_costruttrice = azienda_costruttrice;
    }
    public void setAnno_costruzione(int anno_costruzione) {
        this.anno_costruzione = anno_costruzione;
    }

    public String toString() {
        return "Vagone{" +
                "codice=" + codice +
                ", peso_a_vuoto=" + peso_a_vuoto +
                ", azienda_costruttrice='" + azienda_costruttrice + '\'' +
                ", anno_costruzione=" + anno_costruzione +
                '}';
    }
}
