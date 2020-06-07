import React from 'react';

class DataFetch extends React.Component{

	componentDidMount(){
		fetch("https://swapi.co/api/people/1").then(response => response.json()).then(data => console.log(data))
	}

	render(){
		return(
			<div>Helo</div>
		)
	}

}

export default DataFetch;