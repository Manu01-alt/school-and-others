public class BuonoRegalo implements MetodoPagamento {
    private double saldo;

    public BuonoRegalo(double saldo) {
        this.saldo = saldo;
    }

    //getter
    public double getSaldo() {
        return saldo;
    }

    //setter 
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    @Override
    public boolean paga(double importo) {
        if (importo <= saldo) {
            this.setSaldo(this.getSaldo() - importo);
            System.out.print("\nPagato con Buono Regalo di importo: " + importo);
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
