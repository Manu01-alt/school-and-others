import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        
        Notifica notifica;

        //Prova push
        notifica = new PushNotifica("AppMobile");
        notifica.invia("Ciao! Questa è una notifica push.");
        
        //Prova email
        notifica = new EmailNotifica("example@example.com");
        notifica.invia("Ciao! Questa è una notifica email.");
        
        //Prova SMS
        notifica = new SmsNotifica("+391234567890");
        notifica.invia("Ciao! Questa è una notifica SMS.");

        System.out.println("\n--- Invio notifiche multiple ---\n");

        ArrayList<Notifica> notifiche = new ArrayList<Notifica>();        
        notifiche.add(new PushNotifica("AppMobile"));
        notifiche.add(new EmailNotifica("example@example.com"));    
        notifiche.add(new SmsNotifica("+391234567890"));
        notifiche.add(new ChiamataNotifica("Mario"));
        for (Notifica n : notifiche) {
            if (n.invia("\nMessaggio!\n"))
                System.out.println("Notifica inviata con successo.");
            else
                System.out.println("Errore nell'invio della notifica.");
        }

    }
}
