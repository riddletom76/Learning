//loose vs strict comparison

let age = 24;
console.log(age == '24');
//in the above case javascript tries to convert the string value into number and then 
//evaluates the comparison which results in true
//this is loose  comparison

console.log(age === 24);
console.log(age === '24');
//in the above case javascript tries to check if both the variables have equal value
//and they have the same data type then it evaluates to true
//this is strict comaprison