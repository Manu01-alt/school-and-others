import java.util.ArrayList;
import java.util.Collections;

public class LibreriaMusicale {
    private String titolo;
    ArrayList<Brano> brani;
    private double durataMediaBrani;

    //costruttore
    public LibreriaMusicale(int dim, String titolo) {
        this.titolo = titolo;
        this.brani = new ArrayList<Brano>(dim);
    }


    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }


    /**
     * Aggiunge un brano alla libreria musicale.
     * @param brano
     * @return true se il brano è stato aggiunto con successo, false altrimenti.
     * @throws IllegalArgumentException
     */
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


    /**
     * Rimuove un brano dalla libreria musicale.
     * @param titolo
     * @param artista
     * @return true se il brano è stato rimosso con successo, false altrimenti.
     * @throws IllegalArgumentException
     */
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
        
        if (brani.isEmpty())
            return false;

        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            if (brano.getTitolo().equals(titolo) && brano.getArtista().equals(artista)) {
                brani.remove(i);
                return true;
            }
        }
        return false;
    }

    /**
     * Calcola i minuti totali ascoltati nella libreria musicale.
     * @return i minuti totali ascoltati, -1 se la libreria è vuota.
     */
    public int getMinutiAscoltati() {
        int MinutiTot = 0;
        
        if (brani.isEmpty())
            return -1;
        
        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            MinutiTot += brano.getDurataSec() * brano.getAscolti();
        }

        return MinutiTot / 60;

    }


    /**
     * Restituisce una lista di brani appartenenti a un genere specifico.
     * @param genere
     * @return una lista di brani del genere specificato.
     */
    public ArrayList<Brano> braniPerGenere(String genere) throws IllegalArgumentException {
        ArrayList<Brano> braniGenere = new ArrayList<Brano>();

        try {
            if (genere == null) {
                throw new IllegalArgumentException("Il genere non può essere nullo.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return braniGenere;
        }

        if (brani.isEmpty())
            return braniGenere;

        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            if (brano.getGenere().equals(genere)) 
                braniGenere.add(brano);
        }

        return braniGenere;
    }

    /**
     * Conta il numero di brani di un artista specifico.
     * @param artista
     * @return il numero di brani dell'artista specificato, -1 se la libreria è vuota.
     */
    public int contaBraniPerArtista(String artista) throws IllegalArgumentException {
        int numeroBrani = 0;

        try {
            if (artista == null) {
                throw new IllegalArgumentException("L'artista non può essere nullo.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return -1;
        }

<<<<<<< HEAD
        //Try catch per lista vuota
=======
        
>>>>>>> da20252502077e6d168cfd8333fad008d9eb3f21
        if (brani.isEmpty())
            return -1;

        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            if (brano.getArtista().equals(artista))
                numeroBrani++;
        }
        return numeroBrani;
    }

    /**
     * Restituisce il brano più ascoltato nella libreria musicale.
     * @return il brano più ascoltato, null se la libreria è vuota.
     */
    public Brano piuAscoltato() {
        Brano temp = null;
        Brano brano = null;
        int max_tempo = 0;

        if (brani.isEmpty())
            return brano;

        for (int i = 0; i < brani.size(); i++) {
            temp = brani.get(i);
            int tempo_ascoltato = temp.getDurataSec() * temp.getAscolti();
            
            if (tempo_ascoltato > max_tempo) {
                max_tempo = tempo_ascoltato;
                brano = temp;
            }
        }
        return brano;
    }

    /**
     * Restituisce una lista di brani mescolati casualmente di un genere specifico e con durata massima.
     * @param genere
     * @param durataMax
     * @return una lista di brani mescolati casualmente.
     */
    public ArrayList<Brano> shuffleConSeed(String genere, int durataMax) throws IllegalArgumentException {
        ArrayList<Brano> shuffled_list = new ArrayList<Brano>();
        int sommaDurata = 0;
        
        try {
            if (genere == null) {
                throw new IllegalArgumentException("Il genere non può essere nullo.");
            }
            if (durataMax <= 0) {
                throw new IllegalArgumentException("La durata massima deve essere maggiore di zero.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return shuffled_list;
        }

        if (brani.isEmpty())
            return shuffled_list;

        for(int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            if (brano.getGenere().equals(genere) && sommaDurata <= durataMax) {
                shuffled_list.add(brano);
                sommaDurata += brano.getDurataSec();
            }
        }
        
        Collections.shuffle(shuffled_list);
        return shuffled_list;

    }

    /**
     * Calcola la durata media dei brani nella libreria musicale.
     * @return la durata media dei brani.
     */
    public double calcolaDurataMediaBrani() {
        double durataTot = 0.0;

        if (brani.isEmpty())
            return durataTot;

        for (int i = 0; i < brani.size(); i++) {
            Brano brano = brani.get(i);
            durataTot += brano.getDurataSec();
        }

        durataMediaBrani = durataTot / brani.size();
        return durataMediaBrani;
    }

}