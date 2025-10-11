- `StringBuilder` is a class in Java used to create **mutable** (changeable) sequences of characters. 
- Unlike `String`, which is immutable (once created, cannot be changed), `StringBuilder` allows you to modify the content without creating a new object each time.

| Method                   | Description                  |
| ------------------------ | ---------------------------- |
| `append(...)`            | Add data to the end          |
| `insert(offset, ...)`    | Insert data at index         |
| `delete(start, end)`     | Remove characters            |
| `deleteCharAt(index)`    | Remove one character         |
| `replace(start, end, s)` | Replace substring            |
| `reverse()`              | Reverse the sequence         |
| `charAt(index)`          | Get character at index       |
| `setCharAt(index, ch)`   | Replace character at index   |
| `length()`               | Get length                   |
| `capacity()`             | Get capacity                 |
| `ensureCapacity(cap)`    | Make sure capacity is enough |
| `setLength(n)`           | Change current length        |
| `toString()`             | Convert to `String`          |
| `indexOf(String)`        | First index of string        |
| `lastIndexOf(String)`    | Last index of string         |
```java
/*
1. Append Strings
	Write a program to take three strings and join them using StringBuilder.

2. Reverse a String
	Input: "hello" → Output: "olleh" using .reverse().

3.	Insert "Java" at the beginning of a string
*/

/*
1. Check Palindrome using StringBuilder
	Reverse the string and compare with original.

2. Remove all vowels
	Use .deleteCharAt() inside a loop.

3. Capitalize every vowel
	Replace lowercase vowels with uppercase ones.
*/

/*
1. Run-Length Encoding Compression
	Input: "aaabbc" → Output: "a3b2c1"
*/

class MyStringbuilder{
	public static void easy(){
		/*1. Append Strings
			Write a program to take three strings and join them using StringBuilder*/

		String s1 = "sofia";
		String s2 =  "toby";
		String s3 = "mukul";

		StringBuilder sb = new StringBuilder();
		sb.append(s1);
		sb.append(s2);
		sb.append(s3);

		System.out.println(sb);

		/* Reverse a String
			Input: "hello" → Output: "olleh" using .reverse(). 
		*/
		String str = "hello";
		StringBuilder sb2 = new StringBuilder(str);
		System.out.println("Reversed using Strinbuilder: " + sb2.reverse());

		// Insert "Java" at the beginning of a string
		sb.insert(0, "java");
		System.out.println("Inserting java at the beginning: " + sb);
	}

	public static void medium(){
		/* 1. Check Palindrome using StringBuilder
			Reverse the string and compare with original. */
			String str = "radar";
			StringBuilder sb = new StringBuilder(str);
			if(str.equals(sb.reverse().toString())){
				System.out.println("yes it is a palindrome.");
			}
			else{
				System.out.println("no it is not a palindrome.");
			}

		/*
		 Remove all vowels
		 Use .deleteCharAt() inside a loop. */

		//  for(int i=0; i<sb.length(); i++){
		//  	if("aeiouAEIOU".contains(String.valueOf(sb.charAt(i)))){
		//  		sb.deleteCharAt(i);
		//  		i--;
		//  	}
		//  }
	 	System.out.println(sb);

	 	/*Capitalize every vowel
	   	Replace lowercase vowels with uppercase ones. */
	   	for(int i=0; i<sb.length(); i++){
	   		if("aeiouAEIOU".contains(String.valueOf(sb.charAt(i)))){ //using valueOf to convert char to string because contains() work only for strings nto chars
				//can also do: if ("aeiouAEIOU".indexOf(currentChar) != -1) //if current characteris not present in string of vowels

				sb.setCharAt(i, Character.toUpperCase(sb.charAt(i))); 	   		}
	   	}
	   	System.out.println("Uppercase Vowels" + sb);

	}

	public static void advanced(){
		String str = "aaabc";
		StringBuilder sb = new StringBuilder(str);

		for (int i=0; i<sb.length(); i++ ) {
			for (int j=0; j<sb.length();  j++ ) {
				int count = 0;
				char ch = sb.charAt(i);
				if(ch == sb.charAt(j)){
					count++;
				}
				sb.append(ch).append(count);
			}
		}
		System.out.println(sb);
	}

	public static void main(String[] args){
		easy();
		medium();
		advanced();
	}
}
```

### Practice Problems:
```java

```/* Easy
1. Append Strings
	Write a program to take three strings and join them using StringBuilder.

2. Reverse a String
	Input: "hello" → Output: "olleh" using .reverse().

3.	Insert "Java" at the beginning of a string
*/

/*
1. Check Palindrome using StringBuilder
	Reverse the string and compare with original.

2. Remove all vowels
	Use .deleteCharAt() inside a loop.

3. Capitalize every vowel
	Replace lowercase vowels with uppercase ones.
*/

/*
1. Run-Length Encoding Compression
	Input: "aaabbc" → Output: "a3b2c1"
*/

class MyStringbuilder{
	public static void easy(){
		/*1. Append Strings
			Write a program to take three strings and join them using StringBuilder*/

		String s1 = "sofia";
		String s2 =  "toby";
		String s3 = "mukul";

		StringBuilder sb = new StringBuilder();
		sb.append(s1);
		sb.append(s2);
		sb.append(s3);

		System.out.println(sb); //OUTPUT: sofiatobymukul

		/*2.  Reverse a String
			Input: "hello" → Output: "olleh" using .reverse(). 
		*/
	//using builtin function ( can also do manually using loop)
		String str = "hello";
		StringBuilder sb2 = new StringBuilder(str);
		System.out.println("Reversed using Strinbuilder: " + sb2.reverse());
		//OUTPUT; Reversed using Strinbuilder: olleh

		// 3. Insert "Java" at the beginning of a string
		sb.insert(0, "java");
		System.out.println("Inserting java at the beginning: " + sb);
		//OUTPUT: Inserting java at the beginning: javasofiatobymukul
	}

	public static void medium(){
		/* 1. Check Palindrome using StringBuilder
			Reverse the string and compare with original. */
			String str = "radar";
			StringBuilder sb = new StringBuilder(str);
			
			if(str.equals(sb.reverse().toString())){
				System.out.println("yes it is a palindrome.");
			}
			else{
				System.out.println("no it is not a palindrome.");
			}
			//OUTPUT: yes it is a palindrome.

		/* 2. Remove all vowels
		   		Use .deleteCharAt() inside a loop. */

		 for(int i=0; i<sb.length(); i++){
		 	if("aeiouAEIOU".contains(String.valueOf(sb.charAt(i)))){
		 		sb.deleteCharAt(i);
		 		i--;
		 	}
		 }
	 	System.out.println(sb); //OUTPUT: rdr

	 	/* 3. Capitalize every vowel
	   	Replace lowercase vowels with uppercase ones. */
		String str2 = "mukul";
		StringBuilder sb2 = new StringBuilder(str2);
	   	for(int i=0; i<sb2.length(); i++){
	   		if("aeiouAEIOU".contains(String.valueOf(sb2.charAt(i)))){ //using valueOf to convert char to string because contains() work only for strings nto chars
				//can also do: if ("aeiouAEIOU".indexOf(currentChar) != -1) //if current characteris not present in string of vowels

				sb2.setCharAt(i, Character.toUpperCase(sb2.charAt(i)));  //to convert a character to upper case use Uppercase(character).	   		}
	   	}
	   	System.out.println("Uppercase Vowels " + sb2); //OUTPUT: mUkUl
	}

	// 4. Replace spaces with %20 (like URL encoding)

	public static void spaceURL(){
	    String str = "sofia is fine and happy";
	    StringBuilder sb = new StringBuilder(str);
	    for(int i=0; i<sb.length(); i++){
	    	if(sb.charAt(i) == ' '){
			    sb.replace(i, i+1, "%20");
			}
	    }
	    System.out.println(sb); //OUTPUT: sofia%20is%20fine%20and%20happy
	 }

	//Compress a string (e.g., aaabb → a3b2)
	 public static void compression(){
	 	String str = "aaabc";
	 	StringBuilder sb = new StringBuilder();
	 	int count = 1;
	 	for( int i = 0 ; i < str.length() - 1; i++){
	 		if(str.charAt(i) == str.charAt(i+1)){
	 			count++;
	 		}
	 		else{
				sb.append(str.charAt(i));
		 		sb.append(count);
		 		count = 1;
		 	}
	 	}
	 	sb.append(str.charAt(str.length() - 1));
		sb.append(count);

	 	System.out.print("Compressed String: " + sb); //OUTPUT: Compressed String: a3b1c1
	 }
	 
	public static void main(String[] args){
		easy();
		medium();
		spaceURL();
		compression();
	}
}