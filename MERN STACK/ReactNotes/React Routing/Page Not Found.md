```js
function PageNotFound() {
  return (
    <div>
      <h2> Error-404! Page Not Found</h2>
    </div>
  )
}

<Route path='/*' element={<PageNotFound/>}/
```
##### Explanation:
On navigating to anything `/....` it will redirect to PageNotFound automatically if the path is not defined in routes.