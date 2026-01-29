public abstract class Dipendente {
    protected String nominativo;
    protected String sesso;
    protected java.time.LocalDate data_di_nascita;
    protected double stipendio_base_mensile;

    public Dipendente(String nominativo, String sesso, java.time.LocalDate data_di_nascita, double stipendio_base_mensile) {
        this.nominativo = nominativo;
        this.sesso = sesso;
        this.data_di_nascita = data_di_nascita;
        this.stipendio_base_mensile = stipendio_base_mensile;
    }
    // Getters
    public String getNominativo() {
        return nominativo;
    }
    public String getSesso() {
        return sesso;
    }
    public java.time.LocalDate getData_di_nascita() {
        return data_di_nascita;
    }
    public double getStipendio_base_mensile() {
        return stipendio_base_mensile;
    }

    // Setters
    public void setNominativo(String nominativo) {
        this.nominativo = nominativo;
    }
    public void setSesso(String sesso) {
        this.sesso = sesso;
    }
    public void setData_di_nascita(java.time.LocalDate data_di_nascita) {
        this.data_di_nascita = data_di_nascita;
    }
    public void setStipendio_base_mensile(double stipendio_base_mensile) {
        this.stipendio_base_mensile = stipendio_base_mensile;
    }

    // Method
    public abstract String toString();

    /**
     * Calcola lo stipendio annuale del dipendente
     * @return double stipendio annuale
     */
    public double calcolaStipendio() {
        return stipendio_base_mensile * 12;
    }
}
