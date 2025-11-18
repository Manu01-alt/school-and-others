const userRole = localStorage.getItem("userRole")
const username = localStorage.getItem("username")

document.getElementById("msg").innerText =  `Welcome, ${username}! Your role is: ${userRole}`
