document.getElementById("btn_open").addEventListener("click", showPopup);
document.querySelector('.close').addEventListener('click', hidePopup);
function showPopup(){
    var content = document.getElementById("overlay");
    content.style.visibility = "visible";
}

function hidePopup(){
    var content = document.getElementById("overlay");
    content.style.visibility = "hidden";
}