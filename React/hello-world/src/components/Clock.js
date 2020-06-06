import React from 'react';

class Clock extends React.Component{
    constructor(props){
        super(props);
        this.state = {date: new Date()};
    }
    componentDidMount(){
        this.timedId = setInterval(()=>
        this.tick(), 1000);
    }
    componentWillUnmount(){
        clearInterval(this.timedId);
    }
    tick(){
        this.setState(()=>{
            return {date: new Date()}
        })
    }
    render(){
        return(
            <div>
                <p>Time: {this.state.date.toLocaleTimeString()}</p>
            </div>
        )
    }
}

export default Clock;