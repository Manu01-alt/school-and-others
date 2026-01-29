public class Dirigente extends Dipendente {

    public Dirigente(String nome, String cognome, String codice, int annoAssunzione) {
        super(nome, cognome, codice, annoAssunzione);
    }

    @Override
    public double calcolaStipendio(int ore) {
        return 100 * ore;
    }
}