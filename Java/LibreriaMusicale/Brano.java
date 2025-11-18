import java.time.LocalDate;

public class Brano {
    String titolo;
    String artista;
    String genere;
    int durataSec;
    LocalDate dataUscita;
    int ascolti;

    //costruttori
    public Brano(String titolo, String artista, String genere, int durataSec, LocalDate dataUscita, int ascolti) {
        this.titolo = titolo;
        this.artista = artista;
        this.genere = genere;
        this.durataSec = durataSec;
        this.dataUscita = dataUscita;
        this.ascolti = ascolti;
    }

    public Brano() {
    
        this.titolo = "Sconosciuto";
        this.artista = "Sconosciuto";
        this.genere = "Sconosciuto";
        this.durataSec = 0;
        this.dataUscita = LocalDate.now();
        this.ascolti = 0;
    
    }

    //getter
    public String getTitolo() {
        return titolo;
    }
    public String getArtista() {
        return artista;
    }
    public String getGenere() {
        return genere;
    }
    public int getDurataSec() {
        return durataSec;
    }
    public LocalDate getDataUscita() {
        return dataUscita;
    }
    public int getAscolti() {
        return ascolti;
    }

    //setter
    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }
    public void setArtista(String artista) {
        this.artista = artista;
    }
    public void setGenere(String genere) {
        this.genere = genere;
    }
    public void setDurataSec(int durataSec) {
        this.durataSec = durataSec;
    }
    public void setDataUscita(LocalDate dataUscita) {
        this.dataUscita = dataUscita;
    }
    public void setAscolti(int ascolti) {
        this.ascolti = ascolti;
    }

    //methods
    public void incrementaAscolti() {
        this.ascolti++;
    }
    
    public String toString() {
        return "Titolo: " + titolo + ", Artista: " + artista + ", Genere: " + genere + ", Durata (sec): " + durataSec + ", Data Uscita: " + dataUscita + ", Ascolti: " + ascolti;
    }
    

    
}