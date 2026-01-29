import java.time.LocalDate;

public class Docente extends Dipendente {
    private int numero_ore_docenza;

    public Docente(String nominativo, String sesso, LocalDate data_di_nascita, int numero_ore_docenza, double stipendio_base_mensile) {
        super(nominativo, sesso, data_di_nascita, stipendio_base_mensile);
        this.numero_ore_docenza = numero_ore_docenza;
    }

    // Getters
    public int getNumero_ore_docenza() {
        return numero_ore_docenza;
    }

    // Setters
    public void setNumero_ore_docenza(int numero_ore_docenza) {
        this.numero_ore_docenza = numero_ore_docenza;
    }


    // Methods
    @Override
    /**
     * Rappresentazione testuale del docente
     * @return String rappresentazione testuale
     */
    public String toString() {
        return "Docente [nominativo=" + getNominativo() + ", sesso=" + getSesso() + ", data_di_nascita=" + getData_di_nascita()
                + ", numero_ore_docenza=" + numero_ore_docenza + ", stipendio_base_mensile=" + getStipendio_base_mensile()
                + "]";
    }

    @Override
    /**
     * Calcola lo stipendio annuale del docente
     * @return double stipendio annuale
     */
    public double calcolaStipendio() {
        return super.calcolaStipendio();
    }


}