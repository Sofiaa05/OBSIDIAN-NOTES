- `&&` is looking for the **first falsy**
    
- `||` is looking for the **first truthy**

| Falsy Values | Everything Else (Truthy) |
| ------------ | ------------------------ |
| `false`      | `'hello'`                |
| `0`          | `1`, `42`                |
| `""` (empty) | `"text"`                 |
| `null`       | object, array, etc.      |
| `undefined`  |                          |
| `NaN`        |                          |

#### Example using &&
```js
console.log(1 && "hello" && 0 && "world");  // Output: 0
alert( 1 && 2 && 3 ); // 3, the last one (when all are truthy)
```

#### Example using ||
```JS
console.log(null || "" || "WalletWatch" || 0);  // Output: "WalletWatch"
alert(0 || null || undefined || false || ""); //""
```

---
##### Precedence of AND `&&` is higher than OR `||`

So the code `a && b || c && d` is essentially the same as if the `&&` expressions were in parentheses: `(a && b) || (c && d)`.

---
```js
alert( alert(1) && alert(2) ); //1 and then undefined
```

```js
alert( alert(1) || 2 || alert(3) ); //1 and then 2
```