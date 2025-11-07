
public class Veicolo {
	
	private String targa;
	private String modello;
	private double tariffaOraria;
	private int oreSosta;
	
	//costruttore
	public Veicolo (String targa, String modello, double tariffaOraria, int oreSosta) {
		this.setTarga(targa);
		this.setModello(modello);
		this.setTariffaOraria(tariffaOraria);
		this.setOreSosta(oreSosta);
	}

	//getter
	public String getTarga() {
		return targa;
	}

	public String getModello() {
		return modello;
	}

	public double getTariffaOraria() {
		return tariffaOraria;
	}

	public int getOreSosta() {
		return oreSosta;
	}

	//setter
	public void setTarga(String targa) {
		this.targa = targa;
	}

	public void setModello(String modello) {
		this.modello = modello;
	}

	public void setTariffaOraria(double tariffaOraria) {
		this.tariffaOraria = tariffaOraria;
	}

	public void setOreSosta(int oreSosta) {
		this.oreSosta = oreSosta;
	}
	
	//metodo
	/**
	 * Metodo rappresentativo del veicolo
	 * @return stringa rappresentativa
	 */
	public String toString() {
		return this.targa + " - " + this.modello + " - " + "€" + this.tariffaOraria + "/h - ore: " + this.oreSosta; 
	}
}
