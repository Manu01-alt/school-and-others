public class SmsNotifica implements Notifica {
    private String numeroTelefono;

    //Costruttore
    public SmsNotifica(String numeroTelefono) {
        this.numeroTelefono = numeroTelefono;
    }

    //Getter
    public String getNumeroTelefono() {
        return numeroTelefono;
    }

    //Setter
    public void setNumeroTelefono(String numeroTelefono) {
        this.numeroTelefono = numeroTelefono;
    }
    
    //Metodo
    public boolean invia(String messaggio) {
        System.out.println("Invio SMS a " + numeroTelefono + " con il messaggio: " + messaggio);
        return true;    
    }
}
