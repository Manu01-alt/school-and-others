public class Test {
    
    public static void main(String[] args) {
        Treno treno = new Treno();

        Vagone_passeggeri vp1 = new Vagone_passeggeri(1, 3000.0, "Fiat", 2000, "Prima", 100, 80);
        Vagone_merci vm1 = new Vagone_merci(2, 5000.0, "Siemens", 1995, 50.0, 20000.0, 15000.0);

        treno.aggiungiVagone(vp1);
        treno.aggiungiVagone(vm1);

        double pesoTotale = treno.PesoComplessivo();
        System.out.println("Peso complessivo del treno: " + pesoTotale + " kg");
    }
}
