public class ProdottoSingolo implements Pagabile {
    private double prezzo;

    public ProdottoSingolo(double prezzo) {
        this.prezzo = prezzo;
    }

    //getter
    public double getPrezzo() {
        return prezzo;
    }

    //setter
    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    //methods
    @Override
    public double calcolaTotale() {
        return prezzo;
    }
    
}

