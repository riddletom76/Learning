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
    }
    render(){
        const todoRenderItems = this.state.todoItems.map(item => <TodoItem text={item.text} isChecked={item.completed} key={item.id} id={item.id} />);
        return(
            <div>
                {todoRenderItems}
            </div>
        )
    }
}
export default BasicTodo