- **divide a string into parts** based on a given **delimiter** (like a space, comma, or any character/pattern), and it returns an **array of strings**.

```java
/*
q1. Split a sentence into words
	Input: "Java is powerful"

q2. count frequency of each word

q3. Reverse the order of words
	Input: "one two three"
	Output: "three two one"

q4. Find the longest word in a sentence
	Input: "Java is beautiful"
	Output: "beautiful

q5. Capitalize the first letter of each word
	Input: "hello world"
	Output: "Hello World"
*/
class Split{
	public static void q1(){
		String str = "Java is powerful Is";
		String str2 = "java,is,powerful";
		String[] words = str.split(" ");
		System.out.println("Split by spaces");
		for(String s: words){
			System.out.println(s);
		}

		//count frequency of each word
		boolean visited[] = new boolean[words.length]; //to keep track of string already counted and preventing double counting
		for(int i=0; i<words.length; i++){
			if(visited[i]) continue; //to preventing double counting

			int count = 0; //initialisng 0 for each new string

			for(int j=0; j < words.length; j++){
				if(words[i].equalsIgnoreCase(words[j])){ //ignore cases and check if string content is equal or not
					count++;
					visited[j] =  true;
				}
			}
			System.out.println(words[i] + ": " + count);
		}

		//count frequency of each character
		boolean visited2[] = new boolean[str.length()];
		str = str.toLowerCase(); //ignore cases
		for(int i=0; i<str.length(); i++){
			if (str.charAt(i) == ' ' || visited2[i]) continue; //ignore spaces and characters already counted
			int count2 = 0;
			for(int j=0; j<str.length(); j++){
				if(str.charAt(i) ==  str.charAt(j)){
					count2++;
					visited2[j] = true;
				}
			}
			System.out.println(str.charAt(i) + ": " + count2);
		}

		System.out.println("Number of words in string: " + words.length);
		System.out.println("Split by comma");
		String[] words2 = str2.split(",");
		for(String s: words2){
			System.out.println(s);
		}
	}

	public static void q2(){
		String str = "java is beautiful";
		//reverse order of words
		String rev = "";
		String words[] = str.split(" ");
		for(int i = words.length - 1; i >= 0; i--){
			rev = rev.concat(words[i] + " ");
		}
		System.out.println(rev);

		//longest word in a sentence:
		String longest = words[0];
		for(int i=1; i < words.length; i++){
			if(words[i].length() > longest.length()){
				longest = words[i];
			}
		}
		System.out.println("longest word = " + longest);
	}

	public static void q5(){
		String str = "sofia loves mukul, but he loves her more";
		String words[] = str.split(" ");
		String cap = "";

		for(int i=0; i < words.length; i++){
			String first = words[i].substring(0,1).toUpperCase();
			String rest = words[i].substring(1);
			cap += first + rest + " "; 
		}
		System.out.println(cap.trim());
	}
	public static void main(String[] args){
		q1();
		q2();
		q5();
	}

}
```
### Problem 151. Reverse words in a string

#### Method 1: using strings
```java
class Solution {
    public String reverseWords(String s) {
       s = s.trim();
       String words[] = s.split("\\s+");
       String rev = "";
		for(int i = words.length - 1; i >= 0; i--){
			rev = rev.concat(words[i] + " ");
		}
		return rev.trim();
    }
}
```

#### Method 2: using stringbuilder
todo (https://leetcode.com/problems/reverse-words-in-a-string/)
```java
StringBuilder sb = new StringBuilder();
```