import java.time.LocalDate;

public class Pubblicazione {
    protected static int num = 0;
    protected String titolo;
    protected LocalDate dataPubblicazione;
    protected LocalDate dataRestituzione;
    protected int numPagine;
    protected String RecapitoLettore;
    protected boolean disponibile;
    protected Utente utente;
    
    //costruttore
    public Pubblicazione(String titolo, LocalDate dataPubblicazione, LocalDate dataRestituzione, boolean disponibile, String RecapitoLettore, int numPagine) {
        this.titolo = titolo;
        this.dataPubblicazione = dataPubblicazione;
        this.dataRestituzione = dataRestituzione;
        this.disponibile = disponibile;
        this.RecapitoLettore = RecapitoLettore;
        this.numPagine = numPagine;
        num++;
    }

    //getter e setter
    public String getTitolo() {
        return titolo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public LocalDate getDataPubblicazione() {
        return dataPubblicazione;
    }

    public void setDataPubblicazione(LocalDate dataPubblicazione) {
        this.dataPubblicazione = dataPubblicazione;
    }

    public int getNumPagine() {
        return numPagine;
    }

    public void setNumPagine(int numPagine) {
        this.numPagine = numPagine;
    }

    public boolean isDisponibile() {
        return disponibile;
    }

    public void setDisponibile(boolean disponibile) {
        this.disponibile = disponibile;
    }

    public LocalDate getDataRestituzione() {
        return dataRestituzione;
    }

    public void setDataRestituzione() {
        this.dataRestituzione = null;
    }

    public String getRecapitoLettore() {
        return RecapitoLettore;
    }

    public void setRecapitoLettore(String recapitoLettore) {
        RecapitoLettore = recapitoLettore;
    }


    //metodo

    public void presta(Utente utente) {
        if (this.disponibile) {
            this.disponibile = false;
            this.utente = utente;
            utente.getPubblicazioni_in_prestito().add(this);
        }
    }



    public String toString() {
        return " titolo=" + titolo + ", dataPubblicazione=" + dataPubblicazione + ", numPagine=" + numPagine + ", dataRestituzione=" + dataRestituzione + ", disponibile=" + disponibile + ", RecapitoLettore=" + RecapitoLettore;
    }

}