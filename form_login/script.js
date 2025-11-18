let datas = [
    {Username: "codeMaster7", Password: "C0d3_1sL1fe!", Ruolo: "regular"},
    {Username: "luna_traveler", Password: "M00n_W@lk3r", Ruolo: "Administrator"},
    {Username: "pixel_wizard", Password: "M@g1c_P1x3l", Ruolo: "regular"},
    {Username: "river_flow", Password: "Fl0w1ng_W@t3r", Ruolo: "regular"}
]

function log(){
    let userInput =  {Username: "", Password: ""};
    let nome = document.getElementById("username").value
    let pass = document.getElementById("password").value

    let success;
    for (let i = 0; i < datas.length; i++){
        if (datas[i]["Username"] == nome && datas[i]["Password"] == pass){
            localStorage.setItem('userRole', datas[i].Ruolo)
            localStorage.setItem('username', datas[i].Username)

            window.location.href = "correct_login.html"
            return
        }
    }
    document.getElementById("incorrect").innerText = "access denied!"
}