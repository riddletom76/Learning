import React from 'react';

class Button extends React.Component{
    constructor(props){
        super(props);
        // this.handleClick = this.handleClick.bind(this)
    }
    
    render(){
        return (
            <div>
                <Button onClick={this.props.method}>{this.props.message}</Button>
            </div>
        )
    }
}
export default Button;