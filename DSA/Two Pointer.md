### Problen 238: Move Zeroes 
https://leetcode.com/problems/move-zeroes/
```java
class Solution{
    public void moveZeroes(int[] nums){
        int left = 0; //pointer for next non zero element
        for(int right = 0; right < nums.length; right++){ //iterating pointer for next non zero element
            if(nums[right] != 0){
                //swap elements if right pointer finds a non zero pointer
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++; //move left pointer forward
            }
        }
    }
}

//My solution: 
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j = 0;
        while (i < nums.length && j < nums.length) {
            if (nums[i] == 0 && nums[j] == 0) {
                j++; // advance j too
            }
            else if (nums[i] == 0 && nums[j] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++; // move i too after swap
            }
            else if (nums[i] != 0 && nums[j] == 0) {
                j++; // keep both in sync
            }
            else{
                i++;
                j++;
            }
        }
    }
}

```
---
### Problem 11: Container with most water
https://leetcode.com/problems/container-with-most-water/
#### Method 1: Brute force (On^2)

```java
class Solution{
    public int maxArea(int[] height){
        int maxArea = 0;
        int n = height.length;

        //check all pairs (i,j)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int minHeight = Math.min(height[i], height[j]);
                int width = j - i; //disatnce between lines
                int area = minHeight * width;

                maxArea = Math.max(maxArea, area);
            }
        }
        return maxArea;
    }
}
```

#### Method 2: Two pointer Appraoch (O(n))
```java
class Solution{
    public int maxArea(int[] height){

//start with container with maximum width which would be when start and end are farthest apart
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0; //to keep track of largest area found so far

        while(left <= right){
            int minHeight = Math.min(height[left], height[right]);
            int width = right - left;
            int area = minHeight * width;
            maxArea = Math.max(area, maxArea);

//move the pointer pointing to the shorter height because height and width are to be kept maximmum to get maximum area
            if(height[left] < height[right]){
                left++; //move left pointer forward
            }
            else{
                right--; //move right pointer forward
            }
        }
        return maxArea;
    }
}

```

---
### Problem 167:   Two Sum II - Input Array Is Sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;

        while(start < end){
            int sum = numbers[start] + numbers[end];

            if(sum == target){
                return new int[]{start + 1, end + 1};
            }
            else if(sum < target){ //since array is sorted 
                start++;
            }
            else{
                end--;
            }
        }
        return new int[]{-1, -1};
    }
}
```

---
### Problem 125: Valid Palindrome
https://leetcode.com/problems/valid-palindrome/
#### 1. Without two pointer

```java
public class Solution {
    public boolean isPalindrome(String s) {
        // Step 1: Clean the string
        StringBuilder cleaned = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                cleaned.append(Character.toLowerCase(c));
            }
        }

        // Step 2: Check if cleaned string is same as its reverse
        String cleanedStr = cleaned.toString();
        String reversedStr = cleaned.reverse().toString();

        return cleanedStr.equals(reversedStr);
    }
}
```

#### 2. With Two pointers

```java
class Solution {
    public boolean isPalindrome(String s) {
        if (s.isEmpty()) {
        	return true;
        }
        int start = 0;
        int last = s.length() - 1;
        while(start <= last) {
        	char currFirst = s.charAt(start);
        	char currLast = s.charAt(last);
        	if (!Character.isLetterOrDigit(currFirst )) {
        		start++;
        	} else if(!Character.isLetterOrDigit(currLast)) {
        		last--;
        	} else {
        		if (Character.toLowerCase(currFirst) != Character.toLowerCase(currLast)) {
        			return false;
        		}
        		start++;
        		last--;
        	}
        }
        return true;
    }
}
```

___
### Problem 344: Reverse a string
https://leetcode.com/problems/reverse-string/

```java
class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length - 1;

        while (left < right) {
            // Swap characters
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            // Move pointers
            left++;
            right--;
        }
    }
}
```

---
### Problem 151: Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/
```java
class Solution {
    public String reverseWords(String s) {
       s = s.trim();
       String words[] = s.split("\\s+"); //to convert string to string array

        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            sb.append(words[i]);
            if (i != 0) {
                sb.append(" ");
            }
        }

        return sb.toString();
    }    
}
```

---
### Problem 345:  Reverse Vowels of a String 
https://leetcode.com/problems/reverse-vowels-of-a-string/

```java
class Solution  {
    public String reverseVowels(String s){
        char[] chars = s.toCharArray();

        //using two pointer solution.
        int start =0;
        int end = chars.length-1;

        while (start<end) {

            //if isVowel = true, break out of while loop and check for end pointer
            while(start<end && !isVowel(chars[start])){
                start++;
            }

            //if isVowel = true for end pointer, then break out of while loop 
            //and perform reverse function between start and end pointer
            while (start<end && !isVowel(chars[end])) {
                end--;
            }

            //reverse code:
            char temp=chars[start];
            chars[start]=chars[end];
            chars[end]=temp;

            start++;
            end--;
        }
        return new String(chars);
    }

    //method to check vowel:
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