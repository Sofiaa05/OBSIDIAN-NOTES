
- Hooks allow function components to have access to state and other React features like life cycle methods without writing a class.

- Because of this, class components are generally no longer needed. 

- Hooks were-added to React in version 16.8 (February 16, 2019). React release date : May 29, 2013
- Hooks are basically functions.
- Hooks allow us to "hook" into React features such as state and lifecycle methods.
---
## Hook Rules :
- Hooks can only be called **inside React function components.**
- Hooks can only be called at the **top level** of a component.
- We should not call Hooks inside loops, conditions or nested functions.
- Only call Hooks from React functions, we should not call Hooks from-regular JavaScript functions.
- Hooks **cannot be conditional.**
-  React relies on the **order** in which Hooks are called.
- Hooks are not used for class based components.
---
## Custom Hooks

If you have **stateful logic** that needs to be reused in several components, you can build your own custom Hooks.

## When to use a Hooks
If you write a function component, and then you want to add some state to it, previously you do this by **converting it to a class.**
But, now you can do it by using a **Hook inside the existing function component.**