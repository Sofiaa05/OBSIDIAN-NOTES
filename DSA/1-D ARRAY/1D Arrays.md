## Two pointers: 
### Problem 27. Remove Element
https://leetcode.com/problems/remove-element/description/

#### METHOD 1: Extra array:
- count elements exluding target value
- create new array of size counted above
- copy elements excluding targeted value from og to new array
- copy new array to og (indexing to be done of new array)

```java
class Main{
	public static int removeElement(int nums[], int value){
        int i=0; 
		//counting elements excluding target value
		int k = 0;
		for(i=0; i<nums.length; i++){. //O(n)
			if(nums[i] != value) k++;
		}
	//creating new array
		int nums2[] = new int[k];
		i=0; 
		int j=0;
		while(i<nums.length && j<k){ //O(n)
			if(nums[i] != value){
				nums2[j++] = nums[i];
			}
			i++;
		}

	//copying new array to og
		for(i=0; i<k; i++){   //O(n)
			nums[i] = nums2[i];
		}
		return k;
	}
	public static void main(String[] args){
		int nums[] = {0,1,2,2,3,0,4,2};
		int value = 2;
		System.out.println(removeElement(nums,value));
	}
}
```

##### Analysis
|Metric|Your Code|
|---|---|
|**Time Complexity**|`O(n)` ✅|
|**Space Complexity**|`O(n)` ❌ (uses new array)|
#### METHOD 2: In-Place
- using another pointer `index` to track where the next valid element (not equal to value) should go
- modify original array
```java
public Solution{
	class Solution {
    public int removeElement(int[] nums, int val) {
        int index=0;
        for( int i=0; i<nums.length; i++){
            if(nums[i] != val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
}
```

##### Analysis:
| Metric               | In-Place Version    |
| -------------------- | ------------------- |
| **Time Complexity**  | `O(n)` ✅            |
| **Space Complexity** | `O(1)` ✅ (in-place) |

---
### Problem 26: Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

```java
//75% beats
class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0, index=0;
        while(i<nums.length){
            if(nums[i]==nums[index]) i++;
            else{
                nums[index+1] = nums[i];
                i++;
                index++;
            }
        }
        return index+1;
    }
}

// here you dont need to write the else part you can just do
//real solution (100% beats)
class Solution {
    public int removeDuplicates(int[] nums) {
    // i for traversing array and index for tracking next valid element place.
        int i=0, index=0; 
        while(i<nums.length){
            if(nums[i] != nums[index]){
                nums[index+1] = nums[i];
                index++;
            }
            i++; //to be increment in any case so no need to write else case
        }
        return index+1; //returns count 
    }
}
```

### Problem  283:  Move zeroes:
https://leetcode.com/problems/move-zeroes/description/

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        int i = 0, j=0;
        while(i<len){
            if (nums[i] != 0) {
                nums[j++]=nums[i];
            }
            i++;
        }

        while(j<len){
            nums[j++]=0;
        }
    }
}
```

---
### Problem 136: Single Number
(https://leetcode.com/problems/single-number/)

#### Method 1: count frequency of each element and return if count ==1
```java
class Solution {
    public int singleNumber(int[] nums) {
        boolean visited[] = new boolean[nums.length];

        for(int i=0; i < nums.length; i++){
            if(visited[i]) continue;
            int count = 1;
            for(int j = i+1; j < nums.length; j++){
                if( nums[i] == nums[j]){
                    count++;
                    visited[j] = true;
                }
            }
        if(count == 1) return nums[i];
        }
        return -1;
    }
}
```

- ##### Time:  O(n^2)
- ##### Space: O(n)
#### Method 2: xor
```java
class Solution {
    public int singleNumber(int[] nums) {
        // using xor to find unique numbers
        int xor = 0;
        for(int x: nums){
            xor ^= x;
        }
        return xor;
    }
}
```

- ##### Time: O(n)
- ##### Space: O(1)
---
### Missing number

O(n) space O(n)
```java
class Solution {
    public int missingNumber(int[] nums) {
        int res[] = new int[nums.length + 1];

        for (int i = 0; i < nums.length; i++){
            res[nums[i]] = 1;
        }

        for (int i = 0; i < res.length; i++){
            if (res[i] == 0) return i;
        }

        return -1;
    }
}
```

#### Optimised 
```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int expectedSum = n * (n + 1) / 2;
        int resultSum = 0;

        for (int num: nums){
            resultSum += num;
        }

        return expectedSum - resultSum;
    }
}
```

--- 
### Search an element in an array where difference between adjacent elements is 1
- naive solution would be to do a linear search 
- optimised version is given below
```java
class Solution{
	public static int search(int arr[], int target){
		int start = 0;
		int n = arr.length;
		if (n == 0) return -1;
		
		while (start < n){
			if (arr[start] == target) return start;
			
			int diff = Math.abs(target - arr[start]);
			start += diff;
		}
		return -1;
	}
}
```

### Search an element in an array where difference between adjacent elements differ by at most k elements
```java

```

### count anagrams of given word
```java
blic class CountAnagrams{

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