public class PayPal implements MetodoPagamento {
    private String email;
    private double contoDisponibile;

    public PayPal(String email, double contoDisponibile) {
        this.email = email;
        this.contoDisponibile = contoDisponibile;
    }

    //getter
    public String getEmail() {
        return email;
    }
    public double getContoDisponibile() {
        return contoDisponibile;
    }

    //setter
    public void setEmail(String email) {
        this.email = email;
    }
    public void setContoDisponibile(double saldo) {
        this.contoDisponibile = saldo;
    }

    @Override
    public boolean paga(double importo) {
        if (importo <= contoDisponibile) {
            this.setContoDisponibile(this.getContoDisponibile()-importo);
            System.out.print("\nPagato con Paypal di importo: " + importo);
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
