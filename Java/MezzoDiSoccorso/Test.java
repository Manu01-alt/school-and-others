import java.util.ArrayList;

public class Test {

    public static void main(String[] args) {
        
        MezzoDiSoccorso mezzo = new MezzoDiSoccorso(500.0);
        System.out.println("Capacità: " + mezzo.getCapacità() + " kg");
        System.out.println("Può volare: " + mezzo.vola());
        System.out.println("Ha motore: " + mezzo.hasMotore());
        System.out.println("Può trasportare: " + mezzo.trasporta());
        System.out.println("Può navigare: " + mezzo.nuoto());


        MezzoDiSoccorso mezzo2 = new MezzoDiSoccorso(300.0);
        
        //Collezione di oggetti di tipo Motorizzato
        ArrayList<Motorizzato> mezziMotorizzati = new ArrayList<>();
        mezziMotorizzati.add(mezzo);
        mezziMotorizzati.add(mezzo2);

        for (Motorizzato m : mezziMotorizzati) {
            System.out.println("Mezzo con motore: " + m.hasMotore());
        }

    }
}