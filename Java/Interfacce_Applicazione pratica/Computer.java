public class Computer implements Dispostivo{
    @Override
    public void accendi() {
        System.out.println("Dispostivio acceso!");
    }

    @Override
    public void spegni() {
        System.out.println("Dispositivo spento!");
    }

    public void connettiti() {
        System.out.println("Connesso!");
    }
}
