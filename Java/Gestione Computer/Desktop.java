public class Desktop extends PC_fisso {
    protected String tipoSchedaVideo;
    protected String tipoSchedaAuio;

    //constructor
    public Desktop(String processore, int memoria_ram, int memoria_massa, String marca, String modello, String sistemaOperativo, String tipoCase, String tipoSchedaVideo, String tipoSchedaAuio) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo, tipoCase);
        this.tipoSchedaVideo = tipoSchedaVideo;
        this.tipoSchedaAuio = tipoSchedaAuio;
    }

    //Getter
    public String getTipoSchedaVideo() {
        return tipoSchedaVideo;
    }
    public String getTipoSchedaAuio() {
        return tipoSchedaAuio;
    }
    //Setter
    public void setTipoSchedaVideo(String tipoSchedaVideo) {
        this.tipoSchedaVideo = tipoSchedaVideo;
    }
    public void setTipoSchedaAuio(String tipoSchedaAuio) {
        this.tipoSchedaAuio = tipoSchedaAuio;
    }

    //Method
    public String toString() {
        return "Desktop: " + super.toString() + ", tipoSchedaVideo=" + tipoSchedaVideo + ", tipoSchedaAuio=" + tipoSchedaAuio;
    }

    public boolean equals(Desktop other) {
        return super.equals(other) &&
               this.tipoSchedaVideo.equals(other.tipoSchedaVideo) &&
               this.tipoSchedaAuio.equals(other.tipoSchedaAuio);
    }
}
