import React from 'react';
import Quote from './Quote';
import Author from './Author';
import TweetQuote from './TweetQuote';
class Wrapper extends React.Component {
    constructor(props){
        super(props);
        this.state = {
            allQuotes: [],
            currentQuote: "Hello",
            currentAuthor: "Author"
        }
    }
    componentDidMount(){
        fetch('https://gist.githubusercontent.com/camperbot/5a022b72e96c4c9585c32bf6a75f62d9/raw/e3c6895ce42069f0ee7e991229064f167fe8ccdc/quotes.json').then(response => response.json()).then(data => this.setState({
            allQuotes: data.quotes
        }));
    }

    handleNewQuote = (e) => {
        let randomQuote = this.state.allQuotes[
            Math.floor(Math.random() * this.state.allQuotes.length)
          ];
        this.setState({
            currentQuote: randomQuote.quote,
            currentAuthor: randomQuote.author
        });
    }
    render(){
        return(
            <div id="quote-box">
                <Quote quote={this.state.currentQuote} />
                <Author author={this.state.currentAuthor} />
                <button id="new-quote" onClick={this.handleNewQuote}>New Quote</button>
                <TweetQuote currentQuote={this.state.currentQuote} currentAuthor={this.state.currentAuthor} />
            </div>
        );
    }

}

export default Wrapper;