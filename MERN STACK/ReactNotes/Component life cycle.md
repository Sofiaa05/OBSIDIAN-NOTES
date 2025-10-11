![[Screenshot 2025-02-21 at 3.30.21 PM.png]]

### React’s Virtual DOM 
- React uses Virtual DOM exists which is like a **lightweight copy** of the actual DOM
- So for every object that exists in the original DOM, there is an object for that in React Virtual DOM. 
- It is exactly the same, but it does not have the power to directly change the layout of the document. 
- Manipulating DOM is slow, but manipulating Virtual DOM is fast as nothing gets drawn on the screen. So each time there is a change in the state of our application, the virtual DOM gets updated first instead of the real DOM.
---
## 1. Mounting
- Mounting means putting elements into the DOM. In this phase, an instance of a component is being created and inserted into the DOM.

 ### React has four built-in methods that gets called, in this order, when mounting a component:
###  1. Constructor(props) :
- It is a special function that executes when a new component is created.
* We can use constructor for 2 purposes.
	1. For **initializing state.**
	2. For **binding the event handlers.**
	
- You cannot use HTTP requests (APIs) in the constructor.
 - We have to call parent class constructor in our child class constructor by using super(props). 

### 2. getDerivedsraterrompProps() :

- It is used when the state of the component depends on changes in props over time.
- Lets say, you have a component but the initial state of the component depends on the props being passed to the component, in this scenario you can used this method to set the state.
- This is very rarely used method.
- It is invoked right before calling the render function, both on the initial mount and on subsequent updates
- It takes `state` as an argument, and returns an object with changes to the `state`.
- We cannot use this keyword inside this function, it means we cannot update the state by using **this.setState** method. It should **return an object** to update the state, or **null** to
  update nothing.
#### Example :
The example below starts with the favorite color being "red", but the `getDerivedStateFromProps()` method updates the favorite color based on the `favcol` attribute:
```js
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  static getDerivedStateFromProps(props, state) { //accept two parameters: props and state because state is dependent on props passed.
    return {favoritecolor: props.favcol };
  }
  render() {
    return (
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header favcol="yellow"/>);

OUTPUT:
My favorite color is Yellow.
```

### 3. Render() :
- **Only required** (necessary) method in the class component, so all other methods are optional and is the method that actually outputs the HTML to the DOM.
- In this method, we can read props & state and return JSX.
- We cannot change the state or interact with the DOM or make ajax calls.
- Children'components life cycle methods are also executed
#### Example : 
```js
class Header extends React.Component {
  render() {
    return (
      <h1>This is the content of the Header component</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

### 4. componentDidMount() :
- It is invoked immediately after a component is mounted, **after the render()** method.
- Invoked immediately after a component  and all its children components have been rendered to the Dom..
- We can use HTTP requests, interaction with the DOM or make ajax calls in this method.
- This is where you run statements that requires that the component is already placed in the DOM.
- This method is also used for integration with other JavaScript frameworks and other functions with delayed execution like setTimeout or setInterval.
---

## 2. Updating
- A component is updated whenever there is a change in the component's **`state`** or **`props`.** 
### React has five built-in methods that gets called, in this order, when a component is updated:
### 1. getDerivedStateFromProps() : 
- same as in mounting
#### Example :
The example below has a button that changes the favorite color to blue, but since the `getDerivedStateFromProps()` method is called, which updates the state with the color from the favcol attribute, the favorite color is still rendered as yellow:

```js
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  static getDerivedStateFromProps(props, state) {
    return {favoritecolor: props.favcol };
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header favcol="yellow" />);
```

### 2.  shouldComponentUpdate() :
- In this, you can return a **Boolean value** that specifies whether React should continue with the rendering or not.

- The default value is `true`.

The example below shows what happens when the `shouldComponentUpdate()` method returns `false`:

#### Example:
Stop the component from rendering at any update:

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  shouldComponentUpdate() {
    return false;
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);

_______________________________________________________________________________
if you set the boolean value to true, then on clicking the button, the color will change to blue.
```

### 3. render() :

The `render()` method is of course called when a component gets _updated_, it has to re-render the HTML to the DOM, with the new changes.
### Example:

Click the button to make a change in the component's state by changing the favorite color to blue

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

[Run Example »](https://www.w3schools.com/REACT/showreact.asp?filename=demo2_react_lifecycle_render2)

### 4. getSnapshotBeforeUpdate

- In this method you have access to the `props` and `state` _before_ the update, meaning that even after the update, you can check what the values were _before_ the update.

- If the **`getSnapshotBeforeUpdate()`** method is present, you should also include the **`componentDidUpdate()`** method, otherwise you will get an error.

- Any returned value by this function will be passed as third parameter to last function **componeniDidUpdate().** 
- This is also **rarely used** method according to React documentation. 
#### syntax:

```js
getSnapshotBeforeUpdate(prevProps, prevState){
}
```

### 5. componentDidUpdate()
- Invoked right after updating occurs.
- Not called for the initial render but after the render is completed in the
- re-render cycles.
- This method is guaranteed to call **only once** in a life cycle.
- You can make **Ajax Calls** in this method.
- This method will not be called if **shouldComponentUpdate() returns false.** 
---
## 3. Unmounting
- A component is removed from the DOM

- Just before the component gets removed from actual DOM, this method gets called.

- Along with removal of this component from DOM tree, all children of this component also gets removed automatically.
 
### React has only one built-in method that gets called when a component is unmounted:

### componentWillUnmount() :
- Allows us to execute the React code when the component gets destroyed or unmounted from the DOM
- This method is called during the Unmounting phase i.e before the component gets unmounted.
- All the cleanups such as **invalidating timers, canceling network requests, or cleaning up any subscriptions** that were created in **componentDidMount()** should be coded in the **componentWillUnmount()** method block.
- Cleanup activities helps in **improving performances, memory leakages and maintain security.**
- You should not call a **setState()** in this method because the component will never be re-rendered. 
---
### Mounting
- constructor()
- getDerivedStateFromProps()
- render()
- componentDidMount()
### Updating
- getDerivedStateFromProps()
- shouldComponentUpdate()
- render()
- getSnapshotBeforeUpdate()
- componentDidUpdate()
### Unmounting
- componentWillUnmount()