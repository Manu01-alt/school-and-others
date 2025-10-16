function handleButton(){
    let number = parseInt(document.getElementById("text-box").value) || 0
    let n = parseInt(document.getElementById("increment-box").value) || 1
    number += n
    document.getElementById("text-box").value = number
}

function handleButton_dec(){
    let number = parseInt(document.getElementById("text-box").value) || 0
    let n = parseInt(document.getElementById("increment-box").value) || 1
    number -= n
    document.getElementById("text-box").value = number
}