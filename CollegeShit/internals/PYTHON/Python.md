---
aliases:
---
### 2 marks:
- implicit type conversion vs explicit type conversion
- short circuit vs lazy evaluation
- types of arguments
---
#### **What is Short-Circuit Evaluation?**

**optimization technique** where Python **stops evaluating a logical expression as soon as the result is determined**.

### **1. How Short-Circuit Works with `and` and `or`**

|Operator|Behavior|
|---|---|
|**`and`**|Stops if the first value is `False` (because `False and anything` is always `False`).|
|**`or`**|Stops if the first value is `True` (because `True or anything` is always `True`).|

---

### **2. Short-Circuiting with `and`**

- If the **first operand is `False`**, the second operand is **not evaluated**.

🔹 **Example:**

```PYTHON
def func():
    print("Function executed")
    return True

print(False and func())  # Output: False

```

💡 **Why?**

- Since `False and anything` is always `False`, **Python does not execute `func()`**.

---

### **3. Short-Circuiting with `or`**

- If the **first operand is `True`**, the second operand is **not evaluated**.

🔹 **Example:**

```PYTHON
def func():
    print("Function executed")
    return True

print(True or func())  # Output: True

```

💡 **Why?**

- Since `True or anything` is always `True`, **Python does not execute `func()`**.

### **Lazy Evaluation in Python**

#### **What is Lazy Evaluation?**

Lazy evaluation means **delaying the computation of a value until it is actually needed**.

- It **saves memory** and **improves performance** by avoiding unnecessary calculations.
- Used in **generators, iterators, and functions like `map()`, `filter()`, and `zip()`**.

#### **What is Lazy Evaluation in `range()`?**

- The `range()` function **does not generate all numbers at once**.
- Instead, it **produces numbers one at a time when needed**, making it **memory-efficient**
```PYTHON
r = range(1, 1000000)  # Creates a range object but does not store all numbers
print(r[0])  # Output: 1
print(r[999999])  # Output: 1000000

```

---
## **Differences Between Indexing & Slicing**

| Feature | Indexing                                                                       | Slicing                                                                                                      |
| ------- | ------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------ |
| Purpose | Access a **single character**                                                  | Extract a **substring**                                                                                      |
| Syntax  | `string[index]`                                                                | `string[start:stop:step]`                                                                                    |
| Returns | A **single character**                                                         | A **new string**                                                                                             |
| Step    | Not applicable                                                                 | Allows skipping characters                                                                                   |
|         | An IndexError will be thrown if you attempt to use an index that is too large. | An IndexError will be thrown if you attempt to use an index that is too large. returns string of its length. |

---
### List Comprehension:
```python
[expression for item in iterable if condition == True]
```
- **expression** → The operation to perform on each element.
- **item** → The variable representing each element.
- **iterable** → The source of elements (like a list, range, etc.).
- **condition (optional)** → A filtering condition
## List Comprehension

List comprehension offers a shorter syntax when you want to create a new list based on the values of an existing list.
```python
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = []

for x in fruits:
  if "a" in x:
    newlist.append(x)

print(newlist)
```

```python
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]

newlist = [x for x in fruits if "a" in x]

print(newlist)
```
---
### filter(): 

The **`filter()`** function is used to **filter elements from a list** based on a condition. It **only keeps** elements that satisfy the condition.

### **🔹 Syntax**

```python
filter(function, iterable)
```


- **`function`** → A function that returns `True` or `False`.
- **`iterable`** → A list, tuple, or other sequence.
- **Keeps only elements where the function returns `True`**
```python
def is_even(num):
    return num % 2 == 0  # Returns True for even numbers

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
even_numbers = list(filter(is_even, numbers))

print("Even Numbers:", even_numbers)

```

---
### Zip() :
takes two or more sequences and "zips" them into a list of tuples. The tuple thus, formed has one element from each sequence.
```python
list1=[1,2,3]
tup=("sofia","mukul","toby")
print(list(zip(list1,tup)))

OUTPUT: [(1,"mukul"),...]
```
 ---

 ### Tuples functions
 - count(), index(), max(), min(),len()
 
 ---
 ### Sets
 - unordered list with duplicate values.
 - | , &, -, len(), index(), count(),
 ---
 ### Dictionary 
 - The `pop()` method removes the item with the specified key name:
 - The `popitem()` method removes the last inserted item

---

### append() vs extend()

|Feature|`append()`|`extend()`|
|---|---|---|
|Adds a single element|✅ Yes|❌ No|
|Adds multiple elements separately|❌ No|✅ Yes|
|Accepts an iterable|✅ Yes (adds it as one element)|✅ Yes (spreads elements)|
|Changes list length|✅ Increases by 1|✅ Increases based on iterable size|

---
### Dictionary

keys(), values(), len(), update(), copy()

#### list vs tuple vs dictionary
https://www.geeksforgeeks.org/differences-and-applications-of-list-tuple-set-and-dictionary-in-python/#difference-between-list-tuple-set-and-dictionary

  #### Sorting of ds except lists :
  ```python
  sorted_dict = dict(sorted(student.items())) #for dictionary
#<iterable>(sorted(<iterablename>))
```
 ##### Example code:
 - WAP to input your friends' name and their phone numbers and store them in the dictionary as the key-value pair
 ```python
 friends = {}  # Empty dictionary to store names and phone numbers

n = int(input("How many friends do you want to add? "))

for _ in range(n):
    name = input("Enter friend's name: ")
    phone = input("Enter phone number: ")
    friends[name] = phone  # Storing in dictionary

print("\nFriends' Contact List:")
print(friends)

```

- Q3. WAP that has dictionary of names of students and a list of their marks in 4 subjects, create another dictionary from this dictionary that has name oft h e students and their total marks
```python
# Dictionary with student names as keys and a list of their marks as values
students = {
    "Sofia": [85, 90, 78, 88],
    "Mukul": [76, 81, 85, 79],
    "Toby": [92, 88, 84, 91]
}

# Dictionary to store total marks
total_marks = {}

# Calculating total marks manually using a loop
for name, marks in students.items():
    total = 0  # Initialize total for each student
    for mark in marks:
        total += mark  # Adding each mark to total
    total_marks[name] = total  # Store total in dictionary

# Display total marks
print("\nTotal Marks of Students:")
print(total_marks)

 # Output : Total Marks of Students:
# {'Sofia': 341, 'Mukul': 321, 'Toby': 355}

 # finding out topper
for name,total in total_marks.items()
	if(total == max(total_marks.values()):
		highestscore = total
		topper = name
		break;

```
---
### file handling 
A path is a string that specifies the location of a file or folder in a file system.

**Relative path**
- relative to the current working directory of the program or the user

**Absolute path**
- path that starts from the root of the file system.
#### 2 Types of files:
- binary files (.jpg, .pdf, .png)
- text files (.txt) : stream of characters, human readable form.
### file object attributes:

![[Pasted image 20250319014518.png]]

### readline() vs readlines()
readline : reads one line at a time. next call will read next line
readliens() : reads all lines and store them in list of strings

### delete
To delete an entire folder, use the `os.rmdir()` method
delete file : To delete a file, you must import the OS module, and run its `os.remove()` function:

---
### List operations:
List items are ordered, changeable, and allow duplicate values.
- insert 
- append
- remove (removes element by value)
- pop (removes element by index)
- sort 
- reverse
- len
- check membership
#### Cloning list
- slicing [:] 
```python
b = a[:]
```
- copy() method
```python
b = a.copy()
```
- list() function
```python
b = list(a)
```

#### Searching in Lists

##### A. Using `in` keyword

###  Sorting Lists

###  A. `sort()` method (Modifies original list)

```python
marks = [90, 70, 85, 60] 
marks.sort() 
print(marks)  # [60, 70, 85, 90]`
```

###  B. `sorted()` function (Creates a new list)

```python
`marks = [90, 70, 85, 60] 
sorted_marks = sorted(marks) 
print(sorted_marks) 

```

### C. Sorting in Reverse

```python
`marks.sort(reverse=True) 
print(marks)  # [90, 85, 70, 60]`
```

---
### Dictionary
- Dictionaries are used to store data values in key:value pairs.
- A dictionary is a collection which is ordered*, changeable and do not allow duplicates.

| Operation         | Syntax                       | Behavior                          |
| ----------------- | ---------------------------- | --------------------------------- |
| Create dictionary | `d = {"key": value}`         | Creates dict with key-value pairs |
| Add item          | `d[new_key] = new_value`     | Adds new key-value pair           |
| Remove item       | `del d[key]` or `d.pop(key)` | Removes key-value pair            |
| Access value      | `d[key]` or `d.get(key)`     | Gets value for the key            |
| Replace value     | `d[key] = new_value`         | Updates value for existing key    |
#### Traversing Dictionaries
- loop through keys
```python
for key in d:
    print(key)

```

- loop thorugh values
```python
for value in d.values():
    print(value)
```

- loop thorugh key-value pairs
```python
for key, value in d.items():
    print(key, ":", value)
```

#### Sorted Dictionaries
```python
d = {"b": 2, "a": 1, "c": 3}
for key in sorted(d):
    print(key, d[key])

```

--- 

### Add two complex numbers:

```python
class ComplexNumber:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __add__(self, other):
        new_real = self.real + other.real
        new_imag = self.imag + other.imag
        return ComplexNumber(new_real, new_imag)

    def __str__(self):
        return f"{self.real} + {self.imag}j"

# Step 1
c1 = ComplexNumber(3, 4)
c2 = ComplexNumber(5, 7)

# Step 2 (calls __add__)
c3 = c1 + c2

# Step 3 (calls __str__ to print)
print("Sum:", c3)

```

```python
class BankAccount:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"₹{amount} deposited.")
        else:
            print("Enter a positive amount to deposit.")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient balance!")
        elif amount <= 0:
            print("Enter a valid amount to withdraw.")
        else:
            self.balance -= amount
            print(f"₹{amount} withdrawn.")

    def display(self):
        print(f"Account Holder: {self.name}")
        print(f"Current Balance: ₹{self.balance}")

# Main program (principal code)
account = BankAccount("Runcipa", 5000)  # Initial balance = 5000

account.display()
account.deposit(2000)
account.withdraw(1500)
account.display()
```

### find square and throw exception is user enters character instead of number
```python
class Square:
    def __init__(self, number):
        self.number = number
    
    def square(self):
        return self.number * self.number

try:
    number = int(input("Enter a number: "))
except ValueError:
    print("Enter an integer only")
    number = None  # handle invalid input safely

if number is not None:
    s = Square(number)
    print("Square is:", s.square())
else:
    print("Program terminated due to invalid input.")

```