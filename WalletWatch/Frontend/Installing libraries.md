```bash
npm install chart.js moment react-chartjs-2 react-datepicker styled-components
```

---

### 1. ✅ `chart.js`

🟣 **What it is:**  
A powerful JavaScript charting library.

🟢 **Why you're installing it:**  
You’ll use it to create visual graphs like bar charts, pie charts, or line charts (to show income/expenses visually).

🧠 Example Use:  
Show a pie chart of categories (like Salary, Gift, Freelancing)

---

### 2. ✅ `moment`

🟣 **What it is:**  
A date/time formatting library.

🟢 **Why you're installing it:**  
To format dates like `"10-10-2020"` into readable forms like `October 10, 2020` or calculate "how many days ago" something happened.

🧠 Example Use:  
Show income added **"3 days ago"**, or format date as `Jan 25, 2025`.

---

### 3. ✅ `react-chartjs-2`

🟣 **What it is:**  
A React **wrapper** around `chart.js`.

🟢 **Why you're installing it:**  
You can’t use `chart.js` directly in React — this wrapper lets you write chart components using React code easily.
```js
<Bar data={chartData} />
```

---

### 4. ✅ `react-datepicker`

🟣 **What it is:**  
A date picker component for React.

🟢 **Why you're installing it:**  
To let users **select a date using a calendar UI** instead of typing it manually.

#### Example Use:  
Pick a date when adding income or filtering incomes by month/year.

---

### 5. ✅ `styled-components`

🟣 **What it is:**  
A way to write CSS directly inside your React components.

🟢 **Why you're installing it:**  
Instead of using `.css` files, you can style components with JavaScript. This helps keep your styling **modular and clean**.

#### Example Use:
```jsx
const Title = styled.h1`
  color: purple;
  font-size: 2rem;
`;
```