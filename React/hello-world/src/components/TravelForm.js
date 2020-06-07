import React from 'react';

class TravelForm extends React.Component{
	constructor(){
		super();
		this.state = {
			firstName: "",
			lastName: "",
			age: 0,
			gender: "",
			location: "",
			milk: false,
			water: false,
			food: false
		}
		this.handleChange = this.handleChange.bind(this)
		this.handleSubmit = this.handleSubmit.bind(this)
	}

	handleChange(event){
		const {name, value, type, checked} = event.target;
		type==="checkbox"?this.setState({
			[name]: checked
		}) : this.setState({
			[name]: value
		})
	}

	handleSubmit(event){
		let str = "Name: " + event.target.firstName.value + event.target.lastName.value + "\n" +
		"Age: " + event.target.age.value + "\n" + "Gender: " + event.target.gender.value + "\n" + 
		"Location: " + event.target.location.value + "\n" + "Food: " + (event.target.milk.checked ? "Milk,": "" + event.target.water.checked ? "Water," : "" + event.target.food.checked ? "Food," : "");
		alert(str);
	}

	render(){
		return(
			<div>
				<form onSubmit={this.handleSubmit}>
					<label>First Name <input type="text" name="firstName" value={this.state.firstName} onChange={this.handleChange} placeholder="first name" /></label> <br />
					<label>Last Name <input type="text" name="lastName" value={this.state.lastName} onChange={this.handleChange} placeholder="last name" /></label> <br />
					<label>Age <input type="number" name="age" value={this.state.age} onChange={this.handleChange} /></label> <br />
					<label>Gender: 
						<label>Male<input type="radio" name="gender" checked={this.state.gender==="male"} onChange={this.handleChange} value="male" /></label>
						<label>Female<input type="radio" name="gender" checked={this.state.gender==="female"} onChange={this.handleChange} value="female" /></label>
					</label> <br />
					<label>Location:
						<select value={this.state.location} onChange={this.handleChange} name="location">
							<option value="bangalore">Bangalore</option>
							<option value="delhi">Delhi</option>
							<option value="mumbai">Mumbai</option>
						</select>
					</label> <br />
					<label>choice:
						<label><input type="checkbox" onChange={this.handleChange} checked={this.state.milk} name="milk"/>Milk</label>
						<label><input type="checkbox" onChange={this.handleChange} checked={this.state.water} name="water"/>Water</label>
						<label><input type="checkbox" onChange={this.handleChange} checked={this.state.food} name="food"/>Food</label>
					</label> <br />
					<button type="submit">Submit</button>
				</form>
			</div>
		)
	}
}

export default TravelForm;