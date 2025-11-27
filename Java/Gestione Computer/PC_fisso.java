public class PC_fisso extends PC {
    protected String tipoCase;

    //constructor
    public PC_fisso(String processore, int memoria_ram, int memoria_massa, String marca, String modello,String sistemaOperativo, String tipoCase) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo);
        this.tipoCase = tipoCase;
    }

    //Getter
    public String getTipoCase() {
        return tipoCase;
    }

    //Setter
    public void setTipoCase(String tipoCase) {
        this.tipoCase = tipoCase;
    }

    //Method
    public String toString() {
        return "PC_fisso: " + super.toString() + ", tipoCase=" + tipoCase;
    }

    public boolean equals(PC_fisso other) {
        return super.equals(other) && this.tipoCase.equals(other.tipoCase);
    }
}
