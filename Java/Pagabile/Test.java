import java.util.ArrayList;

public class Test {

    public static void main(String[] args) {
        ProdottoSingolo prodotto1 = new ProdottoSingolo(50.0);
        ProdottoSingolo prodotto2 = new ProdottoSingolo(30.0);
        AbbonamentoMensile abbonamento = new AbbonamentoMensile(10.0, 6);

        ArrayList<Pagabile> carrello = new ArrayList<>();
        carrello.add(prodotto1);
        carrello.add(prodotto2);
        carrello.add(abbonamento);

        for (Pagabile i : carrello) {
            System.out.println("Prezzo: " + i.calcolaTotale());
        }
    }
}