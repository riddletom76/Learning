//function declaration
function greet(){
    console.log('Hello, there!');
}

//function expression   
let speak = function(){
    console.log('Hello, this is function expression');
}

greet();
// greet();
greet();
speak();
speak();
speak();

//the difference between function declaration and function expression 
// in case of function declaration the javascript performs hoisting by which it
// puts the function on top 
//in case of function expression hoisting is not supported hence, 
//if we declare a function expression below the function invokation it'll result in an error
