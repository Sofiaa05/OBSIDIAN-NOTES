- **For initialising min:**
	- Integer.MIN_VALUE 
- **For initialising max:**
	- Integer.MAX_VALUE
---
- if question is asked on string and chracter and we need to convert string to char to work, always convert entire string to char array then loop char array. 

```java
char[] ch = s.toCharArray();
```

- dont convert each char in for loop looping through string
```java
for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
         
        }

```

---
- uppercase to lowercase:
```java
    chars[i] = (char) (chars[i]+32);

```

- converting char array to string:
```java
   return new String(chars);
```

---
### check vowel
```java
    private boolean isVowel(char c){
        if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u' ||
        c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U' ){
        return true;
        }
        // if ("aeiouAEIOU".contains(String.valueOf(c))) return true;
        return false;
    }
}
```

---
### count digits:
```java
        static int digits(int num){
            int count =0;

            while (num > 0) { //1764>0, 176>0 , 17>0 , 1>0 , 0>0 (false)
                count++;  //count=1 --> 2 --> 3 --> 4(count stops)
                num/=10;  //176 --> 17 --> 1 --> 0 
            }
            return count;
        }

```

----
### String to Integer

| Method                  | Example                           | Notes                                    |
| ----------------------- | --------------------------------- | ---------------------------------------- |
| `Integer.parseInt(str)` | `Integer.parseInt("123")` → `123` | Most common, throws exception if invalid |
| `Integer.valueOf(str)`  | `Integer.valueOf("123")` → `123`  | Returns `Integer` object, not primitive  |

### Integer to String
| Method                            | Example                           | Notes                                             |
| --------------------------------- | --------------------------------- | ------------------------------------------------- |
| `String.valueOf(int)`             | `String.valueOf(123)` → `"123"`   | Most common and safe                              |
| `Integer.toString(int)`           | `Integer.toString(123)` → `"123"` | Preferred when you know it's an int               |
| `"" + int` (String concatenation) | `"" + 123` → `"123"`              | Quick and common, but not preferred in production |


---
### In array rotation
```java
k = k % n
```

- This ensures that the number of rotations `k` does **not exceed the length of the array**
- Rotating an array of size 5 **7 times** is the same as rotating it **2 times**:
```java
k = k % n = 7 % 5 = 2

```

---

| Expression | Result | Why                              |
| ---------- | ------ | -------------------------------- |
| `10 / 3`   | `3`    | Integer division: 3 fits 3 times |
| `3 / 10`   | `0`    | 10 doesn’t fit in 3, so 0        |
| `10 % 3`   | `1`    | Remainder after 3×3 = 9 → 10–9=1 |
| `3 % 10`   | `3`    | 10 goes 0 times → remainder is 3 |

---

### HashMap methods:

| Method                         | Use Case                   | Example                                                |
| ------------------------------ | -------------------------- | ------------------------------------------------------ |
| `put(K key, V value)`          | Insert or update key-value | `map.put(1, 100);`                                     |
| `get(K key)`                   | Get value for key          | `int val = map.get(1);`                                |
| `containsKey(K key)`           | Check if key exists        | `map.containsKey(1)`                                   |
| `remove(K key)`                | Remove key-value           | `map.remove(1);`                                       |
| `getOrDefault(K key, default)` | Safe get with fallback     | `map.getOrDefault(k, 0)`                               |
| `keySet()`                     | Loop over keys             | `for (int key : map.keySet())`                         |
| `entrySet()`                   | Loop over key-value pairs  | `for (Map.Entry<Integer, Integer> e : map.entrySet())` |

### HashSet Methods:

|Method|Use Case|Example|
|---|---|---|
|`add(E e)`|Add element (auto skips duplicates)|`set.add(10);`|
|`contains(E e)`|Check if exists|`set.contains(10);`|
|`remove(E e)`|Remove element|`set.remove(10);`|
|`size()`|Get count of unique elements|`set.size();`|
|`isEmpty()`|Check if empty|`set.isEmpty();`|
|`clear()`|Empty the set|`set.clear();`|

When counting frequency:

```java
map.put(ch, map.getOrDefault(ch, 0) + 1);
```

**Without it:**

```java
if (map.containsKey(ch)) {
    map.put(ch, map.get(ch) + 1);
} else {
    map.put(ch, 1);
}

```

--- 
#### While solving questions related to rotation or anything involving circular remember to use modulo operator 
- example: rotate array by d steps use d %= n (n = length of array).
---
### ASCII Values
#### Uppercase \[A-Z]: 65-90
#### Smallercase: \[a-z]: 97-122
- uppercase to lowercase: +32
- lowercase to uppercase: -32

![[Pasted image 20250903172446.png]]
#### Always do x.equals(y) for comparing string values. For reference comparison do x == y.

---
- String words[] = s.split("\\\s+"); //to convert string to string array