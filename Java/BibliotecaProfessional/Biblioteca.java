import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Pubblicazione> biblioteca;

    public Biblioteca() {
        this.biblioteca = new ArrayList<>();
    }

    
    public void aggiungiPubblicazione(Pubblicazione p) {
        biblioteca.add(p);
    }

    public boolean rimuoviPubblicazione(String titolo) {
        Pubblicazione pub = null;
        for(Pubblicazione p : biblioteca) {
            if(p.getTitolo().equalsIgnoreCase(titolo))
                pub=p;
        }
        return biblioteca.remove(pub);
    }
   
    public String inPrestito(String titolo,String lettore) {
        Pubblicazione pub=null;
        for(Pubblicazione p : biblioteca) {
            if(p.getTitolo().equalsIgnoreCase(titolo))
                pub=p;
        }   
        if(pub == null)
            return "libro non presente all'interno della biblioteca";
        else if(pub.getDataPrestito() == null) {
            pub.setRecapitoLettore(lettore);
            if(pub instanceof Libro){
                pub.setDataPrestito();
                return "libro preso in prestito restituirlo il "+pub.getDataPrestito();
            }
            else{
                pub.setDataPrestito();
                return "rivista presa in prestito, restituirla il "+pub.getDataPrestito();
            }
        }
        return " la pubblicazione tornerà disponibile il "+pub.getDataPrestito().plusDays(1);
    }


    public void restituzionePrestito(String titolo) {
        Pubblicazione pub = null;
        for(Pubblicazione p : biblioteca) {
            if(p.getTitolo().equalsIgnoreCase(titolo))
                pub=p;
        }
        pub.setDataPrestito();
    }


    @Override
    public String toString() {
        return "Biblioteca [biblioteca=" + biblioteca + "]";
    }
    
    }
