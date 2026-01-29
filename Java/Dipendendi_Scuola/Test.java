import java.time.LocalDate;
public class Test {
    public static void main(String[] args) {
  
        Docente docente = new Docente("Mario Rossi", "M", LocalDate.of(1980, 5, 15), 120, 2500.0);
        System.out.println(docente.toString());
        System.out.println("Stipendio Docente: " + docente.calcolaStipendio());

        Impiegato_con_Straordinari impiegato = new Impiegato_con_Straordinari("Luigi Bianchi", "M", LocalDate.of(1975, 8, 20), "Senior", 3000.0, 10, 25.0);
        System.out.println(impiegato.toString());
        System.out.println("Stipendio Impiegato con Straordinari: " + impiegato.calcolaStipendio());
    }
}