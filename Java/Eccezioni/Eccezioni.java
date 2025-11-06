import java.lang.reflect.Array;
import java.util.ArrayList;

public class Eccezioni {
    public static void main(String[] args) {
        String s = "80";
        int i = 0;

        try {
            i = Integer.valueOf(s);
            System.out.println(i);
        }
        catch (NumberFormatException e){
            System.out.println( s + " non e' un numero, non possiamo convertirlo in int");
        }

        try {
            double divisione = 7 / 0;
            System.out.println(divisione);
        } catch (ArithmeticException e) {
            System.out.println("NON. SI. DIVIDE. PER. ZERO.");
        }


        ArrayList<String> lista = null;
        try {
            lista.add("pippo");
        }
        catch (NullPointerException e){
            System.out.println("La lista è null");
        }

        
        lista = new ArrayList<>();
        String s2 = lista.get(3);

        try {
            System.out.println(s2);
        }
        catch (IndexOutOfBoundsException e){
            System.out.println("MAMMA MIA, HAI PROVATO A PRENDERE UN ELEMENTO CHE NON C'È!, SEI PAZZO?, MA COME FAI? VERGOGNA!, STAI ATTENTO!" );
        }

    }
}   
