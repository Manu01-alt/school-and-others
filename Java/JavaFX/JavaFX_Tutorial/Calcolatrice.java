import javafx.application.Application;
import javafx.event.Event;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;

public class Calcolatrice extends Application{
    // Componenti dell'interfaccia grafica
    private Button[] buttons;
    private TextField risultato;
    private String[] strings = {
                                "1", "2", "3", "X",
                                "4", "5", "6", "+",
                                "7", "8", "9", "/",
                                ",", "0", "=", "-"
                                };
    
    // Variabili per gestire lo stato della calcolatrice
    private double primoNumero = 0;
    private String operatore = "";
    private boolean inizioNuovoNumero = true;
    private boolean operatorePremuto = false;
    
    public void start(Stage stage) {

        buttons = new Button[16];

        BorderPane root = new BorderPane();
        BorderPane display = new BorderPane();

        Button btnChiudi = new Button("Chiudi");
        btnChiudi.setOnAction(e -> stage.close());

        GridPane tastiera = new GridPane();
        root.setCenter(tastiera);
        tastiera.setHgap(4);
        tastiera.setVgap(4);

        // Creazione e posizionamento dei bottoni della calcolatrice
        for(int i = 0; i < 16; i++) {
            buttons[i] = new Button(strings[i]);
            int riga = i/4;
            int colonna = i%4;
            buttons[i].setOnAction(e -> clickBottone(e));
            tastiera.add(buttons[i],colonna,riga);
        }

        risultato = new TextField();
        root.setTop(display);
        display.setTop(btnChiudi);
        display.setCenter(risultato);
        root.setPadding(new Insets(15));

        stage.setScene(new Scene(root, 300, 200));
        stage.show();
        

    }

    /**
     * Metodo che gestisce il click sui bottoni della calcolatrice
     * @param e Evento di click
     */
    private void clickBottone(Event e) {
        Button btn = (Button) e.getSource();
        String valore = btn.getText();
        
        // il valore è un numero o una virgola
        if (valore.equals(",") || valore.equals("0") || valore.equals("1") || valore.equals("2") || valore.equals("3") || valore.equals("4") || valore.equals("5") || valore.equals("6") || valore.equals("7") || valore.equals("8") || valore.equals("9")) {
            if (inizioNuovoNumero) { 
                risultato.setText(valore);
                inizioNuovoNumero = false;
            } else {
                risultato.appendText(valore);
            }
        }
        // il valore è "="
        else if (valore.equals("=")) {
            calcolaRisultato();
            operatore = "";
            inizioNuovoNumero = true;
            operatorePremuto = false;
        } 
        // È un operatore 
        else {
            if (operatorePremuto) {
                operatore = valore;
                return;
            }
            primoNumero = Double.parseDouble(risultato.getText().replace(",", "."));
            operatore = valore;
            inizioNuovoNumero = true;
            operatorePremuto = true;
        }
    }
    /**
     * Metodo che calcola il risultato dell'operazione
     */
    private void calcolaRisultato() {
        double secondoNumero = Double.parseDouble(risultato.getText().replace(",", "."));
        double result = 0;
        
        switch (operatore) {
            case "+":
                result = primoNumero + secondoNumero;
                break;
            case "-":
                result = primoNumero - secondoNumero;
                break;
            case "X":
                result = primoNumero * secondoNumero;
                break;
            case "/":
                try {
                    if  (secondoNumero == 0) {
                    throw new ArithmeticException("Divisione per zero non consentita");
                    }
                } catch (ArithmeticException e) {
                    risultato.setText("Errore: " + e.getMessage());
                    return;
                }
                result = primoNumero / secondoNumero;
                break;
        }
        
        risultato.setText(String.valueOf(result));
        primoNumero = result;
    }



    public static void main(String[] args) { launch(); }
}
