let newArray = ['rishabh', 'sharma', 'noob'];

let result = newArray.join(',');
console.log(result);
result = newArray.indexOf('sharma');
console.log(result);
result = newArray.concat('hello');
console.log({result});
console.log({newArray});

result = newArray.push('world');
console.log({result});
console.log({newArray});
result = newArray.pop();
console.log({result});
console.log({newArray});

//push and pop are also called destructive functions for array
//the destructive functions change the actual object on which they are working on
//if you see concat it only concatenated and stores the result of concat operation in result
//in case of push the newArray itself gets updated.
