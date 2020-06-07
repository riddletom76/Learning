import React from 'react';
import "../styles/MemeGeneratorStyle.css";
class Header extends React.Component{
    render(){
        return (
        	<header>
        		<img id="HeaderImage" src="http://www.pngall.com/wp-content/uploads/2016/03/Yao-Ming-Meme-PNG.png" alt="Problem?" />
        		Meme Generator 
        	</header>
        )
    }
}

export default Header