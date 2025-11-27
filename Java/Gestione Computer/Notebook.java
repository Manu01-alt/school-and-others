public class Notebook extends PC_portatili{
    protected boolean webcam;
    protected int megapixelCamera;

    //constructor
    public Notebook(String processore, int memoria_ram, int memoria_massa, String marca, String modello, String sistemaOperativo, double peso, double altezza, double larghezza, double profondita, double dimensioneVideo, boolean interfacciaReteWireless, boolean webcam, int megapixelCamera) {
        super(processore, memoria_ram, memoria_massa, marca, modello, sistemaOperativo, peso, altezza, larghezza, profondita, dimensioneVideo, interfacciaReteWireless);
        this.webcam = webcam;
        if (webcam) {
            this.megapixelCamera = megapixelCamera;
        } else {
            this.megapixelCamera = 0; // No camera
        }
    }

    //Getter
    public boolean isWebcam() {
        return webcam;
    }
    public int getMegapixelCamera() {
        return megapixelCamera;
    }

    //Setter
    public void setWebcam(boolean webcam) {
        this.webcam = webcam;
        if (!webcam) {
            this.megapixelCamera = 0; // No camera
        }
    }

    //Method
    public String toString() {
        return "Notebook: " + super.toString() + ", webcam=" + webcam + ", megapixelCamera=" + megapixelCamera;
    }

    public boolean equals(Notebook other) {
        return super.equals(other) &&
               this.webcam == other.webcam &&
               this.megapixelCamera == other.megapixelCamera;
    }
    
}
