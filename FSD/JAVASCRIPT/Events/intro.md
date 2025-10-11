## Ways to attach event listeners
### Method 1: Injecting directly in HTML element

```js
    <button onclick="
        const el = document.getElementById('heading');
        el.innerText = 'button is clicked';
    ">click me</button>

```

### onClick()

#### Directly on button
```js
<button onclick="console.log('clicked')">Click me</button>
```

#### in separate js file
```js
    <script>
		const el = document.getElementById('clickbutton');
		el.onclick = function() {
		    console.log("clicked");
		};
	</script>

//overwrites above script and print hacked in console

      <script>
        el.onclick = () => {
            console.log('hacked');
        }
      </script>
```

### addEventListeners() 
- preferred method

```js
const el = document.getElementById('clickbutton');
el.addEventListener('click', () => {
    console.log("hi");
})

//doesnt override the above event, but both runs 
el.addEventListener('click', () => {
    console.log('another change');
}); 

/*
hi
another change
*/
```

#### few examples
```js
//using eventListener to change color
const el = document.getElementById('clickbutton');

el.addEventListener('click', () => {
	const tag = document.getElementById('username');
	tag.style.color = 'red';
	console.log(tag.style.color)
})
//changes the txt color to red on clicking
```

##### toggle color
```js
el.addEventListener('click', () => {
    const tag = document.getElementById('username');
    if(tag.style.color === 'red'){
        tag.style.color = 'blue';
    }else {
        tag.style.color = 'red';
    }
    console.log(tag.style.color);
})

//changes txt color from red to blue or vice versa
```

##### change text

```html
<h2 id="heading">This is heading 2</h2>
<button id ="change">change text</button>
```

```js
const btn = document.getElementById('change');
btn.addEventListener('click', () => {
    document.getElementById('heading').innerText='Heading is changed';
})

//or

function handleChange() {
    document.getElementById('heading').innerText='Heading is changed';
}

const btn = document.getElementById('change');
btn.addEventListener('click', handleChange); //dont use paranthesis

```