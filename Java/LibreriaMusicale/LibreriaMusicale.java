import java.util.ArrayList;

public class LibreriaMusicale {
    private String titolo;
    ArrayList<Brano> brani;

    //costruttore
    public LibreriaMusicale(int dim, String titolo) {
        this.titolo = titolo;
        this.brani = new ArrayList<Brano>(dim);
    }


    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }


    public boolean aggiungiBrano(Brano brano) throws IllegalArgumentException {
        //Try catch per argomenti nulli o duplicati
        try {
            if (brano == null) {
                throw new IllegalArgumentException("Il brano non può essere nullo.");
            }
            if (brani.contains(brano)) {
                throw new IllegalArgumentException("Il brano è già presente nella libreria.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return false;
        }

        brani.add(brano);
        return true;
    }



    public boolean rimuoviBrano(String titolo, String artista) throws IllegalArgumentException {
        //Try catch per argomenti nulli
        try {
            if (titolo == null) {
                throw new IllegalArgumentException("Il titolo non può essere nullo.");
            }
            if (artista == null) {
                throw new IllegalArgumentException("L'artista non può essere nullo.");
            }
        }
        catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return false;
        }
        

        //Try catch per lista vuota
        try {
            if (brani.isEmpty()) {
                throw new EmptyListExcepion("La libreria è vuota.");
            }
        } catch (EmptyListExcepion e) {
            System.out.println(e.getMessage());
            return false;
        }

        //Try catch per brano non trovato
        try {
        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            if (brano.getTitolo().equals(titolo) && brano.getArtista().equals(artista)) {
                brani.remove(i);
                return true;
            }
        }
        throw new ElementNotFoundException("Il brano non è stato trovato nella libreria.");
        }
        catch (ElementNotFoundException e) {
            System.out.println(e.getMessage());
            return false;
        }
    
    }

    



}
