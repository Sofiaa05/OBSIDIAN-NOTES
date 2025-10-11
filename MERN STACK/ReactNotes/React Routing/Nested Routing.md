In products page, we want to display pages for `shirts` and `jeans`:

```js
//Products.js

function Products() {
  return (
    <div>
      <h1>These are my products</h1>
      
      <nav>
        <Link to={'shirts'}>Shirts</Link>
        <Link to={'jeans'}>Jeans</Link>
      </nav>

      <Outlet/> //child route component will be displayed
    </div>
  )
}

```
##### Explanation :
```js
<Outlet/>
```

- <Outlet /> is a **placeholder for nested routes.**
- If Products is a parent route, the **corresponding child route will be rendered inside <Outlet />.**

```js
//App.js
//Nested Routes:
      <Route path='/products' element={<Products/>}>
	       <Route path='shirts' element={<Shirts/>}/>
	       <Route path='jeans' element={<Jeans/>}/>
      </Route>
```

##### Explanation : 
- This means when the URL is **`/products`**, the **`Products`** component will render.
- If the user visits **`/products/shirts`**, the `Shirts` component will be rendered **inside** `Products` (at `<Outlet />`).
- The `Products` component remains visible, and only the `<Outlet />` content changes.
