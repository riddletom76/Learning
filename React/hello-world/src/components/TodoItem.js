import React from 'react';
import './../styles/TodoStyle.css'
function TodoItem(props){
    return(
        <div class="todo-item">
            {/* <input type="checkbox" id="vehicle1" name="vehicle1" value="Bike" />
            <label for="vehicle1"> I have a bike</label><br /> */}
            <input id={props.id} type="checkbox" defaultChecked={props.isChecked} value={props.text}/>
            <label for={props.id}>{props.text}</label>
        </div>
    )
}
export default TodoItem