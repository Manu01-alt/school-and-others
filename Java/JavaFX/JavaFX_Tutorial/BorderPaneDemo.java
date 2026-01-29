import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

/* Tutorial JavaFX – BorderPane
BorderPane è un layout che divide lo spazio in 5 aree:
    TOP
    BOTTOM
    LEFT
    RIGHT
    CENTER

Ogni regione può contenere un solo nodo
Il CENTER prende tutto lo spazio disponibile rimanente
*/
public class BorderPaneDemo extends Application {
    @Override
    public void start(Stage stage) {
        BorderPane root = new BorderPane();

        root.setTop(new Label("TOP"));
        root.setBottom(new Label("BOTTOM"));
        root.setLeft(new Label("LEFT"));
        root.setRight(new Label("RIGHT"));
        root.setCenter(new TextArea("RIGA ALLARGATA AL CENTRO"));
        stage.setScene(new Scene(root, 300, 100));
        stage.show();
    }
    public static void main(String[] args) { launch(); }
}
