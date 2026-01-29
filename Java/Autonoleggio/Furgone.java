public class Furgone extends Veicolo {
    private double capacita_carico; // in kg

    //costruttore
    public Furgone(String targa, int numero_di_matricola, String marca, String modello, double cilindrata, int anno_di_acquisto, double capacita_serbatoio, double capacita_carico) {
        super(targa, numero_di_matricola, marca, modello, cilindrata, anno_di_acquisto, capacita_serbatoio);
        this.capacita_carico = capacita_carico; 
    }
    //getter e setter
    public double getCapacita_carico() {
        return capacita_carico;
    }

    public void setCapacita_carico(double capacita_carico) {
        this.capacita_carico = capacita_carico;
    }

    //metodo

    @Override
    public double calcolaConsumo(double kmPercorsi, double carburanteMancante, int giorni) {
        double costoNoleggio = (giorni * 70) + (((kmPercorsi-100)/30) * 1) + ((this.capacita_serbatoio - carburanteMancante) * 2);
        return costoNoleggio;
    }


    public String toString() {
        return super.toString() + "capacita_carico=" + capacita_carico;
    }
}