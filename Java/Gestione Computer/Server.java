public class Server extends PC_fisso {
    protected int numeroProcessori;
    protected boolean dischiRAID;

    //constructor
    public Server(String processore, int memoria_ram, int memoria_massa, String marca, String modello, String sistemaOperativo, String tipoCase, int numeroProcessori, boolean dischiRAID) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo, tipoCase);
        this.numeroProcessori = numeroProcessori;
        this.dischiRAID = dischiRAID;
    }

    //Getter
    public int getNumeroProcessori() {
        return numeroProcessori;
    }
    public boolean isDischiRAID() {
        return dischiRAID;
    }

    //Setter
    public void setNumeroProcessori(int numeroProcessori) {
        this.numeroProcessori = numeroProcessori;
    }
    public void setDischiRAID(boolean dischiRAID) {
        this.dischiRAID = dischiRAID;
    }

    //Method
    public String toString() {
        return "Server: " + super.toString() + ", numeroProcessori=" + numeroProcessori + ", dischiRAID=" + dischiRAID;
    }

    public boolean equals(Server other) {
        return super.equals(other) &&
               this.numeroProcessori == other.numeroProcessori &&
               this.dischiRAID == other.dischiRAID;
    }
}
