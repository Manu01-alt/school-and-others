import java.time.LocalDate;

public class Pubblicazione {
    protected final int id;
    protected String titolo;
    protected LocalDate dataPubblicazione;
    protected int numPagine;
    protected boolean prestito;
    protected LocalDate dataPrestito=null;
    protected String recapitoLettore;
    protected static int num=0;
    
    public Pubblicazione(String titolo, LocalDate dataPubblicazione, int numPagine) {
        this.titolo = titolo;
        this.dataPubblicazione = dataPubblicazione;
        this.numPagine = numPagine;
        num++;
        this.prestito=false;
        this.id=num;
    }

    public LocalDate getDataPrestito() {
        return dataPrestito;
    }

    public void setDataPrestito() {
        this.dataPrestito = null;
    }

    public String getRecapitoLettore() {
        return recapitoLettore;
    }

    public void setRecapitoLettore(String recapitoLettore) {
        this.recapitoLettore = recapitoLettore;
    }

    public int getId() {
        return id;
    }

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

    @Override
    public String toString() {
        return "Pubblicazione id=" + id + ", titolo=" + titolo + ", dataPubblicazione=" + dataPubblicazione
                + ", numPagine=" + numPagine;
    }

    
    
}
