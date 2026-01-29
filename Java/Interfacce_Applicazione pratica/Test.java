public class Test {
    public static void main(String[] args) {
        Dispostivo d1 = new Computer(); //Sto legando il computer all'interfaccia, una maggiore generalizzazione
                                        //vedo esclusivamente i metodi dell'interfaccia

        Dispostivo d2 = new Smartphone();
        Dispostivo d3 = new Stampante();

        Computer c1 = new Computer(); //lo vado a "legare" alla classe, ma lo sto "chiudendo" maggiormente
        Smartphone c2 = new Smartphone();
        Stampante c3 = new Stampante();


        d1.accendi();
        d2.accendi();
        d3.accendi();

        c1.accendi();
        c2.accendi();
        c3.accendi();

        ((Computer) d1).connettiti();
        c1.connettiti();

    }
}   
