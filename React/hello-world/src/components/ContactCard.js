import React from "react";
import "../styles/ContactCard.css";
function ContactCard(props){
    console.log(props);
    return (
        <div class="contact-card">
            <p>My name is: {props.contact.Name}</p>
            <p>My age is: {props.contact.Age}</p>
            <p>My number is: {props.contact.Number}</p>
        </div>
    );
}

export default ContactCard;