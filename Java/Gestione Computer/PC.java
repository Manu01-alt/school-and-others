public class PC {
    protected String processore;
    protected int memoria_ram; // in GB
    protected int memoria_massa; // in GB
    protected String marca;
    protected String modello;
    protected String sistemaOperativo;

    //constructor
    public PC(String processore, int memoria_ram, int memoria_massa, String marca, String modello,String sistemaOperativo) {
        this.processore = processore;
        this.memoria_ram = memoria_ram;
        this.memoria_massa = memoria_massa;
        this.marca = marca;
        this.modello = modello;
        this.sistemaOperativo = sistemaOperativo;
    }

    //Getter
    public String getProcessore() {
        return processore;
    }
    public int getMemoriaRam() {
        return memoria_ram;
    }
    public int getMemoriaMassa() {
        return memoria_massa;
    }
    public String getMarca() {
        return marca;
    }
    public String getModello() {
        return modello;
    }
    public String getSistemaOperativo() {
        return sistemaOperativo;
    }

    //Setter
    public void setProcessore(String processore) {
        this.processore = processore;
    }
    public void setMemoriaRam(int memoria_ram) {
        this.memoria_ram = memoria_ram;
    }
    public void setMemoriaMassa(int memoria_massa) {
        this.memoria_massa = memoria_massa;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }
    public void setModello(String modello) {
        this.modello = modello;
    }
    public void setSistemaOperativo(String sistemaOperativo) {
        this.sistemaOperativo = sistemaOperativo;
    }
    
    //Method
    public String toString() {
        return "PC processore=" + processore + ", memoria_ram=" + memoria_ram + ", memoria_massa=" + memoria_massa
                + ", marca=" + marca + ", modello=" + modello + ", sistemaOperativo=" + sistemaOperativo;
    }

    public boolean equals(PC other) {
        return this.processore.equals(other.processore) &&
               this.memoria_ram == other.memoria_ram &&
               this.memoria_massa == other.memoria_massa &&
               this.marca.equals(other.marca) &&
               this.modello.equals(other.modello) &&
               this.sistemaOperativo.equals(other.sistemaOperativo);
    }

}