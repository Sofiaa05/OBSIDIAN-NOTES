
### Program: Finding maximum element
```java
		int A[] = {223,34,56,78,89,0};

		int max = A[0];

		for(int x : A){
			if(x > max){
				max = x
			}
		}
		System.out.println("Maximum Element = " + max);
	}
}
```

```plaintext
OUTPUT:

Maximum Element = 223
```

### Program : Second largest element
```java
public class SecondMax {
    public static void main(String[] args) {
        int A[] = {-223, -34, -56, -78, -89, -89};

        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;

        for (int x : A) {
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2 && x != max1) {
                max2 = x;
            }
        }

        System.out.println("Maximum Element = " + max1);
        if (max2 != Integer.MIN_VALUE)
            System.out.println("Second Maximum Element = " + max2);
        else
            System.out.println("Second Maximum Element not found (all elements equal?)");
    }
}

```

```plaintext
Maximum Element = -34
Second Maximum Element = -56
```
---
### Problem 238: Move Zeroes
https://leetcode.com/problems/move-zeroes/) 
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
```

---

### Reverse an array:
```java
public static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
```
### Problem 1: Two Sum
 https://leetcode.com/problems/two-sum/

#### Method 1: Brute force
 - Time: O(n^2)
 - Space: O(1)
```java
public class Solution {
    public static int[] twoSum(int[] nums, int target) {

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int val = nums[i] + nums[j];
                if (val == target) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] {-1,-1};
    }
}
```

#### Method 2: HashMap
- Time:  O(N)
- Space: O(N)

```java
import java.util.HashMap;

public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store number → index
        HashMap<Integer, Integer> map = new HashMap<>();

        // Traverse the array
        for (int i = 0; i < nums.length; i++) {
            int current = nums[i];                   // Current number
            int complement = target - current;       // Number needed to reach target

            // Check if complement is already in the map
            if (map.containsKey(complement)) {
                // Found the pair! Return their indices
                return new int[] { map.get(complement), i };
            }

            // If not found, store the current number and its index
            map.put(current, i);
        }

        // If no pair found (though question says there will always be one)
        return new int[] { -1, -1 };
    }
}
```

---
### Problem 242: Valid Anagram
https://leetcode.com/problems/valid-anagram/

#### Method 1: Sort both strings and compare

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

            char[] a = s.toCharArray();
            char[] b = t.toCharArray();

            // Manually sort both arrays using bubble sort
            bubbleSort(a);
            bubbleSort(b);

            // Compare manually
            for (int i = 0; i < a.length; i++) {
                if (a[i] != b[i]) return false;
            }
            return true;
        }

        static void bubbleSort(char[] arr) {
            int n = arr.length;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        // Swap arr[j] and arr[j+1]
                        char temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
//time: O(n^2), space: O(n)

// or
//with out inbuilt functions
import java.util.Arrays;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        char[] a = s.toCharArray();
        char[] b = t.toCharArray();

        Arrays.sort(a);
        Arrays.sort(b);

        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) return false;
        }

        return true;
    }
}

//Time: O(n log n)  
// Space: O(n)
```

#### Method 2: HashMap
- time: O(n)
- space: O(n)
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        HashMap <Character, Integer> map = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            char current = s.charAt(i);
            if(map.containsKey(current)){
                map.put(current, map.get(current) + 1);
            }
            else{
                map.put(current, 1);
            }
        }

        for(int i = 0; i < t.length(); i++){
            char current = t.charAt(i);
            if(!map.containsKey(current)){
                return false;
            }
            map.put(current, map.get(current) - 1);
            if (map.get(current) < 0) {
                return false;
            }
        }
        return true;
    }
}
```

#### Method 3:  Frequency Array
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        
        int freq1[] = new int[26];
        int freq2[] = new int[26];

        char[] ch1 = s.toCharArray();
        char[] ch2 = t.toCharArray();

        for(int i = 0; i < ch1.length; i++){
            freq1[ch1[i] - 'a']++;
            freq2[ch2[i] - 'a']++;
        }

        //compare both arrays
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]) return false;
        }

        return true;
    }
}
```

---
### Count anagrams

find anagram number given string horse then find how many anagram
number in array [hoser, seroh, ohser, horsse, gohmer].
```java
public class CountAnagrams{

	private static boolean isAnagram(String target, String str){
		if (target.length() != str.length()) return false;

		int freq1[] = new int[26];
		int freq2[] = new int[26];

		char ch1[] = target.toLowerCase().toCharArray(); //handle capital letters 
		char ch2[] = str.toLowerCase().toCharArray();

		 for (int i = 0; i < ch1.length; i++) {
            if (ch1[i] >= 'a' && ch1[i] <= 'z') freq1[ch1[i] - 'a']++;
            else return false; // invalid character

            if (ch2[i] >= 'a' && ch2[i] <= 'z') freq2[ch2[i] - 'a']++;
            else return false; // invalid character
        }

		for (int i = 0; i < 26; i++){
			if (freq1[i] != freq2[i]) return false;
		}
		return true;
	}

	public static void main(String[] args) {
		int count = 0;
		String target = "horse";
		String arr[] = {"hoser", "seroh", "ohser", "horsse", "gohmer"};

		for (String toCheck: arr) {
			if (isAnagram(target, toCheck))
				count++;
		}
		System.out.println(count);
	}
}
```

### Problem 217: Contains Duplicates
https://leetcode.com/problems/contains-duplicate/

#### Method 1: Sorting and comparing adjacent
- time: O(n logn)
- space: O(1)
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);  //O (n logn) 
        for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] == nums[i+1]) {
                    return true;
                }
        }
        return false;
    }
}
```

#### Method 2: HashMap
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                return true;
            }
            map.put(nums[i],1);
        }
        return false;
    }
}
```

#### Method 3: HashSet

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet <Integer> set = new HashSet<>();
        for(int num : nums){
            if(set.contains(num)) return true;
            else set.add(num);
        }
        return false;
    }
}
```

---

### Problem 387:  First Unique Character in a String
https://leetcode.com/problems/first-unique-character-in-a-string/

#### Method 1: Brute Force
- time:  O(n^2)
- space: 

```java
class Solution {
    public int firstUniqChar(String s) {
        for(int i=0; i<s.length(); i++){
            int count = 0 ;
            for(int j=0; j<s.length(); j++){
                if(s.charAt(i) == s.charAt(j)) count++;
            }
            if(count == 1) return i;
        }
        return -1;
    }
}
```

#### Method 2: HashMap
```java
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();

        for (char a : s.toCharArray()) {
            mp.put(a, mp.getOrDefault(a, 0) + 1);
        }

        for (int i = 0; i < s.length(); i++) {
            if (mp.get(s.charAt(i)) == 1) {
                return i;
            }
        }

        return -1;
    }
}
```

#### Method 3: Frequency Array

```java
class Solution {
    public int firstUniqChar(String s) {
        int freq[] = new int[26]; //frequency array of alphabets count

        char[] ch = s.toCharArray();

        //incrementing value of each alphabets ascii value
        for(int i = 0; i < ch.length; i++){
            if(ch[i] >= 'a' && ch[i] <= 'z'){
                freq[ch[i] - 'a']++;
            }
        }

        //cheking first non repeating character i.e frequency value of 1
        for(int i = 0; i < 26; i++){
            if(freq[ch[i] - 'a'] == 1) return i;
        }

        return -1;

    }
}
```
---
### First unique number in array / first non-repeating number in array

#### Brute Force:

```java
	public static int firstUnique(int arr[]){
		
		for (int i = 0; i < arr.length; i++) {
			int count = 0;
			for (int j = 0; j < arr.length; j++) {
				if (arr[i] == arr[j]) {
					count++;
					break;
				}
			}
			if (count == 1) return arr[i];
		}
		return -1;
	}
```

#### Optimised (HashMap)
```java
	public static int firstUnique(int arr[]){
		
		HashMap<Integer, Integer> map = new HashMap<>();

		for (int num: arr) {
			if (map.containsKey(num)) {
				map.put(num, map.get(num) + 1);
			}
			else{
				map.put(num, 1);
			}	
		}

		for (int num: arr){
			if (map.get(num) == 1) return num;
		}
		return -1;
	}
```

### Problem 287: Find the Duplicate Number

#### Method 1: Brute Force O(n^2)

```java
class Solution {
    public int findDuplicate(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            int count = 1;
            for(int j = i+1; j < nums.length; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
                if(count > 1) return nums[i];
            }
        }
        return -1;
    }
}
```

#### Method 2: Sorting O(n logn)
 
```java

```
#### Method 3: Frequency Array O(n) both time and space
```java
class Solution {
    public int findDuplicate(int[] nums) {
        int freq[] = new int[127];

        for(int i = 0; i < nums.length; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
}
```

#### Method 4: Hashmap O(n) time and space
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findDuplicate(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);

            if (freqMap.get(num) > 1) {
                return num; // found the duplicate
            }
        }

        return -1; // theoretically should never happen given constraints
    }
}
```

#### Method 5: Fast and slow pointers

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        //reset slow to 0, and move slow and fast one step till they meet
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
}
```

- **Two runners** — slow (tortoise) and fast (hare) — start at index `0`.
- Move:
    
    - Slow → 1 step at a time (`slow = nums[slow]`)
    - Fast → 2 steps at a time (`fast = nums[nums[fast]]`)  
        They meet **inside the cycle**.
        
- Reset one pointer to start (`0`) and move **both one step at a time**.
    
- The point they meet again is the **duplicate number**.

![[Pasted image 20250809233346.png]]

### 1207. Unique Number of Occurrences (https://leetcode.com/problems/unique-number-of-occurrences/)

```java
import java.util.*;

public class UniqueOccurrences {
    public static boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        // Step 1: Count frequencies
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Step 2: Check for unique frequencies
        Set<Integer> freqSet = new HashSet<>();

        for (int count : freqMap.values()) {
            // If already exists, it's not unique
            if (!freqSet.add(count)) {
                return false;
            }
        }

        return true;
    }

    // Test
    public static void main(String[] args) {
        int[] arr = {1, 2, 2, 1, 1, 3};
        System.out.println(uniqueOccurrences(arr));  // Output: true
    }
}

```

### Count distinct elements
A sorted array given find the How many unique element in Array....
EX: [23, 56, 47, -23, 58] ans 4; (23 and -23 count 1)

```java
// User function Template for Java
class Solution {
    static int distinct(int arr[]) {
        // code here
        HashSet<Integer> set = new HashSet<>();
        
        for (int num: arr){
            set.add(Math.abs(num));
        }
        return set.size();
    }
}
```

