import React from 'react';
import Main from './components/Main';
import BasicTodo from './components/BasicTodo';
import ContactInfo from './components/ContactInfo';
import QuestionAnswer from './components/QuestionAnswer';
import products from './components/vsSchoolProducts';
import Product from './components/Product';
// function App() {
//   return (
//     <BasicTodo />
//   );
// }

class App extends React.Component{
  constructor(){
    super();
    this.state = {
      name: "Rishabh Sharma",
      age: 20
    }
  }
  render(){
    return(
      <div>
        <h1>I am {this.state.name}</h1>
        <h1>{this.state.age} years old</h1>
      </div>
    )
  }
}

export default App;
