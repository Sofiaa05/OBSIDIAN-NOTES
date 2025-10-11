- When you are building react applications you may often need to show or hide some HTML based on a certain condition.
- In React, you can conditionally render components.
## There are several ways to do this:
## 1. If statement
```js
import React from "react";

const Correct =() =>{
    return <h1>Hi Goby.</h1>;
}

const Wrong = () => {
    return <h1>You're not Goby. No hi to you.</h1>;
}

const Check = (props) => {
    const name = props.name;
    if(name=='Goby'){
        return <Correct/>;
    }
    else{
        return <Wrong/>;
    }
}

export default Check;
```

## 2. Ternary Operator
```js
const ValidAge =() =>{
    return <h1>Your age is valid</h1>;
}

const InvalidAge = () => {
    return <h1>Your age is not valid</h1>;
}

export function TernaryOp(props) {
    const age = props.age;
   return(
    <div>
        {age >= 18? <ValidAge/> : <InvalidAge/>};
    </div>
   )
}
```

## 3. Logical && Operator
- When you dont have else condition.
```js
export function Pets(props){
    const cats = props.pets;
    return(
        <div>
            <h1>Hi Pet Lover</h1>
            {cats.length > 0 &&
            <h1>you have {cats.length} cats.</h1>}
        </div>
    );
}
```

Example usage:
```js
const pets =["toby", "winry", "Ame", "bhuraiya", "cuta", "Namra", "taro"];
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <Pets pets={pets} />
  </React.StrictMode>
);

OUTPUTS:
You have 8 cats.

```

---
## Conditional rendering [](https://react.dev/learn#conditional-rendering "Link for Conditional rendering")

In React, there is no special syntax for writing conditions. Instead, you’ll use the same techniques as you use when writing regular JavaScript code. For example, you can use an [`if`](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/if...else) statement to conditionally include JSX:

```js
let content;
if (isLoggedIn) {
  content = <AdminPanel />;
} else {
  content = <LoginForm />;
}
return (
  <div>
    {content}
  </div>
);
```

If you prefer more compact code, you can use the [conditional `?` operator.](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Conditional_Operator) Unlike `if`, it works inside JSX:

```js
<div>
  {isLoggedIn ? (
    <AdminPanel />
  ) : (
    <LoginForm />
  )}
</div>
```

When you don’t need the `else` branch, you can also use a shorter [logical `&&` syntax](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Logical_AND#short-circuit_evaluation):

```js
<div>
  {isLoggedIn && <AdminPanel />}
</div>
```

All of these approaches also work for conditionally specifying attributes. If you’re unfamiliar with some of this JavaScript syntax, you can start by always using `if...else`.