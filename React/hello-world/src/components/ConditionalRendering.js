import React from 'react'

class ConditionalRendering extends React.Component
{
    constructor(){
        super();
        this.state = {
            isloading: true
        }
    }

    componentDidMount(){
        setTimeout(()=>{
            this.setState({isloading: false})}, 1500)1
    }

    render(){
        return(
            <div>
                {this.state.isloading ? <p>Loading</p> : <p>Loaded</p>}
            </div>
        )
    }
}

export default ConditionalRendering