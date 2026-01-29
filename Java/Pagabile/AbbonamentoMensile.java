public class AbbonamentoMensile implements Pagabile {
    private double costoAlMese;
    private double numeroMesi;

    public AbbonamentoMensile(double costoAlMese, double numeroMesi) {
        this.costoAlMese = costoAlMese;
        this.numeroMesi = numeroMesi;
    }

    //getter
    public double getCostoAlMese() {
        return costoAlMese;
    }

    public double getTotaleAnnuale() {
        return numeroMesi;
    }

    //setter
    public void setCostoAlMese(double costoAlMese) {
        this.costoAlMese = costoAlMese;
    }

    public void setNumeroMesi(double numeroMesi) {
        this.numeroMesi = numeroMesi;
    }

    //methods
    @Override
    public double calcolaTotale() {
        return costoAlMese*numeroMesi;
    }
}