import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;

public class ConvertiValuta3 extends Application{
    public void start(Stage stage) {


        GridPane grid = new GridPane();
        
        BorderPane root = new BorderPane();

        grid.setHgap(10);
        grid.setVgap(10);

        grid.setPadding(new Insets(15));

        TextField txt = new TextField();
        txt.setPromptText("Inserisci valore euro");
        Label lbl = new Label();
        Button btn = new Button("Converti in dollari");

        btn.setOnAction(e -> lbl.setText(String.format("Valore: %.2f$", Double.parseDouble(txt.getText()) * 1.17)));

        TextField txt2 = new TextField();
        txt2.setPromptText("Inserisci valore in dollari");
        Label lbl2 = new Label();
        Button btn2 = new Button("Converti in euro");

        btn2.setOnAction(e -> lbl2.setText(String.format("Valore: %.2f€", Double.parseDouble(txt2.getText()) / 1.17)));

        Separator sep = new Separator();

        grid.add(txt, 0, 0);
        grid.add(btn, 0, 1);
        grid.add(lbl, 1, 1);

        grid.add(sep, 0, 2);

        grid.add(txt2, 0, 3);
        grid.add(btn2, 0, 4);
        grid.add(lbl2, 1, 4);

        Button closeBtn = new Button("Chiudi applicazione");
        closeBtn.setOnAction(e -> stage.close());

        root.setCenter(grid);
        root.setTop(closeBtn);
        root.setPadding(new Insets(10));

        stage.setScene(new Scene(root, 300, 200));
        stage.show();
    }
    public static void main(String[] args) { launch(); }
}
