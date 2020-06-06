import React from 'react';
class Login extends React.Component{
    constructor(){
        super();
    }
    render(){
        return(
            <div>
                {this.state.isLoggedIn ? <p>Logged IN</p> : <p>Logged Out</p>}
            </div>
        )
    }
}
export default Login