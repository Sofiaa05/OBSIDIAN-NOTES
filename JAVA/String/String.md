
- when we create a string using `string literal` then an object is created in string pool. and when again the same string is created, new object is not created and the reference to that string will point to the object already created in string pool.
- when we create a string using `new` then, two objects are created:  one is in heap and other in string pool, but if it exists in pool already then only object in heap is created not in pool.

![[Pasted image 20250329220842.png]]

### Creating String
- using `String` literal.
- using `new` keyword (creating string object)
- using `char array`
- using `byte array`. 
```java

public class Strings {
    public static void main(String[] args) {
        String str1 = "String is created using string literal";
        System.out.println(str1);

        String str2 = new String("String is created using new keyword");
        System.out.println((str2));

        System.out.println("String is created using char array: ");
        char c[] = {'H','e','l', 'l', 'o'};
        String str3 = new String(c);
        System.out.println(str3);

        System.out.println("String is created using byte array: ");
        byte b[] = {67,68,69,70};
        String str4 = new String(b,1 ,2); // can spcify starting index and length
        System.out.println(str4);

        //string pool
        String str5 = "JAVA";
        String str6 = "JAVA";  
        String str7 = new String("JAVA");  
        System.out.println(str5==str6); //str5 and str6 both pointing to same object in string pool hence true
        
        System.out.println(str6==str7); // returns false as new object will be created in heap hence they are not same
    }
}

```

---
### String Methods
```java

public class StringMethods {
    public static void main(String[] args) {
        String str = new String("www.youtube.com");
        System.out.println(str.length());  //gives length of string
        System.out.println(str.toUpperCase()); 
        System.out.println(str.toLowerCase());
        System.out.println(str.trim()); //removes leading and trailing spaces
        System.out.println(str.substring(3)); //gives substring from given string
        System.out.println(str.substring(3,7)); //ending index is exclusive
        System.out.println(str.replace('e','o') + " " + str);
        System.out.println(str.startsWith("Net")); //boolean value
        System.out.println(str.endsWith("eans")); //booean value
        System.out.println(str.charAt(str.length()-4)); //fetches the character at index 11 (0-based indexing).
        System.out.println(str.indexOf(".",4)); //11
        System.out.println(str.indexOf("sofia")); //-1 (not present)
        System.out.println(str.lastIndexOf(".")); //index of "." staring from last

        String str1 = "JAVA";
        String str2= "java";
        String str3= "Python";
        String str4= "python";
        String str5 = new String("java");
        System.out.println(str4.equals(str3)); //false
        System.out.println(str1.equalsIgnoreCase(str2)); //true
        System.out.println(str3.compareTo(str4)); //ASCII value of Python is less than python hence -ve
        System.out.println(str4.compareTo(str3)); //ASCII value of python is more than Python hence +ve
        System.out.println(str2.equals(str5)); //true (compares string literal value)
        System.out.println(str2==str5); // false (compares references)
        System.out.println(str.valueOf(5));
        System.out.println(str.contains("you")); //to check if given substring is present or not
    }
}

```

##### NOTE:
- `equalsTo()` compares string literal values not references. always use this to compare two strings or a substring.
- `'=='` compares references to string literals not their value.
---
### String Regular Expressions matching:

Here’s a **table of commonly used regular expressions (regex) in Java** for `String` operations:

| **Regex Pattern** | **Meaning**                                      | **Example Match**                                        |
| ----------------- | ------------------------------------------------ | -------------------------------------------------------- |
| `.`               | Any single character except a newline            | `"a"`, `"9"`, `"@"`                                      |
| `\\d`             | Any digit (0-9)                                  | `"5"`, `"8"`                                             |
| `\\D`             | not digit                                        | `"a"`, `"$"`                                             |
| `\\w`             | Any word character (alphabet, digit, underscore) | `"A"`, `"5"`, `"_"`                                      |
| `\\W`             | neither alphabet nor digit                       | `"@"`, `" "`                                             |
| `\\s`             | Any whitespace character (space, tab, newline)   | `" "`, `"\n"`                                            |
| `\\S`             | not space                                        | `"A"`, `"1"`                                             |
| `^`               | Start of the string                              | `^Hello` matches `"Hello world"` but not `"Hi Hello"`    |
| `$`               | End of the string                                | `world$` matches `"Hello world"` but not `"world hello"` |
| `*`               | 0 or more occurrences of the previous character  | `"a*"` matches `""`, `"a"`, `"aaaa"`                     |
| `+`               | 1 or more occurrences of the previous character  | `"a+"` matches `"a"`, `"aaa"`, but not `""`              |
| `?`               | 0 or 1 occurrence of the previous character      | `"a?"` matches `""` or `"a"`                             |
| `{n}`             | Exactly `n` occurrences                          | `"a{3}"` matches `"aaa"`                                 |
| `{n,}`            | At least `n` occurrences                         | `"a{2,}"` matches `"aa"`, `"aaa"`, `"aaaa"`              |
| `{n,m}`           | Between `n` and `m` occurrences                  | `"a{2,4}"` matches `"aa"`, `"aaa"`, `"aaaa"`             |
| `                 | `                                                | OR operator                                              |
| `[]`              | Character class (any character inside)           | `"[aeiou]"` matches `"a"`, `"e"`, `"o"`                  |
| `[^ ]`            | Negated character class (not inside)             | `"[^aeiou]"` matches `"b"`, `"c"`                        |
| `( )`             | Capturing group                                  | `"(ab)+"` matches `"ab"`, `"abab"`                       |
| `(?i)`            | Case-insensitive match                           | `"(?i)hello"` matches `"Hello"`, `"HELLO"`               |
| `\\b`             | Word boundary                                    | `"\bcat\b"` matches `"cat"` but not `"category"`         |
| `\\B`             | Not a word boundary                              | `"\Bcat\B"` matches `"category"` but not `"cat"`         |
![[Pasted image 20250330152130.png]]

---
##### FEW EXAMPLES: 

```java

import java.util.Scanner;

public class StringMatch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an email.id: ");

        String str = sc.nextLine();
        //find if email id is on gmail
        System.out.println("Is the email id on gmail?");
        System.out.println(str.matches(".*gmail.*"));  
        
        //find username and domain name from email
        System.out.println("Domain name of email is: ");
        System.out.println(str.substring(str.indexOf('@')+1));

        System.out.println("Username : ");
        System.out.println(str.substring(0,str.indexOf('@')));      
    }    
}

```

---
```java
        //to check if a number is binary or not
    int b = 1011001;
    String str1 = String.valueOf(b); //to convert int to string, or you can do
    
        // String str1 = b +"";
    System.out.println(str1.matches("[01]+"));

        //to check if  a number is hexadecinal or not
    String str2 = "9B8069A";
    System.out.println(str2.matches("[0-9A-F]*"));

        //Find if data is in date format(dd//mm//yyyy)
    String d = "3/12/2000";
    System.out.println((d.matches("(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([0-9]{4})")));
    
```

---
```java  
        //removes special characters from string
        String str3 = "a!B@c#1$2%3";
        System.out.println("After removing special characters");
        System.out.println(str3.replaceAll("[^\\w]","" ));

        //remove extra spaces from string
        String str4 = "    abc    de    fgh  ij k    lm     ";
        System.out.println(str4.replaceAll("\\s+"," ").trim());

        //find number of words in a string 
        String str5 = str4.replaceAll("\\s+"," ").trim(); // to prevent multiple spaces from being counted as separate words.
        
        String words[] = str5.split("\\s");  //Splits str5 into an array of words wherever there is a space
        
        System.out.println("number of words in given string is: " + words.length);

```