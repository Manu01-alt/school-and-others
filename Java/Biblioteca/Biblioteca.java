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
    //farla senza uso di instance of
    public String Prestito(Pubblicazione p, String RecapitoLettore) {
        if (p.isDisponibile()) {
            p.setDisponibile(false);
            p.setRecapitoLettore(RecapitoLettore);
            p.setDataRestituzione();
            return "Prestito avvenuto con successo, la pubblicazione sarò disponibile a partire dal " + p.getDataRestituzione();
       }
       else {
           return "Errore: la pubblicazione non è disponibile per il prestito.";
       }
    }

    /**
     * Gestisce la restituzione di una pubblicazione.
     * @param p La pubblicazione da restituire.
     * @return Messaggio di conferma con la data di restituzione.
     */
    public String Restituzione(Pubblicazione p) {
        p.setDisponibile(true);
        p.setRecapitoLettore("");
        p.setDataRestituzione();
        return "Restituzione avvenuta con successo in data " + p.getDataRestituzione();
    }
}
