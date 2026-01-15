import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ConvertiValuta extends Application{
    public void start(Stage stage) {
        TextField txt = new TextField();
        txt.setPromptText("Inserisci valore euro");
        Label lbl = new Label();
        Button btn = new Button("Converti in dollari");

        btn.setOnAction(e -> lbl.setText(String.format("Valore in dollari: %.2f", Double.parseDouble(txt.getText()) * 1.17)));

        TextField txt2 = new TextField();
        txt.setPromptText("Inserisci valore in dollari");
        Label lbl2 = new Label();
        Button btn2 = new Button("Converti in euro");

        btn2.setOnAction(e -> lbl2.setText(String.format("Valore in euro: %.2f", Double.parseDouble(txt2.getText()) / 1.17)));

        // VBox con spaziatura di 10 pixel tra i nodi
        VBox root = new VBox(10, txt, btn, lbl, txt2, btn2, lbl2);
        stage.setScene(new Scene(root, 300, 200));
        stage.show();
    }
    public static void main(String[] args) { launch(); }
}
