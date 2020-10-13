import React from 'react';

class Quote extends React.Component {
    render(){
      return (
        <div>
          <p id="text">{this.props.quote}</p>
        </div>
      );
    }
  }
  export default Quote;