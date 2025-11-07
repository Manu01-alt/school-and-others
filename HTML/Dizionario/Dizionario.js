const italiano = ["cane", "gatto", "casa", "scuola", "libro", "penna", "tavolo", "sedia", "computer", "telefono"];
const inglese = ["dog", "cat", "house", "school", "book", "pen", "table", "chair", "computer", "phone"];

document.getElementById("Traduci").addEventListener("click", translate);

function translate() {

    let inputWord = document.getElementById("wordInput").value.toLowerCase();

    if (italiano.includes(inputWord)) {
        let index = italiano.indexOf(inputWord);
        document.getElementById("translationResult").innerText = "Traduzione in inglese: " + inglese[index];

    } else if (inglese.includes(inputWord)) {
        let index = inglese.indexOf(inputWord);
        document.getElementById("translationResult").innerText = "Traduzione in italiano: " + italiano[index];

    } else {

        document.getElementById("translationResult").innerText = "Parola non trovata nel dizionario.";
    }
}

document.getElementById("MostraTutte").addEventListener("click", showAllWords);

function showAllWords() {
    let table = "<table><tr><th>Italiano</th><th>Inglese</th></tr>";

    for (let i = 0; i < italiano.length; i++) {
        table += "<tr><td>" + italiano[i] + "</td><td>" + inglese[i] + "</td></tr>";
    }
    table += "</table>";

    document.getElementById("allWordsList").innerHTML = table;
}

document.getElementById("AggiungiParola").addEventListener("click", addWord);