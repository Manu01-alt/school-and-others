public class Vagone_passeggeri extends Vagone {
    private String classe;
    private int num_posti_disponibili;
    private int num_posti_occupati;

    public Vagone_passeggeri(int codice, double peso_a_vuoto, String azienda_costruttrice, int anno_costruzione, String classe, int num_posti_disponibili, int num_posti_occupati) {
        super(codice, peso_a_vuoto, azienda_costruttrice, anno_costruzione);
        this.classe = classe;
        this.num_posti_disponibili = num_posti_disponibili;
        this.num_posti_occupati = num_posti_occupati;
    }

    //getter
    public String getClasse() {
        return classe;
    }
    public int getNum_posti_disponibili() {
        return num_posti_disponibili;
    }
    public int getNum_posti_occupati() {
        return num_posti_occupati;
    }

    //setter
    public void setClasse(String classe) {
        this.classe = classe;
    }
    public void setNum_posti_disponibili(int num_posti_disponibili) {
        this.num_posti_disponibili = num_posti_disponibili;
    }
    public void setNum_posti_occupati(int num_posti_occupati) {
        this.num_posti_occupati = num_posti_occupati;
    }

    //metodo per calcolare il peso totale del vagone
    public double calcolaPesoTotale() {
        double peso_totale = this.peso_a_vuoto + (this.num_posti_occupati * 65);
        return peso_totale;
    }

    public String toString() {
        return super.toString() +
                ", classe='" + classe + '\'' +
                ", num_posti_disponibili=" + num_posti_disponibili +
                ", num_posti_occupati=" + num_posti_occupati +
                '}';
    }
}