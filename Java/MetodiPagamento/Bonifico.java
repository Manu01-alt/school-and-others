public class Bonifico implements MetodoPagamento {
    private String iban;
    private double saldoConto;

    public Bonifico(String iban, double saldoConto) {
        this.iban = iban;
        this.saldoConto = saldoConto;
    }

    //getter
    public String getIban() {
        return iban;
    }
    public double getSaldoConto() {
        return saldoConto;
    }

    //setter
    public void setIban(String iban) {
        this.iban = iban;
    }
    public void setSaldoConto(double saldoConto) {
        this.saldoConto = saldoConto;
    }

    @Override
    public boolean paga(double importo) {
        if (importo <= saldoConto) {
            this.setSaldoConto(this.getSaldoConto() - importo);
            System.out.print("\nPagato con Bonifico di importo: " + importo);
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