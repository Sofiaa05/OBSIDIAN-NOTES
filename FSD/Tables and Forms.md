To add a caption to a `table`, you can use the table caption element.

```html
<table>
  <caption>Football Scores</caption>
</table>
```

### thead element
The table head element, `thead`, is used to group the header content in a table.


```html
<table>
  <thead>
    <!-- header content goes here -->
  </thead>
</table>
```


### tr and th element
The table head element consists of a table row element, `tr`, which contains the table header cell elements, `th`.

Here is an example using the `tr` and `th` elements for a sports table:

Example Code

```html
<table>
  <caption>Football Scores</caption>
  <thead>
    <tr>
      <th>Team</th>
      <th>Wins</th>
      <th>Losses</th>
    </tr>
  </thead>
</table>
```

### td element

To add student data to the table, you will need to use the table row and table data elements.

The table data element, `td`, is used to create a cell in the table.


```html
<tr>
  <td>1</td>
  <td>John Doe</td>
  <td>USA</td>
</tr>
```

### colspan attribute (inside opening tag)
The `colspan` attribute specifies the number of columns a cell should span.

```html
<tr>
  <td colspan="3">Total Points</td>
</tr>
```

##### REVIEW:

## Working with HTML Table Elements and Attributes

- **Table element**: used to create an HTML table.
- **Table Head (`thead`) element**: used to group the header content in an HTML table.
- **Table Row (`tr`) element**: used to create a row in an HTML table.
- **Table Header (`th`) element**: used to create a header cell in an HTML table.
- **Table body (`tbody`) element**: used to group the body content in an HTML table.
- **Table Data Cell (`td`) element**: used to create a data cell in an HTML table.
- **Table Foot (`tfoot`) element**: used to group the footer content in an HTML table.
- **`caption` element**: used to add a title of an HTML table.
- **`colspan` attribute**: used to specify the number of columns a table cell should span.

Example Code

```html
<table>
  <caption>Exam Grades</caption>

  <thead>
    <tr>
      <th>Last Name</th>
      <th>First Name</th>
      <th>Grade</th>
    </tr>
  </thead>

  <tbody>
    <tr>
      <td>Davis</td>
      <td>Alex</td>
      <td>54</td>
    </tr>

    <tr>
      <td>Doe</td>
      <td>Samantha</td>
      <td>92</td>
    </tr>

    <tr>
      <td>Rodriguez</td>
      <td>Marcus</td>
      <td>88</td>
    </tr>
  </tbody>

  <tfoot>
    <tr>
      <td colspan="2">Average Grade</td>
      <td>78</td>
    </tr>
  </tfoot>
</table>
```

## Working with HTML Tools

- **HTML validator**: a tool that checks the syntax of HTML code to ensure it is valid.
- **DOM inspector**: a tool that allows you to inspect and modify the HTML structure of a web page.
- **Devtools**: a set of web developer tools built directly into the browser that helps you debug, profile, and analyze web pages.
---
---
##### REVIEW:
## HTML Form Elements and Attributes

- **`form` element**: used to create an HTML form for user input.
- **`action` attribute**: used to specify the URL where the form data should be sent.
- **`method` attribute**: used to specify the HTTP method to use when sending the form data. The most common methods are `GET` and `POST`.

Example Code

```html
<form method="value-goes-here" action="url-goes-here">
  <!-- inputs go inside here -->
</form>
```

- **`input` element**: used to create an input field for user input.
- **`type` attribute**: used to specify the type of input field. Ex. `text`, `email`, `number`, `radio`, `checkbox`, etc.
- **`placeholder` attribute**: used to show a hint to the user to show them what to enter in the input field.
- **`value` attribute**: used to specify the value of the input. If the input has a `button` type, the `value` attribute can be used to set the button text.
- **`name` attribute**: used to assign a name to an input field, which serves as the key when form data is submitted. For radio buttons, giving them the same `name` groups them together, so only one option in the group can be selected at a time.
- **`size` attribute**: used to define the number of characters that should be visible as the user types into the input.
- **`min` attribute**: can be used with input types such as `number` to specify the minimum value allowed in the input field.
- **`max` attribute**: can be used with input types such as `number` to specify the maximum value allowed in the input field.
- **`minlength` attribute**: used to specify the minimum number of characters required in an input field.
- **`maxlength` attribute**: used to specify the maximum number of characters allowed in an input field.
- **`required` attribute**: used to specify that an input field must be filled out before submitting the form.
- **`disabled` attribute**: used to specify that an input field should be disabled.
- **`readonly` attribute**: used to specify that an input field is read-only.

Example Code

```html
<!-- Text input -->
<input 
  type="text"
  id="name"
  name="name"
  placeholder="e.g. Quincy Larson" 
  size="20"
  minlength="5"
  maxlength="30"
  required
/>

<!-- Number input -->
<input 
  type="number"
  id="quantity"
  name="quantity"
  min="2"
  max="10"
  disabled
/>

<!-- Button -->
<input type="button" value="Show Alert" />
```

- **`label` element**: used to create a label for an input field.
- **`for` attribute**: used to specify which input field the label is for.
- **Implicit form association**: inputs can be associated with labels by wrapping the input field inside the `label` element.

Example Code

```html
<form action="">
  <label>
    Full Name:
    <input type="text" />
  </label>
</form>
```

- **Explicit form association**: inputs can be associated with labels by using the `for` attribute on the `label` element.

Example Code

```html
<form action="">
  <label for="email">Email Address: </label>
  <input type="email" id="email" />
</form>
```

- **`button` element**: used to create a clickable button. A button can also have a `type` attribute, which is used to control the behavior of the button when it is activated. Ex. `submit`, `reset`, `button`.

Example Code

```html
<button type="button">Show Form</button>
<button type="submit">Submit Form</button>
<button type="reset">Reset Form</button>
```

- **`fieldset` element**: used to group related inputs together.
- **`legend` element**: used to add a caption to describe the group of inputs.

Example Code

```html
<!-- Radio group -->
<fieldset>
  <legend>Was this your first time at our hotel?</legend>

  <label for="yes-option">Yes</label>
  <input id="yes-option" type="radio" name="hotel-stay" value="yes" />

  <label for="no-option">No</label>
  <input id="no-option" type="radio" name="hotel-stay" value="no" />
</fieldset>

<!-- Checkbox group -->
<fieldset>
  <legend>
    Why did you choose to stay at our hotel? (Check all that apply)
  </legend>

  <label for="location">Location</label>
  <input type="checkbox" id="location" name="location" value="location" />

  <label for="price">Price</label>
  <input type="checkbox" id="price" name="price" value="price" />
</fieldset>
```

- **Focused state**: this is the state of an input field when it is selected by the user.

---
## Forms in HTML

```html
<form method="value-goes-here" action="url-goes-here">
  <!-- inputs go inside here -->
</form>
```

The `action` attribute is used to specify where the form data should be sent when the form is submitted.

The `method` attribute is used to specify the HTTP method to use when sending the form data. The most common methods are `GET` and `POST`.

### fieldset element
Forms consist of `inputs` where users can input their data. You can group related inputs together using the `fieldset` element.


```html
<form action="/example-url">
  <fieldset>
  <!-- inputs go inside here-->
  </fieldset>
</form>
```

### legend element
When working with `fieldset` elements, it is common to use a caption to describe the group of inputs. You can use the `legend` element for this.

```html
<form action="/example-url">
  <fieldset>
    <legend>Personal Information</legend>
    <!-- inputs go inside here-->
  </fieldset>
</form>
```

### label element

```html
<label for="name">Name:</label>
<input type="text" id="name" name="name">
```

The `for` attribute on the `label` element should match the `id` attribute on the `input` element. This is known as an explicit association.

### input element
When a user provides their full name, the `input` will accept plaintext.

```html
<input type="text">
```

#### name element
The name attribute is used to identify form data after it has been submitted to the server.


```html
<input type="email" name="email">
```

#### number input/ min and max attributes
The number `input` is used to create a numeric input field.

```html
<input type="number" id="age" name="age" min="18" max="100">
```

The `min` and `max` attributes are used to set the minimum and maximum values that can be entered in the input field.

#### radio buttons
f you want users to select one option from a list of options, you can use a set of radio buttons.


```html
<input type="radio" id="yes" name="first-time">
<label for="yes">Yes</label>
<input type="radio" id="no" name="first-time">
<label for="no">No</label>
```

#### checkboxes 
When you want a user to select multiple options from a list, you can use checkboxes.


```html
<fieldset>
  <legend>Food Options</legend>
  <label for="pizza">Pizza</label>
  <input type="checkbox" id="pizza" name="food" value="pizza">
  <label for="burger">Burger</label>
  <input type="checkbox" id="burger" name="food" value="burger">
</fieldset>
```

The `value` attribute is used to specify the value that will be sent to the server when the form is submitted.

##### To make a checkbox input checked by default, you can add the `checked` attribute.

```html
<input checked type="checkbox" id="checked" name="checked">
```

### Dropdown menu
When you want users to make selections from a dropdown menu, you can use the `select` and `option` elements.

```html
<label for="city">Choose a City: </label>
<select id="city" name="city">
  <option value="new-york">New York</option>
  <option value="los-angeles">Los Angeles</option>
  <option value="chicago">Chicago</option>
  <option value="miami">Miami</option>
</select>
```
The `value` attribute in a `<option>` tag specifies the actual data or value that is submitted with the form when that option is selected.
- if you select New york, the form submission will send
```html
city = new-york
```

If you omit `value`:
```html
<option>Miami</option>
```
 
 the **text content** (`Red`) is used as the submission value instead.
- ##### To make an `option` selected by default, you can add the `selected` attribute to the `option` element you want to be selected.


```html
<option selected value="amazing">Amazing</option>
```

###### Allow Multiple Selections:

Use the `multiple` attribute to allow the user to select more than one value:
```html
<select id="cars" name="cars" size="4" multiple>
```
### Textarea element
If you want users to have more space to write their comments, you can use a `textarea` element.

The `textarea` element is a multi-line text input control that allows users to enter text that is longer than a single line. It can be used to create a comment box, a message input, or other text input that requires multiple lines.

```html
<textarea id="comments" name="comments" rows="4" cols="50"></textarea>
```

The `rows` attribute is used to specify the visible height of the `textarea`, and the `cols` attribute is used to specify the visible width of the `textarea`.

### The Autocomplete Attribute

The `autocomplete` attribute specifies whether a form should have autocomplete on or off.

When autocomplete is on, the browser automatically complete values based on values that the user has entered before.

### Example

A form with autocomplete on:
```html
<form action="/action_page.php" autocomplete="on">
```
