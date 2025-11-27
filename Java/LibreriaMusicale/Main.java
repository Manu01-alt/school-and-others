import java.time.LocalDate;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        
        LibreriaMusicale library = new LibreriaMusicale(10, "La mia Libreria Musicale");


        Brano b1 = new Brano("Song1", "Artist1", "Pop", 210, LocalDate.of(2020, 5, 20), 1500);
        Brano b2 = new Brano("Song2", "Artist2", "Rock", 180, LocalDate.of(2019, 3, 15), 2500);
        Brano b3 = new Brano("Song3", "Artist1", "Pop", 200, LocalDate.of(2021, 7, 10), 3000); 
        Brano b4 = new Brano("Song4", "Artist4", "Pop", 240, LocalDate.of(2018, 11, 5), 1200);
        Brano b5 = new Brano("Song5", "Artist5", "Pop", 300, LocalDate.of(2017, 1, 25), 800);  
        

        library.aggiungiBrano(b1);
        library.aggiungiBrano(b2);
        library.aggiungiBrano(b3);
        library.aggiungiBrano(b4);
        library.aggiungiBrano(b5);


        b1.incrementaAscolti();
        b3.incrementaAscolti();

        library.rimuoviBrano("Song2", "Artist2");


        System.out.println("Minuti totali ascoltati: " + library.getMinutiAscoltati());
        
        System.out.println("Brani di genere Pop:");
        ArrayList<Brano> popSongs = library.braniPerGenere("Pop");
        for (Brano brano : popSongs) {
            System.out.println("- " + brano.getTitolo() + " di " + brano.getArtista());
        }
        
        System.out.println("Numero di brani dell'artista 'Artist1': " + library.contaBraniPerArtista("Artist1"));
        
        System.out.println("Brano piu' ascoltato: " + library.piuAscoltato().getTitolo() + " di " + library.piuAscoltato().getArtista());
        
        System.out.println("Durata media dei brani: " + library.calcolaDurataMediaBrani() + " secondi");

        System.out.println("Lista mischiata: ");
        for (Brano brano : library.shuffleConSeed("Pop", 600)) {
            System.out.println("- " + brano.getTitolo() + " di " + brano.getArtista());
        
        }
    }
}
