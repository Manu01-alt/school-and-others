import java.time.LocalDate;

public class Libro extends Pubblicazione{
    private String isbn;
    private String autore;
    
    public Libro(String titolo, LocalDate dataPubblicazione, int numPagine, String isbn, String autore) {
        super(titolo, dataPubblicazione, numPagine);
        this.isbn = isbn;
        this.autore = autore;
    }

    public String getIsbn() {
        return isbn;
    }
    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }
    public String getAutore() {
        return autore;
    }
    public void setAutore(String autore) {
        this.autore = autore;
    }

    @Override
    public void setDataPrestito() {
        this.dataPrestito = LocalDate.now().plusMonths(2);
    }

    public String toString() {
        return "Libro [isbn=" + isbn + ", autore=" + autore + ", " + super.toString() + "]";
    }

 
    

}
