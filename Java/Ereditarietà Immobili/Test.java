public class Test {
    public static void main(String[] args) {
        Villa villa1 = new Villa("Roma", "Via Roma 1", 5, 250.0, 2, 100.0, true);
        Villa villa2 = new Villa("Roma", "Via Roma 1", 5, 250.0, 2, 100.0, true);
        Appartamento appartamento1 = new Appartamento("Milano", "Corso Milano 10", 3, 80.0, 5, 2, true);
        Appartamento appartamento2 = new Appartamento("Milano", "Corso Milano 10", 3, 80.0, 5, 2, false);

        System.out.println("Dettagli Villa 1: ");
        System.out.println(villa1.toString());
        System.out.println("Dettagli Appartamento 1: ");
        System.out.println(appartamento1.toString());

        System.out.println("\nVilla 1 uguale a Villa 2? " + villa1.equals(villa2));
        System.out.println("Appartamento 1 uguale a Appartamento 2? " + appartamento1.equals(appartamento2));
    }
}
