public class EmailNotifica implements Notifica {
    private String indirizzoEmail;

    //Costruttore
    public EmailNotifica(String indirizzoEmail) {
        this.indirizzoEmail = indirizzoEmail;
    }

    //Getter
    public String getIndirizzoEmail() {
        return indirizzoEmail;
    }

    //Setter
    public void setIndirizzoEmail(String indirizzoEmail) {
        this.indirizzoEmail = indirizzoEmail;
    }

    //Metodo
    public boolean invia(String messaggio) {
        System.out.println("Invio email a " + indirizzoEmail + " con il messaggio: " + messaggio);
        return true; 
    }
}