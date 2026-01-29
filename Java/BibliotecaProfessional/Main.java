import java.time.LocalDate;

public class Main {
    
    public static void main(String[] args) {
        Libro p1 = new Libro("la bella e la bestia", LocalDate.of(2008, 4, 5), 150, "123456654", "disney");
        Rivista p2 = new Rivista("pomeriggio 5", LocalDate.of(2025, 9, 21), 35, true);
        Libro p3 = new Libro("Il signore degli anelli", LocalDate.of(1954, 7, 29), 1200, "9780544003415", "Tolkien");
        Libro p4 = new Libro("Harry Potter e la pietra filosofale", LocalDate.of(1997, 6, 26), 320, "9780747532743", "J.K. Rowling");
        Rivista p5 = new Rivista("National Geographic", LocalDate.of(2023, 3, 1), 98, false);
        Rivista p6 = new Rivista("Focus", LocalDate.of(2024, 10, 15), 72, true);

        Biblioteca biblioteca = new Biblioteca();

        biblioteca.aggiungiPubblicazione(p1);
        biblioteca.aggiungiPubblicazione(p2);
        biblioteca.aggiungiPubblicazione(p3);
        biblioteca.aggiungiPubblicazione(p4);
        biblioteca.aggiungiPubblicazione(p5);
        biblioteca.aggiungiPubblicazione(p6);
        
        System.out.println(biblioteca.rimuoviPubblicazione("pomeriggio 5"));

        System.out.println(biblioteca.inPrestito("il signore degli anelli", "bjow"));
        System.out.println(biblioteca.inPrestito("national Geographic", "hfe"));
        System.out.println(biblioteca.inPrestito("national geographic", "ipwef"));
        System.out.println(biblioteca.inPrestito("il signore degli anelli", "bjow"));
        biblioteca.restituzionePrestito("il signore degli anelli");

    }
}
