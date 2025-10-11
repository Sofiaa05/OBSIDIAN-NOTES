```html
//index.html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <div>
        <input
            id="city"
            type="text"
            placeholder="enter your location"
        />
        <button id="search">search</button>
    </div>

    <div>
        <h3 id="cityName">Canada, Ontario, New Delhi</h3>
        <h6 id="time">localtime</h6>
        <p id="temp">13</p>
    </div>

    <script src="script.js"></script>
</body>
</html>
```

```js
//script.js
const btn = document.getElementById("search");
const input = document.getElementById("city");

const cityName = document.getElementById('cityName')
const time = document.getElementById('time')
const temp = document.getElementById('temp')

btn.addEventListener('click', async () => {
    const value = input.value;
    const res = await getData(value);
    cityName.innerText=`${res.location.name}, ${res.location.region} - ${res.location.country}`;
    time.innerText = `${res.location.localtime}`;
    temp.innerText = `${res.current.temp_c}`;
})

async function getData(input) {
   const promise = await fetch(`http://api.weatherapi.com/v1/current.json?key=ae16c4324e604540a93123526251307&q=${input}&aqi=yes`)
   return await promise.json()
}



```