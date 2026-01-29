public class ChiamataNotifica implements Notifica {
    private String Contatto;

    //Costruttore
    public ChiamataNotifica(String Contatto) {
        this.Contatto = Contatto;
    }

    //Getter
    public String getContatto() {
        return Contatto;
    }

    //Setter
    public void setContatto(String Contatto) {
        this.Contatto = Contatto;
    }

    //Metodo
    public boolean invia(String messaggio) {
        System.out.println("Effettuo chiamata a " + Contatto + " con il messaggio: " + messaggio);
        return false;    
    }

    
}