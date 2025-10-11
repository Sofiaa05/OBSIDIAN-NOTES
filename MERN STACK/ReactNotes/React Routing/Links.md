**`<Link>`** is used to set the URL and keep track of browsing history.

Anytime we link to an internal path, we will use `<Link>` instead of `<a href="">`. `<Link>` corresponds to anchor `<a>` element in HTML.

Doesn't reload on clicking any of the link mentioned.

Doesn't have **active class.**
```js
import React from 'react'
import { Link } from 'react-router-dom'

function Navbar() {
  return (
    <nav>
        <Link to='/'>Home</Link>  //<a href='/'> Home <a/> (in HTML)
        <Link to='/about'>About</Link>
        <Link to='/contact'>Contact</Link>
    </nav>
  )
}
export default Navbar
```

---
## Navlink 
To decorate active link (link you have currently opened)

```js
import {navLink} from 'react-router-dom'
```

```js
function Navbar() {
    const linkcss = ({isActive}) => {
        return{
            fontWeight: isActive? 'bold' : 'normal',
            fontSize: isActive?  'x-large' : 'normal'
        }
    }
  return (
    <nav>
        <NavLink  style={linkcss}to='/'>Home</NavLink>
        <NavLink  style={linkcss}to='/about'>About</NavLink>
        <NavLink  style={linkcss}to='/contact'>Contact</NavLink> 

    </nav>
  )
}
---------------------------------------------------------------------------------
//Applying css in css file:
nav a.active{
  font-weight: bold;
  font-size:x-large;
} 
```
##### Explanation:
1. `isActive` is **true** if the current link matches the active URL, otherwise **false**.

2. **`NavLink`** (from `react-router-dom`) is used instead of `<a>` because:
	- It prevents full page reloads.
	- It automatically detects if the link is active.
