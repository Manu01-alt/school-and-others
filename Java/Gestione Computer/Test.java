public class Test {
    public static void main(String[] args) {
        
        Inventario_PC inventario = new Inventario_PC();

        
        Desktop desktop1 = new Desktop("Intel i7", 16, 1000, "Dell", "OptiPlex", "Windows 10", "MidTower", "NVIDIA", "Realtek");
        Server server1 = new Server("Intel Xeon", 64, 4000, "HP", "ProLiant", "Linux", "Rack", 2, true);
        Notebook notebook1 = new Notebook("Intel i5", 8, 512, "Asus", "ZenBook", "Windows 10", 1.2, 1.5, 30.0, 20.0, 13.3, true, true, 1);
        Notebook notebook2 = new Notebook("AMD Ryzen 5", 12, 256, "Lenovo", "IdeaPad", "Windows 11", 1.4, 1.6, 32.0, 22.0, 14.0, false, false, 0);
        Palmare palmare1 = new Palmare("ARM Cortex", 2, 64, "Samsung", "GalaxyTab", "Android", 0.5, 0.7, 10.0, 0.8, 10.1, true, true, "microSD");

       
        inventario.aggiungiPC(desktop1);
        inventario.aggiungiPC(server1);
        inventario.aggiungiPC(notebook1);
        inventario.aggiungiPC(notebook2);
        inventario.aggiungiPC(palmare1);

        
        System.out.println("--- Inventario completo ---");

        
        PC piuRam = inventario.trovaPCconPiuRam();
        System.out.println("PC con più RAM: " + (piuRam != null ? piuRam.toString() : "nessuno"));

        
        double mediaRam = inventario.calcolaMediaRAM();
        System.out.println("Media RAM: " + mediaRam + " GB");

        
        int portatiliConWifi = inventario.contaPortatiliConWifi();
        System.out.println("Portatili con Wi-Fi: " + portatiliConWifi);

        
        int serverConRaid = inventario.contaServerConRaid();
        System.out.println("Server con dischi RAID: " + serverConRaid);

        
        Notebook notebookLeggero = inventario.trovaNotebookPiuLeggero();
        System.out.println("Notebook più leggero: " + notebookLeggero);

        
        System.out.println("\n--- Ricerche ---");

        System.out.println("PC marca 'Asus':");
        for (PC pc : inventario.cercaPerMarca("Asus")) {
            System.out.println(pc);
        }

        System.out.println("\nPC con sistema operativo 'Windows 10':");
        for (PC pc : inventario.cercaPerSistemaOperativo("Windows 10")) {
            System.out.println(pc);
        }

        System.out.println("\nPortatili sotto peso 1.3 kg con Wi-Fi:");
        for (PC pc : inventario.cercaPortabili(1.3, true)) {
            System.out.println(pc);
        }

        System.out.println("\nPortatili sotto peso 1.5 kg senza richiedere Wi-Fi (inclusi con o senza):");
        for (PC pc : inventario.cercaPortabili(1.5, false)) {
            System.out.println(pc);
        }

        // dimostrare rimozione
        boolean rimosso = inventario.rimuoviPC(palmare1);
        System.out.println("\nRimozione palmare1 riuscita: " + rimosso);
        System.out.println("Portatili con Wi-Fi dopo rimozione: " + inventario.contaPortatiliConWifi());
    }
}
