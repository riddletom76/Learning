import React from 'react';
import './../App.css';
import TodoItem from './TodoItem';
import todosData from './todoData';

// function BasicTodo(){
//     const todoItems = todosData.map(item => <TodoItem text={item.text} isChecked={item.completed} key={item.id} />)
//     return(
//         <div>
//             {todoItems}
//         </div>
//     )
// }

class BasicTodo extends React.Component{
    constructor(){
        super();
        this.state = {
            todoItems: todosData
        }
        this.handleChange = this.handleChange.bind(this);
    }

    handleChange(id){
        this.setState(prevState => {
            let todoItems = prevState.todoItems.map(item => {
                if(item.id == id){
                    item.completed = !item.completed
                }
            })
            return todoItems;
        })
        console.log(this.state);
    }

    render(){
        const todoRenderItems = this.state.todoItems.map(item => <TodoItem text={item.text} isChecked={item.completed} key={item.id} id={item.id} handleChange={this.handleChange}/>);
        return(
            <div>
                {todoRenderItems}
            </div>
        )
    }
}
export default BasicTodo