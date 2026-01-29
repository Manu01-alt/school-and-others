public class Stampante implements Dispostivo{
    @Override
    public void accendi() {
        System.out.println("Dispostivio acceso!");
    }

    @Override
    public void spegni() {
        System.out.println("Dispositivo spento!");
    }
}