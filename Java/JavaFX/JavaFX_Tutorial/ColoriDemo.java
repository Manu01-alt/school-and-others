import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class ColoriDemo extends Application {

    @Override
    public void start(Stage stage) {

        // ====== LABEL con Color (Java) ======
        Label lblTitolo = new Label("Gestione dei colori in JavaFX");
        lblTitolo.setTextFill(Color.DARKBLUE);   // colore via classe Color
        lblTitolo.setStyle("-fx-font-size: 18px; -fx-font-weight: bold;");

        // ====== LABEL con colore dinamico ======
        Label lblStato = new Label("Stato: OK");
        lblStato.setTextFill(Color.GREEN);

        // ====== BOTTONE con CSS inline ======
        Button btnCambia = new Button("Cambia stato");
        btnCambia.setStyle(
            "-fx-background-color: #1976D2;" +
            "-fx-text-fill: white;" +
            "-fx-font-weight: bold;"
        );

        // ====== EVENTO: cambio colore dinamico ======
        btnCambia.setOnAction(e -> {
            lblStato.setText("Stato: ERRORE");
            lblStato.setTextFill(Color.RED);   // colore via Java
        });

        // ====== CONTENITORE con Background (Java) ======
        VBox root = new VBox(15, lblTitolo, lblStato, btnCambia);
        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(20));

        BackgroundFill fill = new BackgroundFill(
            Color.rgb(220, 220, 100, 0.8), // RGBA con trasparenza
            CornerRadii.EMPTY,
            Insets.EMPTY
        );
        root.setBackground(new Background(fill));

        // ====== SCENE ======
        Scene scene = new Scene(root, 420, 250);
        stage.setTitle("Demo Colori JavaFX");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}
