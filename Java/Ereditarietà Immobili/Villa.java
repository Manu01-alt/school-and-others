public class Villa extends Abitazione {
    protected int numeroPiani;
    protected double superficieGiardino;
    protected boolean piscina;

    public Villa(String città, String indirizzo, int numeroStanze, double superficie, int numeroPiani, double superficieGiardino, boolean piscina) {
        super(città, indirizzo, numeroStanze, superficie);
        this.numeroPiani = numeroPiani;
        this.superficieGiardino = superficieGiardino;
        this.piscina = piscina;
    }

    //getter
    public int getNumeroPiani() {
        return numeroPiani;
    }
    public double getSuperficieGiardino() {
        return superficieGiardino;
    }
    public boolean hasPiscina() {
        return piscina;
    }

    //setter
    public void setNumeroPiani(int numeroPiani) {
        this.numeroPiani = numeroPiani;
    }
    public void setSuperficieGiardino(double superficieGiardino) {
        this.superficieGiardino = superficieGiardino;
    }
    public void setPiscina(boolean piscina) {
        this.piscina = piscina;
    }

    //metodi    
    public String toString() {
        return super.toString() + ", Numero Piani: " + numeroPiani + ", Superficie Giardino: " + superficieGiardino + " mq, Piscina: " + piscina;
    }

    public boolean equals(Villa V) {
        return super.equals(V) && this.numeroPiani == V.numeroPiani && this.superficieGiardino == V.superficieGiardino && this.piscina == V.piscina;
    }


}
