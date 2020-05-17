//what is DOM?
//QuerySelector?
//use a queryselector to insert an unordered list in the html page
//getting and setting attributes of a tag
//use the queryselector to set a class which will have an associated css attribute set
//add and remove classes

let bodyElement = document.querySelector('#list');
console.log(bodyElement);
let list = document.createElement('ul');
let item = document.createElement('li');
item.innerHTML = "first item";
list.appendChild(item);
document.getElementById('list').appendChild(list);
bodyElement.setAttribute("class", 'rishabh')
console.log(bodyElement.getAttribute('class'))
let classList = document.getElementById('list').classList;
classList.add('sharma');
console.log(bodyElement.getAttribute('class'))