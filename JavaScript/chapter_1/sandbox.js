let email = "rishabhgsharma95@gmail.com";
let result = email.slice(0,5);
console.log(result);
result = email.slice(2,5);
console.log(result);

//the first index in slice  determines the starting point 
//the second index shows the end point till where the slice should happen, which means excluding
//the element which is present at that index.