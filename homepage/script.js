document.addEventListener('DOMContentLoaded', function() {
   let flex = document.querySelector(".flex");
    let user = document.getElementById("name1").value;
    let submit = document.getElementById("submit");
    let btn = document.getElementById("btn");
    submit.addEventListener("click" , function() {
    let result = document.getElementById("result");
    result.innerHTML = "Albenis.kerqelis";
    result.style.width = "100%";
    result.style.minHeight = "40px";
    result.style.opacity = "1";
    result.innerHTML=(`wow your name is ${user}`);
    })
});
