public class TecnicoInformatico extends Tecnico {
    
    public TecnicoInformatico(String nome, String cognome, String codice, int annoAssunzione, boolean interno) {
        super(nome, cognome, codice, annoAssunzione);
    }

    @Override
    public double calcolaStipendio(int ore) {
        double base = 50 * ore;
        int anniLavoro = 2026-annoAssunzione;
        if (interno)
            return base + anniLavoro;
        return base;
    }
}