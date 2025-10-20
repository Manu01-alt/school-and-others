public class Raccoglitore {
    private int N;
    private Programma[] cartella;

    //costruttore
    public Raccoglitore(int N) {
        this.N = N;
        this.cartella = new Programma[N];
    }

    //getter
    public Programma getProgramma(int n) {
        if ((n < 0) || (n >= N)) {
            return null;
        }
        return cartella[n];
    }

    //setter
    public int setProgramma(Programma p, int n) {
        if ((n < 0) || (n >= N)) {
            return -1;
        }
        if (cartella[n] != null) {
            return -2;
        }
        cartella[n] = p;
        return 0;
    }

    //methods

    /**
     * Rimuove il programma in posizione n
     * @param n la posizione del programma da rimuovere
     */
    public void killProgramma(int n) {
        if ((n < 0) || (n >= N)) {
            return;
        }
        cartella[n] = null;
    }

    /**
     * Conta il numero di programmi presenti nel raccoglitore
     * @return il numero di programmi presenti
     */
    public int getN() {
        int c = 0;
        for (int i = 0; i < N; i++) {
            if (cartella[i] != null) {
                c++;
            }
        }
        return c;
    }

    /**
     * Cerca un programma per denominazione
     * @param denominazione 
     * @return la posizione del programma trovato, -1 se non trovato
     */
    public int cercaProgrammaPerDenominazione(String denominazione) {
        for (int i = 0; i < N; i++) {
            if (cartella[i] != null && cartella[i].getDenominazione().equals(denominazione)) {
                return i;
            }
        }
    return -1;
    }


    /***
     * Restituisce una rappresentazione testuale del raccoglitore
     * @return la stringa che rappresenta il raccoglitore
     */
    public String toString() {
        String result = "La cartella contiene:\n";
        for (int i = 0; i < N; i++) {
            if (cartella[i] != null) {
                result += "Posizione" + i + ": " + cartella[i].getDenominazione() + "\n"; 
            } else {
                result += "Posizione" + i + ": vuota\n";
            }
        }
        return result;
    }


       /***
        * Confronta il contenitore con un altro raccoglitore e conta i programmi in comune
        * @param c1 l'altro raccoglitore da confrontare
        * @return il numero di programmi in comune  
        */
        public int confrontaContenitore(Raccoglitore c1) {
        int c = 0;
        for (int i = 0; i < N; i++) {
            if (cartella[i] != null) {
                for (int j = 0; j < c1.N; j++) {
                    if (c1.getProgramma(j) != null) {
                        if (cartella[i].getDenominazione().equals(c1.getProgramma(j).getDenominazione())) 
                            c++;
                    }
                }    
            }
        }
        return c;   
    }

}
