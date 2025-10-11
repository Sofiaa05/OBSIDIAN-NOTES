- The purpose of the function is to display the specified **HTML code inside the specified HTML element.**

- React renders HTML to the web page by using a function called **`createRoot()`** and its method **`render()`.**

#### The createRoot Function

- The **createRoot()** function takes one argument, an HTML element.

- The purpose of the function is to **define the HTML element** where a React component should be displayed.

#### But Render Where?

- The **`render()`** method is then called to define the React component that should be rendered. 

- There is another folder in the root directory of your React project, named "public". In this folder, there is an **`index.html`** file.

- You'll notice a single **`<div>`** in the body of this file. This is where our React application will be rendered.