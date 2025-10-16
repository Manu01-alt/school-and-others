function handleButton(n){
    let number = parseInt(document.getElementById("text-box").value) || 0
    number += n
    document.getElementById("text-box").value = number
}
