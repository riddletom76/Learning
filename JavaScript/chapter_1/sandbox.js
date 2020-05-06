//objects and methods
let obj = {
    name: "Rishabh",
    email: "rishabhgsharma95@gmail.com",
    login: function(){
        console.log("rishabh logged in");
    },
    logout(){
        console.log("rishabh logged out");
    },
    methodForThis(){
        console.log(this.name);
    }
};

console.log(obj);
console.log(obj.login());
console.log(obj.logout());
console.log(obj.methodForThis());

//important points 
//this does not work with arrow functions hence the above are the two variations in which the methods
//can be written in order to use this as well;