import React from 'react';

class MemeGenerator extends React.Component{

	constructor(){
		super();
		this.state = {
			topText: "",
			bottomText: "",
			randomImage: "http://i.imgflip.com/lbij.jpg",
			allMemeImgs: []
		}
		this.handleChange = this.handleChange.bind(this)
		this.handleSubmit = this.handleSubmit.bind(this)
	}

	componentDidMount(){
		fetch("https://api.imgflip.com/get_memes").then(response => response.json()).then(response => response.data.memes).then(memes => this.setState({
			allMemeImgs: memes
		}))
	}

	handleChange(event){
		this.setState({
			[event.target.name]: event.target.value
		})
	}

	handleSubmit(event){
		event.preventDefault();
		const memes = this.state.allMemeImgs;
		this.setState({
			randomImage: memes[Math.floor(Math.random() * 10)].url
		})
		console.log(this.state.randomImage);
	}

	render(){
		return(
			<div>
				<form onSubmit={this.handleSubmit}>
					<input type="text" name="topText" value={this.state.topText} onChange={this.handleChange} placeholder="top text" />
					<input type="text" name="bottomText" value={this.state.bottomText} onChange={this.handleChange} placeholder="bottom text" />
					<button>Gen</button>
				</form>
				<div>
					<img src={this.state.randomImage} alt="Meme"/>
					<h2>{this.state.topText}</h2>
					<h2>{this.state.bottomText}</h2>
				</div>
			</div>
		)
	}
}

export default MemeGenerator