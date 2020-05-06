//foreach and callback

let people = ['person','person','person','person','person'];
let html = "";
let logPerson = (person, index) => {
    html += (`<li>Hello ${person} - ${index}</li>`);
}

people.forEach(logPerson);

let ul = document.getElementById("list");
ul.innerHTML = html;