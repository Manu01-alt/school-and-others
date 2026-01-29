import java.util.ArrayList;

public class Cassa {
    public static void main(String[] args) {
        MetodoPagamento pagamento;
        pagamento = new CartaDiCredito("1234-5678-9012-3456", 500.0);
        pagamento.paga(150.0);

        pagamento = new PayPal("user@example.com", 500.0);
        pagamento.paga(200.0);

        pagamento = new BuonoRegalo(300.0);
        pagamento.paga(100.0);

        pagamento = new Bonifico("IT60X0542811101000000123456", 400.0);
        pagamento.paga(500.0);

        ArrayList<MetodoPagamento> metodi = new ArrayList<>();
        metodi.add(new CartaDiCredito("9876-5432-1098-7654", 600.0));
        metodi.add(new PayPal("user2@example.com", 700.0));
        metodi.add(new BuonoRegalo(400.0));
        metodi.add(new Bonifico("IT60X0542811101000000123456", 800.0));

        for (MetodoPagamento metodo : metodi) {
            metodo.paga(250.0);
        }
    }
}
