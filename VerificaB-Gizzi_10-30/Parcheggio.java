import java.util.ArrayList;

public class Parcheggio {

	ArrayList<Veicolo> veicoli;
	
	//costruttore
	public Parcheggio(int dim) {
		this.veicoli = new ArrayList<Veicolo>(dim);
	}
	
	/**
	 * Metodo per aggiungere un veicolo
	 * @param v - Veicolo
	 */
	public void aggiungiVeicolo(Veicolo v) {
		veicoli.add(v);
	}
	
	/**
	 * Metodo per rimuovere un veicolo tramite l'uso della targa
	 * @param targa - per la ricerca del veicolo
	 */
	public void rimuoviVeicolo(String targa) {
		for (int i = 0; i < veicoli.size(); i++) {
			if (veicoli.get(i).getTarga().equals(targa)) {
				veicoli.remove(i);
			}
		}
	}
	
	/**
	 * Metodo che cerca un veicolo tramite l'uso della targa e lo restituisce
	 * @param targa - per la ricerca del veicolo
	 * @return Veicolo trovato o null
	 */
	public Veicolo cercaVeicolo(String targa) {
		for (int i = 0; i < veicoli.size(); i++) {
			if (veicoli.get(i).getTarga().equals(targa)) 
				return veicoli.get(i);
		}
		return null;
		}
	
	/**
	 * Metodo che cerca un veicolo tramite l'uso della targa, stampa l'importo da pagare e lo rimuove dal parcheggio
	 * @param targa - per la ricerca del veicolo
	 * @return true se l'operazione è avvenuta con successo, false se il contrario
	 */
	public boolean esciVeicolo(String targa) {
		if (cercaVeicolo(targa) != null) {		
		System.out.println("Importo da pagare: " + (cercaVeicolo(targa).getTariffaOraria() * cercaVeicolo(targa).getOreSosta()) + "€");
		rimuoviVeicolo(targa);
		return true;
		}
		return false;
	}
	
	/**
	 * Metodo che fa il calcolo dell'incasso totale del parcheggio
	 * @return int somma - somma di tutti gli incassi (tariffaOraria * oreSosta)
	 */
	public double incassoTotale() {
		double somma = 0;
		for (int i = 0; i < veicoli.size(); i++) {
			somma += (veicoli.get(i).getTariffaOraria() * veicoli.get(i).getOreSosta());
		}
		return somma;
	}
	
	/**
	 * Metodo che restituisce l'elenco numerato dei ceicoli presenti nel parcheggio
	 * @return string - stringa rappreentativa
	 */
	public String toString() {
		String stringhe = "";
		for (int i = 0; i < veicoli.size(); i++) {
			stringhe += "Veicolo " + (i+1) + " :" + veicoli.get(i).toString() + "\n";
		}
		return stringhe;
	}
}
