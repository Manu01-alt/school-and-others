const cittaPerRegione = {
  "Abruzzo": ["L'Aquila", "Pescara", "Chieti", "Teramo", "Sulmona", "Avezzano", "Vasto"],
  "Basilicata": ["Potenza", "Matera", "Pisticci", "Melfi", "Lauria"],
  "Calabria": ["Catanzaro", "Reggio Calabria", "Cosenza", "Crotone", "Vibo Valentia", "Lamezia Terme"],
  "Campania": ["Napoli", "Salerno", "Caserta", "Benevento", "Avellino", "Torre del Greco", "Giugliano"],
  "Emilia-Romagna": ["Bologna", "Modena", "Parma", "Reggio Emilia", "Rimini", "Ferrara", "Ravenna", "Forlì"],
  "Friuli-Venezia Giulia": ["Trieste", "Udine", "Pordenone", "Gorizia", "Monfalcone"],
  "Lazio": ["Roma", "Latina", "Frosinone", "Viterbo", "Rieti", "Guidonia", "Civitavecchia"],
  "Liguria": ["Genova", "La Spezia", "Savona", "Imperia", "Rapallo", "Sanremo"],
  "Lombardia": ["Milano", "Brescia", "Monza", "Bergamo", "Como", "Varese", "Cremona", "Mantova"],
  "Marche": ["Ancona", "Pesaro", "Fermo", "Macerata", "Ascoli Piceno", "Civitanova Marche"],
  "Molise": ["Campobasso", "Isernia", "Termoli", "Venafro", "Bojano"],
  "Piemonte": ["Torino", "Novara", "Alessandria", "Asti", "Cuneo", "Biella", "Vercelli"],
  "Puglia": ["Bari", "Lecce", "Foggia", "Taranto", "Brindisi", "Andria", "Barletta"],
  "Sardegna": ["Cagliari", "Sassari", "Nuoro", "Oristano", "Olbia", "Alghero", "Porto Torres"],
  "Sicilia": ["Palermo", "Catania", "Messina", "Siracusa", "Trapani", "Caltanissetta", "Agrigento"],
  "Toscana": ["Firenze", "Prato", "Livorno", "Arezzo", "Pisa", "Siena", "Lucca", "Grosseto"],
  "Trentino-Alto Adige": ["Trento", "Bolzano", "Rovereto", "Merano", "Bressanone"],
  "Umbria": ["Perugia", "Terni", "Foligno", "Città di Castello", "Spoleto", "Gubbio"],
  "Valle d'Aosta": ["Aosta", "Saint-Vincent", "Châtillon", "Sarre", "Pont-Saint-Martin"],
  "Veneto": ["Venezia", "Verona", "Padova", "Vicenza", "Treviso", "Rovigo", "Belluno"]
};

function aggiornaProvince() {
  
    const Regione = document.getElementById("Regioni").value;
    const province = cittaPerRegione[Regione];
    let options = "";
    for (let i = 0; i < province.length; i++) {
        options += `<option>${province[i]}</option>`;
      }
      document.getElementById("Province").innerHTML = options;
}
   
document.getElementById("Regioni").addEventListener("change", aggiornaProvince);


