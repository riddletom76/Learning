import React from 'react';
// import Main from './components/Main';
// import BasicTodo from './components/BasicTodo';
// import ContactInfo from './components/ContactInfo';
// import QuestionAnswer from './components/QuestionAnswer';
// import products from './components/vsSchoolProducts';
// import Product from './components/Product';
// import Counter from "./components/Counter";
// import Clock from './components/Clock';
// import ConditionalRendering from './components/ConditionalRendering';
// import Login from './components/Login';
// import Button from './components/Button';
// import DataFetch from './components/DataFetch';
// import BasicForm from './components/BasicForm';
// import TravelForm from './components/TravelForm';
import Header from './components/Header';
import MemeGenerator from './components/MemeGenerator';
// function App() {
//   return (
//     <BasicTodo />
//   );
// }

class App extends React.Component{
  
  render(){
    return(
      <div>
        <Header />
        <MemeGenerator />        
      </div>
    )
  }
}
export default App;
