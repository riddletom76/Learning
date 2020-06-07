import React from 'react';

class BasicForm extends React.Component{

	constructor(){
		super();
		this.handleChange = this.handleChange.bind(this)
		this.state = {
			firstName: "",
			lastName: ""
		}
	}

	handleChange(event){
		this.setState({
			[event.target.name]: event.target.value
		})
	}

	render(){
		return(
			<div>
			<form>
				<input type="text" onChange={this.handleChange} value={this.state.firstName} name="firstName" />
				<input type="text" onChange={this.handleChange} value={this.state.lastName} name="lastName" />
			</form>
			<p>{this.state.firstName} {this.state.lastName}</p>
			</div>
		)
	}
}

export default BasicForm