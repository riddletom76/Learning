import React from 'react';

class BasicForm extends React.Component{

	constructor(){
		super();
		this.handleChange = this.handleChange.bind(this)
		this.state = {
			firstName: "",
			lastName: "",
			additionalInfo: "",
			isChecked: false,
			gender:""
		}
	}

	handleChange(event){
		const {name, value, type, checked} = event.target
		type==="checkbox" ? this.setState({
			[name]: checked
		}):
		this.setState({
			[name]: value
		})
	}

	render(){
		return(
			<div>
			<form>
				<input type="text" onChange={this.handleChange} value={this.state.firstName} name="firstName" placeholder="First Name" />
				<input type="text" onChange={this.handleChange} value={this.state.lastName} name="lastName" placeholder="Last Name" />
				<textarea name="additionalInfo" placeholder="Default value" value={this.state.additionalInfo} onChange={this.handleChange} />
				<label>
					<input type="checkbox" name="isChecked" checked={this.state.isChecked} onChange={this.handleChange} /> Is Checked?
				</label>
				<br />
				<label><input type="radio" name="gender" checked={this.state.gender === "male"} onChange={this.handleChange} value="male" />Male</label>
				<br />
				<label><input type="radio" name="gender" checked={this.state.gender === "female"} onChange={this.handleChange} value="female" />Female</label>
			</form>
			<p>{this.state.firstName} {this.state.lastName} Additional Info - {this.state.additionalInfo}</p>
			<p>{this.state.gender}</p>
			</div>
		)
	}
}

export default BasicForm