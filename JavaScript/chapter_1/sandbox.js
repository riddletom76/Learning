//type conversion
//converting one data type into another
let score = "100";
console.log(typeof score);
console.log(score + 1);

score = Number(score);
console.log(score + 1);

console.log(typeof score);

let result = Boolean(0);
console.log(result);
//zero are falsy values
console.log(Boolean(-1));
//any other number than 0 is a truthy value
console.log(Boolean('0'));
//any string is a truthy value
console.log(Boolean(''));
//empty strings are falsy values
