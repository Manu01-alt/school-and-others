import java.util.ArrayList;

public class Autonoleggio {
    ArrayList<Veicolo> veicoli;

    public Autonoleggio() {
        veicoli = new ArrayList<Veicolo>();
    }

    public void aggiungiVeicolo(Veicolo v) {
        veicoli.add(v);
    }

    public void rimuoviVeicolo(Veicolo v) {
        veicoli.remove(v);
    }

    public void noleggioVeicolo(Veicolo v) {
        if (veicoli.contains(v)) {
            veicoli.remove(v);
            System.out.println("Veicolo noleggiato: " + v.getMarca() + " " + v.getModello());
        } else {
            System.out.println("Veicolo non disponibile per il noleggio.");
        }
    }

    public void restituisciVeicolo(Veicolo v, int kmPercorsi, double carburanteMancante, int giorni) {
        veicoli.add(v);
        System.out.println("Veicolo restituito: " + v.getMarca() + " " + v.getModello());
        if (v instanceof Autovettura) {
            Autovettura a = (Autovettura) v;
            double costoNoleggio = a.calcolaConsumo(kmPercorsi, carburanteMancante, giorni);
            System.out.println("Costo noleggio Autovettura: " + costoNoleggio + " euro");
        } else if (v instanceof Furgone) {
            Furgone f = (Furgone) v;
            double costoNoleggio = f.calcolaConsumo(kmPercorsi, carburanteMancante, giorni);
            System.out.println("Costo noleggio Furgone: " + costoNoleggio + " euro");
        }
    }

    
}