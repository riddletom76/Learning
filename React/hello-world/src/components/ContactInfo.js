import React from "react";
import ContactCard from "./ContactCard";

function ContactInfo(){
    return (<div>
        <ContactCard contact={{Name:"Rishabh",  Age:'20', Number:"11111072"}}/>
        <ContactCard contact={{Name:"Sharma", Age:'20', Number:"11111073"}} />
        <ContactCard contact={{Name:"Ram", Age:'20', Number:"1111111074"}} />
        <ContactCard contact={{Name:"Shyam", Age:'20', Number:"111111075"}} />
    </div>);
}

export default ContactInfo;