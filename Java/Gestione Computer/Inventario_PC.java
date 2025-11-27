import java.util.ArrayList;

public class Inventario_PC {
    private ArrayList<PC> inventario;

    public Inventario_PC() {
        this.inventario = new ArrayList<>();
    }

    /**
     * Aggiunge un PC all'inventario
     * @param pc , il PC da aggiungere
     */
    public void aggiungiPC(PC pc) {
        inventario.add(pc);
    }

    /**
     * Rimuove un PC dall'inventario
     * @param pc , il PC da rimuovere
     * @return true se il PC è stato rimosso, false altrimenti
     */
    public boolean rimuoviPC(PC pc) {
        if (inventario.contains(pc)) {
            inventario.remove(pc);
            return true;
        }
        return false;
    }


    /**
     * Cerca PC per marca
     * @param marca , la marca da cercare
     * @return ArrayList di PC che corrispondono alla marca cercata
     */
    public ArrayList<PC> cercaPerMarca (String marca) {
        ArrayList<PC> risultati = new ArrayList<>();
        for (PC pc : inventario) {
            if (pc.getMarca().equalsIgnoreCase(marca)) {
                risultati.add(pc);
            }
        }
        return risultati;
    }


    /**
     * Cerca PC per sistema operativo
     * @param sistemaOperativo , il sistema operativo da cercare
     * @return ArrayList di PC che corrispondono al sistema operativo cercato
     */
    public ArrayList<PC> cercaPerSistemaOperativo (String sistemaOperativo) {
        ArrayList<PC> risultati = new ArrayList<>();
        for (PC pc : inventario) {
            if (pc.getSistemaOperativo().equalsIgnoreCase(sistemaOperativo)) {
                risultati.add(pc);
            }
        }
        return risultati;
    }

    /**
     * Trova il PC con più RAM
     * @return PC con più RAM
     */
    public PC trovaPCconPiuRam() {
        PC temp = null;
        PC pc = new PC(null, 0, 0, null, null, null);
        for (int i = 0; i < inventario.size(); i++) {
            temp = inventario.get(i);
            if (temp.getMemoriaRam() > pc.getMemoriaRam()) {
                pc = temp;
            }
        }
        return pc;
    }

    /**
     * Calcola la media della RAM dei PC nell'inventario
     * @return media della RAM
     */
    public double calcolaMediaRAM() {
        int somma = 0;

        if (inventario.isEmpty())
            return 0;

        for(int i = 0; i < inventario.size(); i++) {
            somma += inventario.get(i).getMemoriaRam();
        }

        return somma / inventario.size();
    }

    /**
     * Conta i portatili con interfaccia di rete wireless
     * @return numero di portatili con interfaccia di rete wireless
     */
    public int contaPortatiliConWifi() {
        int c = 0;
        for (int i = 0; i < inventario.size(); i++) {
            if (inventario.get(i) instanceof PC_portatili) {
                PC_portatili portatile = (PC_portatili) inventario.get(i);
                if (portatile.isInterfacciaReteWireless()) {
                    c++;
                }
            }
        }
        return c;
    }

    /**
     * Conta i server con dischi RAID
     * @return numero di server con dischi RAID
     */
    public int contaServerConRaid() {
        int c = 0;
        for (int i = 0; i < inventario.size(); i++) {
            if (inventario.get(i) instanceof Server) {
                Server server = (Server) inventario.get(i);
                if (server.isDischiRAID()) {
                    c++;
                }
            }
        }
        return c;
    }

    /**
     * Trova il notebook più leggero
     * @return notebook più leggero
     */
    Notebook trovaNotebookPiuLeggero() {
        Notebook temp = null;
        Notebook notebook = null;
        for (int i = 0; i < inventario.size(); i++) {
            if (inventario.get(i) instanceof Notebook) {
                temp = (Notebook) inventario.get(i);
                if (notebook == null || temp.getPeso() < notebook.getPeso()) {
                    notebook = temp;
                }
            }
        }
        return notebook;
    }

    /**
     * Cerca portatili in base a peso massimo e presenza di wifi
     * @param pesoMassimo , il peso massimo
     * @param richiedeWifi , se richiede la presenza di wifi
     * @return
     */
    public ArrayList<PC> cercaPortabili(double pesoMassimo, boolean richiedeWifi) {
        ArrayList<PC> risultati = new ArrayList<>();
        for (PC pc : inventario) {
            if (pc instanceof PC_portatili) {
                PC_portatili portatile = (PC_portatili) pc;
                if (portatile.isInterfacciaReteWireless())
                    if (portatile.getPeso() <= pesoMassimo) 
                        risultati.add(portatile);
            }
        }
        return risultati;
    }
}

