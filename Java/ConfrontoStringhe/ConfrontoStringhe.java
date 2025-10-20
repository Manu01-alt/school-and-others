package Java.ConfrontoStringhe;

public class ConfrontoStringhe {
    public static void main(String[] args) {
        String s1 = new String("Ciao");
        String s2 = new String("Ciao");

        if (s1 == s2) {
            System.out.println("uguali");
        } else {
            System.out.println("diversi");
        }

        if (s1.equals(s2)) {
            System.out.println("uguali");
        } else {
            System.out.println("diversi");
        }

        String s3 = "Ciao"; //vengono trattati in modo diverso da Java, si chiamano stringhe letterali
        String s4 = "Ciao"; //si trovano nello string pool

        if (s3 == s4) {
            System.out.println("uguali");
        } else {
            System.out.println("diversi");
        }

        if (s3 == s1) {
            System.out.println("uguali");
        } else {
            System.out.println("diversi");
        }

    }
}
