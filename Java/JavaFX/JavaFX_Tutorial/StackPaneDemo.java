import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/* Tutorial JavaFX – StackPane

StackPane è un container che:
    - impila i nodi uno sopra l’altro
    - per default li centra
    - è perfetto per:
        sovrapporre elementi
        centrare contenuti
        creare overlay (popup, loading, badge)
*/
public class StackPaneDemo extends Application {
    @Override
    public void start(Stage stage) {
        StackPane root = new StackPane();

        // *** Bottone Centrato
        Button btn = new Button("Cliccami");
        root.getChildren().add(btn);

        // *** Più nodi sovrapposti
        // Label sfondo = new Label("SFONDO");
        // sfondo.setStyle("-fx-background-color: lightgray; -fx-padding: 40;");
        // Button btn = new Button("Davanti");
        // root.getChildren().addAll(sfondo, btn);

        // *** Allineamento personalizzato dei nodi
        // Button b1 = new Button("Centro");
        // Button b2 = new Button("In basso a destra");
        // StackPane.setAlignment(b1, Pos.CENTER);
        // StackPane.setAlignment(b2, Pos.BOTTOM_RIGHT);
        // root.getChildren().addAll(b1, b2);

        // *** Wrapping di un altro layout
        /*
            Se mettessimo il GridPane direttamente nel centro del BorderPane:
            - Il nodo nel CENTER viene ridimensionato per occupare tutto lo spazio disponibile
            - le celle diventano enormi
            - il layout 'brutto'
            - Incapsulando il grid in uno StackPane:
                - lo StackPane centra il form
                - il form mantiene le sue dimensioni naturali
         */
        // BorderPane root = new BorderPane();
        // GridPane form = new GridPane();
        // form.addRow(0, new Label("Username:"), new TextField());
        // form.addRow(1, new Label("Password:"), new TextField());
        // StackPane wrapper = new StackPane(form);
        // wrapper.setAlignment(Pos.CENTER);
        // root.setCenter(wrapper);

        stage.setScene(new Scene(root, 300, 100));
        stage.show();
    }
    public static void main(String[] args) { launch(); }
}