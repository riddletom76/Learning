import React from 'react';

class Author extends React.Component {
    render(){
      return(
        <div>
          <p id="author">{this.props.author}</p>
        </div>  
      );
    }
  }
  export default Author;