import React from "react";
import "../styles/ContactCard.css";
function ContactCard(props){
    return (
        <div class="contact-card">
            <p>My name is: {props.Name}</p>
            <p>My age is: {props.Age}</p>
            <p>My number is: {props.Number}</p>
        </div>
    );
}

export default ContactCard;