import React from 'react';

function QuestionAnswer(props){
    return(
        <div>
            <p>
    {props.question ? <div>
        Question: {props.question}
    </div> : <div></div>}
                <br />
                Answer: {props.answer}
            </p>
        </div>
    );
}

export default QuestionAnswer;