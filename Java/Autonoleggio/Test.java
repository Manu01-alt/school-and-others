public class Test {
    public static void main(String[] args) {
        Autonoleggio autonoleggio = new Autonoleggio();

        Autovettura auto1 = new Autovettura("AB123CD", 1001, "Fiat", "Panda", 1.2, 2020, 40, 5);
        Furgone furgone1 = new Furgone("EF456GH", 2001, "Iveco", "Daily", 3.0, 2019, 80, 1500);

        autonoleggio.aggiungiVeicolo(auto1);
        autonoleggio.aggiungiVeicolo(furgone1);

        autonoleggio.noleggioVeicolo(auto1);
        autonoleggio.restituisciVeicolo(auto1, 300, 10, 3);

        autonoleggio.noleggioVeicolo(furgone1);
        autonoleggio.restituisciVeicolo(furgone1, 250, 20, 2);
    }
}