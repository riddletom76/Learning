import React from 'react';
import './../App.css';
import TodoItem from './TodoItem';
import todosData from './todoData';

function BasicTodo(){
    const todoItems = todosData.map(item => <TodoItem text={item.text} isChecked={item.completed} key={item.id} />)
    return(
        <div>
            {todoItems}
        </div>
    )
}
export default BasicTodo