import java.util.ArrayList;

public class Biblioteca {
    ArrayList<Pubblicazione> pubblicazioni;

    public Biblioteca() {
        this.pubblicazioni = new ArrayList<>();
    }

    /**
     * Aggiunge una pubblicazione alla biblioteca se non è già presente.
     * @param p La pubblicazione da aggiungere.
     */
    public void aggiungiPubblicazione(Pubblicazione p) {
        if (!pubblicazioni.contains(p))
            pubblicazioni.add(p);
    }

    /**
     * Rimuove una pubblicazione dalla biblioteca.
     * @param p La pubblicazione da rimuovere.
     */
    public void rimuoviPubblicazione(Pubblicazione p) {
        pubblicazioni.remove(p);
    }

    /**
     * Gestisce il prestito di una pubblicazione.
     * @param p La pubblicazione da prestare.
     * @param RecapitoLettore Il recapito del lettore che prende in prestito la pubblicazione.
     * @return Messaggio di conferma o errore.
     */
    public String Prestito(Pubblicazione p, String RecapitoLettore) {
        if (pubblicazioni.contains(p)) {
            p.setDisponibile(false);
            p.setDataRestituzione(null);
            p.setRecapitoLettore(RecapitoLettore);
            rimuoviPubblicazione(p);
            return "Prestito avvenuto con successo, recapito lettore: " + RecapitoLettore;
        }
        else {
            return "Errore nel prestito, la pubblicazione non è presente in biblioteca";
        }
    }

    /**
     * Gestisce la restituzione di una pubblicazione.
     * @param p La pubblicazione da restituire.
     * @return Messaggio di conferma con la data di restituzione.
     */
    public String Restituzione(Pubblicazione p) {
        p.setDisponibile(true);
        if (p instanceof Libro) {
            p.setDataRestituzione(((Libro) p).getDataPubblicazione().plusDays(60));
        } else if (p instanceof Rivista) {
            p.setDataRestituzione(((Rivista) p).getDataPubblicazione().plusDays(30));
        }
        p.setRecapitoLettore(null);
        aggiungiPubblicazione(p);
        return "Restituzione avvenuta con successo. Data di restituzione: " + p.getDataRestituzione();
    }
}
