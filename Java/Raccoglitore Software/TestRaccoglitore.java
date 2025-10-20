public class TestRaccoglitore {

    public static void main(String[] args) {
        Raccoglitore c1 = new Raccoglitore(2);
        Raccoglitore c2 = new Raccoglitore(2);

        Programma p1 = new Programma("Programma1","Produttore1",1,"Linux",2008);
        Programma p2 = new Programma("Programma2","Produttore2",1,"Linux",2008);

        Programma p3 = new Programma("Programma3","Produttore3",1,"Linux",2008);
        Programma p4 = new Programma("Programma4","Produttore4",1,"Linux",2008);

        //setting per c1
        c1.setProgramma(p1, 0);
        c1.setProgramma(p2, 1);

        //setting per c2
        c2.setProgramma(p3, 0); 
        c2.setProgramma(p4, 1);

        //Conta dei programmi presenti
        System.out.println("Numero di programmi presenti in c1: " + c1.getN());
        System.out.println("Numero di programmi presenti in c2: " + c2.getN());
        System.out.println("-----------------------------");

        //Cerca programma per denominazione
        System.out.println("Posizione del programma per denominazione 'Programma2' in c1 : " + c1.cercaProgrammaPerDenominazione("Programma2"));
        System.out.println("Posizione del programma per denominazione 'Programma4' in c2 : " + c2.cercaProgrammaPerDenominazione("Programma4"));
        System.out.println("-----------------------------");

        //Stampa toString
        System.out.println(c1.toString());
        System.out.println("-----");
        System.out.println(c2.toString());
        System.out.println("-----------------------------");

        //Rimuovi programma da c1 e c2
        c1.killProgramma(1);
        System.out.println("Dopo aver rimosso il programma in posizione 1 da c1:");
        System.out.println(c1.toString());
        System.out.println("------");
        c2.killProgramma(1);
        System.out.println("Dopo aver rimosso il programma in posizione 1 da c2:");
        System.out.println(c2.toString());
        System.out.println("-----------------------------");

        c1.setProgramma(p2, 1);
        c2.setProgramma(p2, 1);

        //Confronta contenitori
        System.out.println("Numero di programmi in comune tra i due contenitori: " + c1.confrontaContenitore(c2));
    }
}

