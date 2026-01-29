public class PushNotifica implements Notifica {
    private String app;

    //Costruttore
    public PushNotifica(String app) {
        this.app = app;
    }

    //Getter
    public String getApp() {
        return app;
    }

    //Setter
    public void setApp(String app) {
        this.app = app;
    }

    //Metodo
    public boolean invia(String messaggio) {
        System.out.println("Invio notifica push tramite " + app + " con il messaggio: " + messaggio);
        return true;
    }
}
