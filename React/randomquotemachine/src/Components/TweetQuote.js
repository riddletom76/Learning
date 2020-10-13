import React from 'react';
class TweetQuote extends React.Component {
    constructor(props){
        super(props);
    }
  render(){
    let tweet = "https://twitter.com/intent/tweet?hashtags=quotes&related=freecodecamp&text=" + encodeURIComponent('"' + this.props.currentQuote + '"' + this.props.currentAuthor);
    console.log(tweet);
    return(
      <div>
        <a id="tweet-quote" href={tweet}>Tweet Quote</a>
      </div>
    );
  }
}

export default TweetQuote;