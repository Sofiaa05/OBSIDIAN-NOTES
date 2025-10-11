

![[Screenshot 2025-02-21 at 12.23.52 AM.png]]

![[Screenshot 2025-02-21 at 12.24.17 AM.png]]

```js
import React, { Component } from 'react'

export default class Constructor extends Component {
    constructor(props){
        super(props);
        console.log("This is Constructor from student class")
    }

  render() {
    return (
      <div>
        <h1>This is Constructor example using {this.props.prop}</h1>
      </div>
    )
  }
}

//index.js
<Constructor prop="props"/>

OUTPUT:
This is Constructor example using props
```