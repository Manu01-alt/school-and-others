import java.time.LocalDate;

public class Rivista extends Pubblicazione {
    private boolean patinata;

    //costruttore
    public Rivista(String titolo, LocalDate dataPubblicazione, LocalDate dataRestituzione, boolean disponibile, String RecapitoLettore, int numPagine, boolean patinata) {
        super(titolo, dataPubblicazione, dataRestituzione, disponibile, RecapitoLettore, numPagine);
        this.patinata = patinata;
    }

    //getter e setter
    public boolean getPatinata() {
        return patinata;
    }

    public void setPatinata(boolean patinata) {
        this.patinata = patinata;
    }

    @Override
    public void setDataRestituzione() {
        this.dataRestituzione = LocalDate.now().plusDays(30);
    }

    //metodo
    public String toString() {
        return super.toString() + ", patinata=" + patinata;
    }

}
