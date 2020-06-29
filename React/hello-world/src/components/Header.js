import React from 'react';
import "../styles/MemeGeneratorStyle.css";
class Header extends React.Component{
    render(){
        return (
        	<div class="header">
        		<img id="HeaderImage" src="http://www.pngall.com/wp-content/uploads/2016/03/Yao-Ming-Meme-PNG.png" alt="Problem?" />
        		<h1> Meme Generator </h1>
        	</div>
        )
    }
}

export default Header