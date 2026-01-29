public class CartaDiCredito implements MetodoPagamento {
    private String numerocarta;
    private double contoDisponibile;
    
    public CartaDiCredito(String numerocarta, double contoDisponibile) {
        this.numerocarta = numerocarta;
        this.contoDisponibile = contoDisponibile;
    }

    //getter
    public String getNumerocarta() {
        return numerocarta;
    }
    public double getContoDisponibile() {
        return contoDisponibile;
    }

    //setter
    public void setNumerocarta(String numerocarta) {
        this.numerocarta = numerocarta;
    }
    public void setContoDisponibile(double contoDisponibile) {
        this.contoDisponibile = contoDisponibile;
    }


    @Override
    public boolean paga(double importo) {
        if (importo <= contoDisponibile) {
            this.setContoDisponibile(this.getContoDisponibile()-importo);
            System.out.print("\nPagato con Carta di credito di importo: " + importo);
            return true;
        } else {
            try {
                throw new Exception("\nSaldo insufficiente.");
            } catch (Exception e) {
                System.out.println(e.getMessage());
                return false;
            }
        }
    }
}
