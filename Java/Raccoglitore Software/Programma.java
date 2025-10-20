public class Programma {
    String denominazione;
    String produttore;
    int versione;
    String sistemaOperativo;
    int anno;
    
    //costruttore
    public Programma(String denominazione, String produttore, int versione, String sistemaOperativo, int anno) {
        this.denominazione = denominazione;
        this.produttore = produttore;
        this.versione = versione;
        this.sistemaOperativo = sistemaOperativo;
        this.anno = anno;
    }

    //getter
    public String getDenominazione() {
        return denominazione;
    }

    public String getProduttore() {
        return produttore;
    }

    public int getVersione() {
        return versione;
    }

    public String getSistemaOperativo() {
        return sistemaOperativo;
    }

    public int getAnno() {
        return anno;
    }

    //setter
    public void setDenominazione(String denominazione) {
        this.denominazione = denominazione;
    }

    public void setProduttore(String produttore) {
        this.produttore = produttore;
    }

    public void setVersione(int versione) {
        this.versione = versione;
    }

    public void setSistemaOperativo(String sistemaOperativo) {
        this.sistemaOperativo = sistemaOperativo;
    }

    public void setAnno(int anno) {
        this.anno = anno;
    }

    //methods

    /***
     * Rappresentazione testuale del programma
     * @return la stringa rappresentante il programma
     */
    public String toString() {
        return "Denominazione: " + denominazione + ", Produttore: " + produttore + ", Versione: " + versione + ", Sistema Operativo: " + sistemaOperativo + ", Anno: " + anno;
    }

}
