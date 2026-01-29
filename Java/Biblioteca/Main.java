import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        System.out.println("Benvenuti nella Biblioteca! è il " + LocalDate.now());
        Biblioteca biblioteca = new Biblioteca();

        Libro libro1 = new Libro("Il Signore degli Anelli", LocalDate.of(1954, 7, 29), null, true, "", 1216, "978-0261102385", "J.R.R. Tolkien");
        Rivista rivista1 = new Rivista("National Geographic", LocalDate.of(2023, 1, 1), null, true, "", 100, true);

        System.out.println(Pubblicazione.num); 
        
        System.out.println("Libro: ");
        System.out.println(libro1.toString());
        System.out.println("Rivista: ");
        System.out.println(rivista1.toString());

        biblioteca.aggiungiPubblicazione(libro1);
        biblioteca.aggiungiPubblicazione(rivista1);

        System.out.println(biblioteca.Prestito(libro1, "Via Roma 1, Milano"));
        System.out.println(biblioteca.Prestito(rivista1, "Via Milano 2, Roma"));

        System.out.println(biblioteca.Restituzione(libro1));
        System.out.println(biblioteca.Restituzione(rivista1));
    }
}

