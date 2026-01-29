public class MezzoDiSoccorso implements Volante, Motorizzato, Trasportatore, Navigabile {
    private double capacità;

    public MezzoDiSoccorso(double capacità) {
        this.capacità = capacità;
    }

    //getters
    public double getCapacità() {
        return capacità;
    }

    //setters
    public void setCapacità(double capacità) {
        this.capacità = capacità;
    }

    //methods
    @Override
    public boolean vola() {
        return true;
    }

    @Override
    public boolean hasMotore() {
        return true;
    }

    @Override
    public boolean trasporta() {
        return true;
    }

    @Override
    public boolean nuoto() {
        return true;
    }
}
