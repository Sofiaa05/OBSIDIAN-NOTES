When creating a React component, the component's name must start with an **upper case letter.**

The component has to include the **`extends React.Component`** statement, that creates an inheritance to React.Component, and gives your component **access to React.Component's functions.**

The component also requires a **`render()`** method, this method **returns HTML.**

```js

//class component.js
import React from "react"; //import React, {Component} from 'react';

//Class component
class Name extends React.Component{ //class Name extends Component
    render(){
        return(
            <div>
                <h1>This is {this.props.name} {this.props.num} using props</h1>
                {this.props.children} {/* child props */}
            </div>
        )
    }
}

//indexl.js
    <Name name="class component" num={1}>
      <h3>This is a child prop within class component</h3> 
    </Name>


Output:
This is class component 1 uisng props
This is a child prop within class component
```





## Components in Components

	We can refer to components inside other components:
### Example
	Use the Car component inside the Garage component:

```jsx
class Car extends React.Component {
  render() {
    return <h2>I am a Car!</h2>;
  }
}

class Garage extends React.Component {
  render() {
    return (
      <div>
      <h1>Who lives in my Garage?</h1>
      <Car />
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Garage />);

OUTPUT:
Who lives in my Garage?
I am a Car!
```

### Class Component vs Functional Component

|Feature|**Class Component**|**Functional Component**|
|---|---|---|
|Definition|JavaScript **class** that extends `React.Component`|JavaScript **function** that returns JSX|
|Syntax|Uses `class` keyword and a `render()` method|Uses a simple function or arrow function|
|Props Access|`this.props`|`props` directly|
|State|Uses `this.state` and `this.setState()`|Uses `useState()` Hook (React 16.8+)|
|Lifecycle Methods|Supported (`componentDidMount`, `componentDidUpdate`, etc.)|Supported via `useEffect()` Hook|
|Use of `this` keyword|Required|Not required|
|Code Complexity|More complex and longer code|Simpler and cleaner|
|Performance|Slightly heavier|Lightweight and faster|
|Modern Recommendation|Less preferred for new code|✅ Recommended with Hooks|
