import React from "react";
class Counter extends React.Component{
    constructor(){
        super();
        this.state = {
            count: 0
        }
        this.handleClick = this.handleClick.bind(this);
    }

    handleClick(){
        this.setState(prevState => {
            return {count: prevState.count + 1};
        })
    }

    render(){
        return(
            <div>
                <label>{this.state.count}</label>
                <button onClick={this.handleClick}>Increment</button>
            </div>
        )
    }
}

export default Counter;