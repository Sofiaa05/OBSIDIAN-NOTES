
| Props                             | States                                             |
| --------------------------------- | -------------------------------------------------- |
| Props get passed to the component | State is created and managed within the component. |
| Function Parameters.              | Variables                                          |
| Immutable                         | Mutable                                            |
| props -> Functional Components    | useState Hook -> Functional Components             |
| this.props -> Class Components    | this.state -> Class components                     |


| Feature             | **Props**                     | **State**                                              |
| ------------------- | ----------------------------- | ------------------------------------------------------ |
| Type                | Immutable (read-only)         | Mutable (can be changed)                               |
| Use                 | Pass data to child components | Store dynamic data inside a component                  |
| Updated by          | Parent component              | The component itself                                   |
| Accessed via        | `props.propertyName`          | `this.state` (class) or `[state, setState]` (function) |
| Triggers re-render? | No (unless parent re-renders) | Yes                                                    |
| Example             | `<Component name="Sofia" />`  | `useState(0)` or `this.setState()`                     |
| Shareable?          | Yes (parent → child)          | No (internal to component)                             |