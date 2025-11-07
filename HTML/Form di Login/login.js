const validUsers = ['user1', 'user2', 'admin'];
const validPasswords = ['a722c63db8ec8625af6cf71cb8c2d939', 'c1572d05424d0ecb2a65ec6a82aeacbf', '25e4ee4e9229397b6b17776bfceaf8e7']; //pass1, pass2, adminpass
const userRoles = ['user', 'user', 'admin'];

function fromMD5(password) {
    return CryptoJS.MD5(password).toString();
}

function handleLogin() {
    
    let username = document.getElementById('username').value;
    let password = fromMD5(document.getElementById('password').value);
    
    let userIndex = validUsers.indexOf(username);
    if (userIndex != -1 && validPasswords[userIndex] == password) {
       
        document.getElementById("messaggio").innerText = "Benvenuto " +  username + "!\n Ruolo: " + userRoles[userIndex];

    } else {
        document.getElementById("messaggio").innerText = "credenziali errate!";
    }
}