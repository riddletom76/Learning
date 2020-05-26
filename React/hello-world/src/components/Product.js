import React from 'react';

function Product(props){
    return (
        <div>
            <p>Name: {props.name}
            <br />
            Price: {props.price}
            <br />
            Description: {props.description}
            </p>
        </div>
    )
}

export default Product