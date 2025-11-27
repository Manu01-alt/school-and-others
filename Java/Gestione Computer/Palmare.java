public class Palmare extends PC_portatili {
    protected boolean bluetooth;
    protected String tipoEspansioneMemoria;

    //constructor
    public Palmare(String processore, int memoria_ram, int memoria_massa, String marca, String modello, String sistemaOperativo, double peso, double altezza, double larghezza, double profondita, double dimensioneVideo, boolean interfacciaReteWireless, boolean bluetooth, String tipoEspansioneMemoria) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo, peso, altezza, larghezza, profondita, dimensioneVideo, interfacciaReteWireless);
        this.bluetooth = bluetooth;
        this.tipoEspansioneMemoria = tipoEspansioneMemoria;
    }

    //Getter
    public boolean isBluetooth() {
        return bluetooth;
    }
    public String getTipoEspansioneMemoria() {
        return tipoEspansioneMemoria;
    }

    //Setter
    public void setBluetooth(boolean bluetooth) {
        this.bluetooth = bluetooth;
    }
    public void setTipoEspansioneMemoria(String tipoEspansioneMemoria) {
        this.tipoEspansioneMemoria = tipoEspansioneMemoria;
    }

    //Method
    public String toString() {
        return "Palmare: " + super.toString() + ", bluetooth=" + bluetooth + ", tipoEspansioneMemoria=" + tipoEspansioneMemoria;
    }

    public boolean equals(Palmare other) {
        return super.equals(other) &&
               this.bluetooth == other.bluetooth &&
               this.tipoEspansioneMemoria.equals(other.tipoEspansioneMemoria);
    }

}
