public class GestioneVoti {
    static String[] voti = {"8", "10", "abc","12", "-3", "7"};

    static String media() {
        int somma = 0;
        int count = 0;

        for (String n : voti) {
            try {
                if(Integer.parseInt(n) <= 10 && Integer.parseInt(n) >= 0) {
                    somma += Integer.parseInt(n);
                    count++;
                }
        }
        catch (NumberFormatException e) {
            return (n + " elemento non valido");
        }
    }
    return ("La media dei voti e' " + Integer.toString(somma / count));
    }
    public static void main(String[] args) {
        System.out.println(media());
    }



}