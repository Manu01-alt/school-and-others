public class Autovettura extends Veicolo {
    private int numero_posti;

    //costruttore
    public Autovettura(String targa, int numero_di_matricola, String marca, String modello, double cilindrata, int anno_di_acquisto, double capacita_serbatoio, int numero_posti) {
        super(targa, numero_di_matricola, marca, modello, cilindrata, anno_di_acquisto, capacita_serbatoio);
        this.numero_posti = numero_posti;   
    }

    //getter e setter
    public int getNumero_posti() {
        return numero_posti;    
    }

    public void setNumero_posti(int numero_posti) {
        this.numero_posti = numero_posti;    
    }


    //metodo

    @Override
    public double calcolaConsumo(double kmPercorsi, double carburanteMancante, int giorni) {
        double costoNoleggio = (giorni * 50) + ((kmPercorsi/25)*1) + ((this.capacita_serbatoio - carburanteMancante) * 2);
        return costoNoleggio;
    }


    public String toString() {
        return super.toString() + "numero_posti=" + numero_posti;
    }
}