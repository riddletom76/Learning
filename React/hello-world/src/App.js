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
  render(){
    return(
      <Main />
    )
  }
}

export default App;
