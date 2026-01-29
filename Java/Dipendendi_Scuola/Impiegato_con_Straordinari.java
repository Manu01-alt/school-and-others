import java.time.LocalDate;
public class Impiegato_con_Straordinari extends Impiegato {
    private int numero_ore_straordinari_mensili;
    private final double retribuzione_oraria = 20.0;

    public Impiegato_con_Straordinari(String nominativo, String sesso, LocalDate data_di_nascita, String livello, double stipendio_base, int numero_ore_straordinari_mensili, double retribuzione_oraria) {
        super(nominativo, sesso, data_di_nascita, livello, stipendio_base);
        this.numero_ore_straordinari_mensili = numero_ore_straordinari_mensili;
    }

    // Getters
    public int getNumero_ore_straordinari_mensili() {
        return numero_ore_straordinari_mensili;
    }
    public double getRetribuzione_oraria() {
        return retribuzione_oraria;
    }

    // Setters
    public void setNumero_ore_straordinari_mensili(int numero_ore_straordinari_mensili) {
        this.numero_ore_straordinari_mensili = numero_ore_straordinari_mensili;
    }


    // Methods
    @Override
    /**
     * Rappresentazione testuale dell'impiegato con straordinari
     * @return String rappresentazione testuale
     */
    public String toString() {
        return super.toString() + "Straordinari [numero_ore_straordinari_mensili=" + numero_ore_straordinari_mensili + ", retribuzione_oraria=" + retribuzione_oraria + "]";
    }

    @Override
    /**
     * Calcola lo stipendio annuale dell'impiegato con straordinari
     * @return double stipendio annuale
     */
    public double calcolaStipendio() {
        return super.calcolaStipendio() + (numero_ore_straordinari_mensili * retribuzione_oraria * 12);
    }
}