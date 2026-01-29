import java.time.LocalDate;

public abstract class Impiegato extends Dipendente {
    protected String livello;

    public Impiegato(String nominativo, String sesso, LocalDate data_di_nascita, String livello, double stipendio_base_mensile) {
        super(nominativo, sesso, data_di_nascita, stipendio_base_mensile);
        this.livello = livello;
    }
    // Getters
    public String getLivello() {
        return livello;
    }

    // Setters
    public void setLivello(String livello) {
        this.livello = livello;
    }


    // Methods
    @Override
    /**
     * Rappresentazione testuale dell'impiegato
     * @return String rappresentazione testuale
     */
    public String toString() {
        return "Impiegato [nominativo=" + getNominativo() + ", sesso=" + getSesso() + ", data_di_nascita=" + getData_di_nascita()
                + ", livello=" + livello + ", stipendio_base=" + getStipendio_base_mensile() + "]";
    }
    
    @Override
    /**
     * Calcola lo stipendio annuale dell'impiegato
     * @return double stipendio annuale
     */
    public double calcolaStipendio() {
        return super.calcolaStipendio();
    }
}