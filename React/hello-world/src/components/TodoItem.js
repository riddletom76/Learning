import React from 'react';
import './../styles/TodoStyle.css'
// function TodoItem(props){
//     return(
//         <div class="todo-item">
//             {/* <input type="checkbox" id="vehicle1" name="vehicle1" value="Bike" />
//             <label for="vehicle1"> I have a bike</label><br /> */}
//             <input id={props.id} type="checkbox" defaultChecked={props.isChecked} value={props.text}/>
//             <label for={props.id}>{props.text}</label>
//         </div>
//     )
// }

class TodoItem extends React.Component{
    constructor(){
        super();
    }
    
    render(){
        const CompletedStyle = {
            fontStyle: "italic"
        }
        return (
            <div class="todo-item">
                <input 
                    id={this.props.id} 
                    type="checkbox" 
                    checked={this.props.isChecked} 
                    onChange={() => {this.props.handleChange(this.props.id)}} 
                    value={this.props.text} />
                <label style={this.props.isChecked ? CompletedStyle : null} for={this.props.id}>{this.props.text}</label>
            </div>
        )
    }
}
export default TodoItem