public abstract class Tecnico extends Dipendente {
    protected boolean interno;

    public Tecnico(String nome, String cognome, String codice, int annoAssunzione) {
        super(nome, cognome, codice, annoAssunzione);
    }

    public abstract double calcolaStipendio(int ore);
}
