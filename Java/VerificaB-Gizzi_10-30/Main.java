public class Main {

	public static void main(String[] args) {
		
		Parcheggio PA = new Parcheggio(3);
		
		Veicolo v1 = new Veicolo("AB123CD","Fiat Panda",2.50,3);
		Veicolo v2 = new Veicolo("EF456GH","Fiat Panda",2.50,1);
		Veicolo v3 = new Veicolo("IJ789KL","Fiat Panda",2.50,5);
		
		PA.aggiungiVeicolo(v1);
		PA.aggiungiVeicolo(v2);
		PA.aggiungiVeicolo(v3);
		
		System.out.println(PA.toString());
		
		PA.esciVeicolo("EF456GH");
		
		System.out.println("\n" + PA.toString());
		
		System.out.println("Incasso totale: " + PA.incassoTotale() + "€");
		

	}

}
