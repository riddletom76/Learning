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
			gender:"",
			favColor: ""
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
				<br />
				<label>Favourite Color:
					<select name="favColor" value={this.state.favColor} onChange={this.handleChange}>
						<option value="red">Red</option>
						<option value="green">Green</option>
						<option value="blue">Blue</option>
						<option value="black">Black</option>
					</select>
				</label>
			</form>
			<p>{this.state.firstName} {this.state.lastName} Additional Info - {this.state.additionalInfo}</p>
			<p>{this.state.gender}</p>
			<p>Favourite Color is - {this.state.favColor}</p>
			</div>
		)
	}
}

export default BasicForm