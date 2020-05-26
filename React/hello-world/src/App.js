import React from 'react';
import BasicTodo from './components/BasicTodo';
import ContactInfo from './components/ContactInfo';
import QuestionAnswer from './components/QuestionAnswer';
import products from './components/vsSchoolProducts';
import Product from './components/Product';

function App() {
  const productArray = products.map(item => <Product key={item.id} name={item.name} price={item.price} description={item.description} />);
  return (
    <div>
      {productArray}
    </div>
  );
}

export default App;
