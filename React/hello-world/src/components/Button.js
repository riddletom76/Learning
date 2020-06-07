import React from 'react';

class Button extends React.Component{    
    render(){
        return (
            <div>
                <button onClick={this.props.method}>{this.props.message}</button>
            </div>
        )
    }
}
export default Button;