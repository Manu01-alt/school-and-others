let tabellone = [];
let annunciEffettuati = {
    ambo: false,
    terna: false,
    quaterna: false,
    cinquina: false,
    tombola: false
};

const scritteItaliane = [
  "L'Italia", "Il bimbo", "Il gatto", "Il maiale", "La mano",
  "Quella che guarda per terra", "Il vaso da notte", "La madonna", "La prole", "I fagioli",
  "I topi", "I soldati", "Sant'Antonio", "L'ubriaco", "Il ragazzo",
  "Il deretano", "La disgrazia", "Il sangue", "La risata", "La festa",
  "La donna nuda", "Il pazzo", "Lo scemo", "Le guardie", "Natale",
  "Piccola Anna", "Il pitale", "Il seno", "Il padre dei bambini", "Le palle del tenente",
  "Il proprietario di casa", "Il capitone", "Gli anni di Cristo", "La testa", "L'uccellino",
  "Le nacchere", "Il frate", "Le botte", "La corda al collo", "La noia",
  "Il coltello", "Il caffè", "La donna al balcone", "Il carcere", "Il vino",
  "I denari", "Il morto", "Il morto che parla", "Il pezzo di carne", "Il pane",
  "Il giardino", "La mamma", "Il vecchio", "Il cappello", "La musica",
  "La caduta", "Il gobbo", "Il regalo", "I peli", "Si lamenta",
  "Il cacciatore", "Il morto ammazzato", "La sposa", "La marsina", "Il pianto",
  "Le due zitelle", "Il totano nella chitarra", "La zuppa cotta", "Sottosopra", "Il palazzo",
  "L'uomo di merda", "La meraviglia", "L'ospedale", "La grotta", "Pulcinella",
  "La fontana", "I diavoli", "La bella ragazza", "Il ladro", "La bocca",
  "I fiori", "La tavola imbandita", "Il maltempo", "La chiesa", "Le anime del purgatorio",
  "Il negozio", "I pidocchi", "I caciocavalli", "La vecchia", "La paura"
];

const scritteNapoletane = [
  "L'Italia", "'A criatura", "'A jatta", "'O puorco", "'A mano",
  "Chella che guarda 'nterra", "'O' vasett", "'A maronna", "'A figliata", "'E fasule",
  "'E surice", "'E surdate", "Sant'Antonio", "'O mbriaco", "'O guaglione",
  "'O culo", "'A disgrazia", "'O sanghe", "'A resata", "'A festa",
  "'A femmena annura", "'O pazzo", "'O scemo", "'E gguardie", "Natale",
  "Nanninella", "'O cantero", "'E zzizze", "'O pate d''e criature", "'E palle d''o tenente",
  "'O padrone 'e casa", "'O capitone", "Ll'anne 'e Cristo", "'A capa", "L'aucielluzzo",
  "'E castagnelle", "'O monaco", "'E mmazzate", "'A funa 'nganna", "'A paposcia",
  "'O curtiello", "'O ccafè", "'A femmena 'ncopp''o balcone", "'E ccancelle", "'O vino",
  "'E denare", "'O muorto", "'O muorto che parla", "'O piezzo 'e carne", "'O ppane",
  "'O ciardino", "'A mamma", "'O viecchio", "'O cappiello", "'A museca",
  "'A caruta", "'O scartellato", "'O paccotto", "'E pile", "Se lamenta",
  "'O cacciatore", "'O muorto acciso", "'A sposa", "'A sciammeria", "'O chianto",
  "'E ddoie zetelle", "'O totano int''a chitarra", "'A zuppa cotta", "Sott' e 'ncoppo", "'O palazzo",
  "L'ommo 'e merda", "'A meraviglia", "'O spitale", "'A rotta", "Pullecenella",
  "'A funtana", "'E diavule", "'A bella figliola", "'O mariuolo", "'A vocca",
  "'E sciure", "'A tavula 'mbandita", "'O maletiempo", "'A cchiesa", "Ll'aneme 'o priatorio",
  "'A puteca", "'E perucchie", "'E casecavalle", "'A vecchia", "'A paura"
];

// Crea il tabellone
for(let i = 1; i <= 90; i++) {
    let cell = document.createElement("div");
    cell.textContent = i;
    cell.id = "cell-" + i;
    cell.className = "cella";
    document.getElementById("tabella").appendChild(cell);
}

function estrai(){
    let n;  
    if (tabellone.length >= 90) {
        alert("il panarello è vuoto");
        return null;
    }
    else{
        n = Math.floor(Math.random() * 90) + 1;
        while (tabellone.includes(n)) {
            n = Math.floor(Math.random() * 90) + 1;
        }   
    }
    return n;
}

function print_number(){
    let Number = estrai();
    if (Number === null) return;

    document.getElementById("mostraNumero").innerText = Number;
    tabellone.push(Number);

    document.getElementById("ScrittaNapoletana").innerText = scritteNapoletane[Number - 1];
    document.getElementById("ScrittaItaliana").innerText = scritteItaliane[Number - 1];

    let CellaUscita = document.getElementById("cell-" + Number);
    if (CellaUscita) {
        CellaUscita.className = "cella-estratta";
    }
    
    verificaNumeriCartelle();
}

function reset_table(){ 
    document.getElementById("mostraNumero").innerText = "";
    tabellone = [];
    annunciEffettuati = {
        ambo: false,
        terna: false,
        quaterna: false,
        cinquina: false,
        tombola: false
    };
    document.getElementById("ScrittaNapoletana").innerText = "";
    document.getElementById("ScrittaItaliana").innerText = "";
    
    for(let i = 1; i <= 90; i++) {
        let cell = document.getElementById("cell-" + i);
        if (cell) {
            cell.className = "cella";
        }
    }
    
    
    let cartelle = document.getElementsByClassName('cartella');
    for(let i = 0; i < cartelle.length; i++) {
        let celle = cartelle[i].getElementsByClassName('cartella-cella');
        for(let j = 0; j < celle.length; j++) {
            if(celle[j].dataset.numero) {
                celle[j].className = 'cartella-cella';
            }
        }
    }
}

function generaCartella() {
    const cartella = [];
    
    for(let riga = 0; riga < 3; riga++) {
        const numeriRiga = [];
        const colonneUsate = [];
        
        while(colonneUsate.length < 5) {
            let col = Math.floor(Math.random() * 9);
            if(!colonneUsate.includes(col)) {
                colonneUsate.push(col);
            }
        }
        colonneUsate.sort(function(a, b) { return a - b; });
        
        for(let col = 0; col < 9; col++) {
            if(colonneUsate.includes(col)) {
                let min, max;
                if(col === 0) {
                    min = 1;
                    max = 9;
                } else if(col === 8) {
                    min = 80;
                    max = 90;
                } else {
                    min = col * 10;
                    max = col * 10 + 9;
                }
                
                let numero;
                let trovato = false;
                do {
                    numero = Math.floor(Math.random() * (max - min + 1)) + min;
                    trovato = false;
                    for(let r = 0; r < cartella.length; r++) {
                        if(cartella[r][col] === numero) {
                            trovato = true;
                            break;
                        }
                    }
                } while(trovato);
                
                numeriRiga[col] = numero;
            } else {
                numeriRiga[col] = null;
            }
        }
        
        cartella.push(numeriRiga);
    }
    
    return cartella;
}

let container = document.getElementById('cartelle');
container.innerHTML = '';
    
for(let i = 0; i < 8; i++) {
    let cartella = generaCartella();
    let cartellaDiv = document.createElement('div');
    cartellaDiv.className = 'cartella';
        
    for(let riga = 0; riga < 3; riga++) {
        for(let col = 0; col < 9; col++) {
            let cella = document.createElement('div');
            cella.className = 'cartella-cella';
            let numero = cartella[riga][col];
                
            if(numero !== null) {
                cella.textContent = numero;
                cella.dataset.numero = numero;
            }
                
            cartellaDiv.appendChild(cella);
        }
    }
        
    container.appendChild(cartellaDiv);
    }



function verificaNumeriCartelle() {
    let maxNumeriPerRiga = 0;
    let maxNumeriPerCartella = 0;
    
    let cartelle = document.getElementsByClassName('cartella');
    for(let i = 0; i < cartelle.length; i++) {
        let celle = cartelle[i].getElementsByClassName('cartella-cella');
        let numeriCartellaEstratti = 0;
        
        for(let riga = 0; riga < 3; riga++) {
            let numeriRigaEstratti = 0;
            
            for(let col = 0; col < 9; col++) {
                let cella = celle[riga * 9 + col];
                let numero = parseInt(cella.dataset.numero);
                
                if(numero && tabellone.includes(numero)) {
                    cella.className = 'cartella-cella cartella-cella-estratta';
                    numeriRigaEstratti++;
                    numeriCartellaEstratti++;
                }
            }
            
            if(numeriRigaEstratti > maxNumeriPerRiga) {
                maxNumeriPerRiga = numeriRigaEstratti;
            }
        }
        
        if(numeriCartellaEstratti > maxNumeriPerCartella) {
            maxNumeriPerCartella = numeriCartellaEstratti;
        }
    }
    
    
    if(maxNumeriPerCartella === 15 && !annunciEffettuati.tombola) {
        annunciEffettuati.tombola = true;
        alert("🎉 TOMBOLA! 🎉")
    }
    if(maxNumeriPerRiga === 5 && !annunciEffettuati.cinquina) {
        annunciEffettuati.cinquina = true;
        alert("🎊 CINQUINA! 🎊")
    } if(maxNumeriPerRiga === 4 && !annunciEffettuati.quaterna) {
        annunciEffettuati.quaterna = true;
        alert("🎯 QUATERNA! 🎯")
    } if(maxNumeriPerRiga === 3 && !annunciEffettuati.terna) {
        annunciEffettuati.terna = true;
        alert("🎪 TERNA! 🎪")
    } if(maxNumeriPerRiga === 2 && !annunciEffettuati.ambo) {
        annunciEffettuati.ambo = true;
        alert("🎲 AMBO! 🎲")
    }
}

document.getElementById("estrai").addEventListener('click', print_number);
document.getElementById("reset").addEventListener('click', reset_table);