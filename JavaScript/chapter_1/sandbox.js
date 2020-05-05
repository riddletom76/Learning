//foreach and callback

let people = ['person','person','person','person','person'];

let logPerson = (person, index) => {
    console.log(`Hello ${person} - ${index}`);
}

people.forEach(logPerson);