public class Funzionario extends Dipendente {

    public Funzionario(String nome, String cognome, String codice, int annoAssunzione) {
        super(nome, cognome, codice, annoAssunzione);
    }

    @Override
    public double calcolaStipendio(int ore) {
        if (2026-annoAssunzione > 10) {
            return 85 * ore;
        }
        else
            return 75 * ore;
    }   
}
