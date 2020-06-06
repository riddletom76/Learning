import React from 'react';
// import Main from './components/Main';
import BasicTodo from './components/BasicTodo';
// import ContactInfo from './components/ContactInfo';
// import QuestionAnswer from './components/QuestionAnswer';
// import products from './components/vsSchoolProducts';
// import Product from './components/Product';
// import Counter from "./components/Counter";
// import Clock from './components/Clock';
// import ConditionalRendering from './components/ConditionalRendering';
import Login from './components/Login';
import Button from './components/Button';
// function App() {
//   return (
//     <BasicTodo />
//   );
// }

class App extends React.Component{
  constructor(){
    super();
    this.state = {
      isLoggedIn: false
    }
    this.handleClick = this.handleClick.bind(this)
  }
  handleClick(){
    this.setState(prevState =>
        {
            return {isLoggedIn: !prevState.isLoggedIn}
        }
    )
  }
  render(){
    return(
      <div>
        <Button method={this.handleClick} message={this.state.isLoggedIn ? "LogOut": "LogIn"}/>
        <Login />
      </div>
    )
  }
}
export default App;
