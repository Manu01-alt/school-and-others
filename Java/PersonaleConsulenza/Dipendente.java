public abstract class Dipendente {
    protected String codice;
    protected String cognome;
    protected String nome;
    protected int annoAssunzione;

    public Dipendente(String nome, String cognome, String codice, int annoAssunzione) {
        this.codice = codice;
        this.cognome = cognome;
        this.nome = nome;
        this.annoAssunzione = annoAssunzione;
    }

    //Getter
    public String getCodice() {
        return codice;
    }
    public String getCognome() {
        return cognome;
    }
    public String getNome() {
        return nome;
    }
    public int getAnnoAssunzione() {
        return annoAssunzione;
    }

    //setter
    public void setCodice(String codice) {
        this.codice = codice;
    }
    public void setCognome(String cognome) {
        this.cognome = cognome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setAnnoAssunzione(int annoAssunzione) {
        this.annoAssunzione = annoAssunzione;
    }

    //Metodo
    public abstract double calcolaStipendio(int ore);

}