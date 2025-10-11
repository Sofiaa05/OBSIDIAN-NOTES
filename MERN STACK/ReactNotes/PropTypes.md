- We passed different types of information like integers, strings, arrays, etc. as props to the components. 
- No check on what type of values we are getting inside our Component through props. 
- For larger Apps, good practice to validate the data we are getting through props. Helps in debugging and  avoiding bugs in the future.

```js
npm i prop-types
```
```js
import PropTypes from 'prop-types';
```

