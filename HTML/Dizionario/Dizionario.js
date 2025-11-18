// Array con le parole italiane del dizionario
const italiano = ["cane", "gatto", "casa", "scuola", "libro", "penna", "tavolo", "sedia", "computer", "telefono"];
// Array con le corrispondenti traduzioni in inglese (stesso indice di 'italiano')
const inglese = ["dog", "cat", "house", "school", "book", "pen", "table", "chair", "computer", "phone"];

// Aggiunge un listener al pulsante 'Traduci' che chiama la funzione translate quando si clicca
document.getElementById("Traduci").addEventListener("click", translate);
document.getElementById("wordInput").addEventListener("change", translate);

// Definizione della funzione che esegue la traduzione
function translate() {

    // Legge il valore inserito nell'input e lo converte in minuscolo
    let inputWord = document.getElementById("wordInput").value.toLowerCase();

    // Se la parola è presente nell'array italiano, trova l'indice e mostra la traduzione inglese
    if (italiano.includes(inputWord)) {
        let index = italiano.indexOf(inputWord);
        document.getElementById("translationResult").innerText = "Traduzione in inglese: " + inglese[index];

    // Altrimenti, se la parola è presente nell'array inglese, mostra la traduzione italiana
    } else if (inglese.includes(inputWord)) {
        let index = inglese.indexOf(inputWord);
        document.getElementById("translationResult").innerText = "Traduzione in italiano: " + italiano[index];

    // Se non è trovata in nessuno dei due array, mostra un messaggio di errore
    } else {
        document.getElementById("translationResult").innerText = "Parola non trovata nel dizionario.";
    }
}

// Aggiunge un listener al pulsante 'MostraTutte' che chiama showAllWords quando si clicca
document.getElementById("MostraTutte").addEventListener("click", showAllWords);

// Funzione che crea una tabella HTML con tutte le parole del dizionario
function showAllWords() {
    // Inizia la stringa HTML della tabella con l'intestazione
    let table = "<table><tr><th>Italiano</th><th>Inglese</th></tr>";

    // Cicla su tutti gli elementi dell'array italiano e aggiunge una riga per ognuno
    for (let i = 0; i < italiano.length; i++) {
        table += "<tr><td>" + italiano[i] + "</td><td>" + inglese[i] + "</td></tr>";
    }
    // Chiude la tabella
    table += "</table>";

    // Inserisce la tabella nel container dedicato nella pagina
    document.getElementById("allWordsList").innerHTML = table;
}

// Listener per il pulsante 'AggiungiParola' (se presente nel DOM) -> avvia addWord
document.getElementById("AggiungiParola").addEventListener("click", addWord);

// Funzione che aggiunge una nuova coppia di parole agli array
function addWord() {
    // Legge i valori dagli input per la nuova parola italiana e inglese
    let newItalianWord = document.getElementById("newItalianWord").value.toLowerCase();
    let newEnglishWord = document.getElementById("newEnglishWord").value.toLowerCase();

    // Se entrambi i campi sono compilati, aggiunge le parole agli array
    if (newItalianWord && newEnglishWord) {
        italiano.push(newItalianWord);
        inglese.push(newEnglishWord);
        // Notifica l'utente che l'aggiunta è andata a buon fine
        alert("Parola aggiunta con successo!");

        // Pulisce i campi di input
        document.getElementById("newItalianWord").value = "";
        document.getElementById("newEnglishWord").value = "";
    } else {
        // Mostra un messaggio se uno dei campi è vuoto
        alert("Per favore, inserisci entrambe le parole.");
    }
}