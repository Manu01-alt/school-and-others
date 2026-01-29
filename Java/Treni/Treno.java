import java.util.ArrayList;

public class Treno {
    private ArrayList<Vagone> treno;

    public Treno() {
        this.treno = new ArrayList<>();
    }

    public void aggiungiVagone(Vagone vagone) {
        treno.add(vagone);
    }


    public double PesoComplessivo() {
        double peso_totale = 0.0;
        for (Vagone vagone : treno) {
            if (vagone instanceof Vagone_passeggeri) {
                Vagone_passeggeri vp = (Vagone_passeggeri) vagone;
                peso_totale += vp.calcolaPesoTotale();
            } else if (vagone instanceof Vagone_merci) {
                Vagone_merci vm = (Vagone_merci) vagone;
                peso_totale += vm.getPeso_a_vuoto() + vm.getPeso_effettivo_carico();
            }
        }
        return peso_totale;
    }
}
