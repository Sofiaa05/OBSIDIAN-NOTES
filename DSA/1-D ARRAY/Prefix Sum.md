### CONCEPTUAL KNOWLEDGE
- aka **"Cumulative Sum Arrays"**
- to calculate **sum of array elements within a given range in constant time (O(1)),** instead of running loop again and again for every range, we create an array consisting of cumulative sums of elements once, then use it to solve queries related to sums or subarrays which would take O(n) everytime in worst case.

**Without prefix sum:**
- For each query, you loop through the range → Time = O(n) per query

**With prefix sum:**
- Preprocess the prefix array in O(n)
- Answer each query in O(1)
- Total Time = O(n + q) (q = number of queries)

| Feature             | Brute Force                     | Prefix Sum                      |
| ------------------- | ------------------------------- | ------------------------------- |
| Time for one query  | O(n)                            | O(1)                            |
| Time for multiple q | **O(q * n)** O(n) for q queries | **O(n + q)** O(n) and q queries |
| Space               | O(1)                            | O(n)                            |
| Setup cost          | None                            | One-time O(n)                   |
| Best use case       | Few queries                     | Many queries                    |

- concept learniing code
```java
/* 
----------------------------- EASY --------------------------------
Q1. Given:
arr = [3, 1, 4, 2, 5]
Build the prefix sum array.

Q2. Given:
arr = [2, 2, 2, 2, 2]
What will the prefix sum array look like?

--------------------------- MEDIUM --------------------------------
Q3. Given:
arr = [1, 2, 3, 4, 5]
What’s the sum from index 1 to 3 using prefix sum?

Q4. Sum from index 0 to 2
Sum from index 2 to 4
Sum from index 1 to 3

Q5.  Original Array from Prefix
You’re given the prefix sum: [3, 7, 12, 18]
What was the original array?

Q6. Count Above Threshold
Given:
arr = [1, 2, 3, 4, 5]
Find how many subarrays of size 2 have a sum greater than 5.

*/
import java.util.*;

class Easy{
	public static void q1(){
		int arr[] = {1,2,3,4,5,8,9};
		int prefix[] = new int[arr.length]; //another array of sums of all elements of same size
		prefix[0] = arr[0]; //keeping first element same
		for(int i=1; i<prefix.length; i++){  //running loop from i=1 not i=0 because it is already placed at its position
			prefix[i] = prefix[i-1] + arr[i]; //calculating sum of each element with its previous elements
		}

		//sum from index 1 to 3
		int start = 1, end = 3;
		int sum = prefix[end] - prefix[start-1]; //to find sum in given range
		System.out.println("Sum from index 2 to 4: " + (prefix[4] - prefix[1]));
		System.out.println(" Sum from index 1 to 3: " + (prefix[3] - prefix[0]));
		System.out.println(Arrays.toString(prefix));
		System.out.println("sum from 1 to 3: " + sum);

		// subarrays of size 2 have sum greater than 5
		int count = 0;
		for(int i=0; i <= arr.length-2; i++){
			int summ;
			if (i==0){
				 summ = prefix[1];
			}
			else{
				summ = prefix[i+1] - prefix[i-1];
			}
			if(summ>5){
				count++;
			}
		}
		System.out.println("subarrays of size 2 having sum greater than 5 " + count);		
	}

	static void q2(){
		int arr[] = {2,2,2,2,2};
		int prefix[] = new int[arr.length];
		prefix[0] = arr[0];
		for(int i=1; i<prefix.length; i++){
			prefix[i] = prefix[i-1] + arr[i];
		}
		System.out.println(Arrays.toString(prefix));		
	}

	//going back to original array from sum array
	static void q5(){
		int prefix[] = {3,7,12,18};  
		int arr[] = new int[prefix.length]; //declaring og array as same size
		arr[0] = prefix[0]; //keepign first element same
		for(int i=1; i<prefix.length; i++){ //
			arr[i] = prefix[i] - prefix[i-1]; 
		}  
		System.out.println(Arrays.toString(arr));		
	}
	public static void main(String[] args){
		int arr[] = {3,1,4,2,5};
		q1();
		q2();
		q5();
	}
}

```

## LEETCODE PROBLEMS

### Problem 1480: Running sum of 1d array
https://leetcode.com/problems/running-sum-of-1d-array/description/

```java
class Solution {
    public int[] runningSum(int[] nums) {
        int sum[] = new int[nums.length];
        sum[0] = nums[0];
        for(int i=1; i<sum.length; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        return sum;
    }
}
```
### Problem 303: Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/description/
```java
class NumArray {
    int prefix[];
    public NumArray(int[] nums) {
        prefix = new int[nums.length];
        prefix[0] = nums[0];
        for(int i=1; i<nums.length; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        if (left == 0) return prefix[right]; //because array indexing starts from 0 and there is no other element before this so we just return the rightmost element whenever we are asked to find example [0,2] or [0,5] 
        return prefix[right] - prefix[left-1]; //else for [2,5] we subtract 1 from left element
    } 
}
```

 ### Problem 724: Find pivot index
 https://leetcode.com/problems/find-pivot-index/

#### Code that i wrote:  92% beats 1 ms with space complexity of O(n)

 
 ```java
 class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int leftsum[] = new int[n];
        //sum array
        leftsum[0] = nums[0];
        for(int i=1; i<n; i++){
            leftsum[i] = leftsum[i-1] + nums[i]; 
        }

        int total = leftsum[n-1];
        for(int i=0; i<n; i++){
            if(i==0){
                if(total - 0 == leftsum[i]) return i; 
            }
            else{
                if (total - leftsum[i] == leftsum[i-1]){ //leftsum of i == rightsum of i
                    return i;
                }
            }
        }
        return -1;
    }
}
```

#### Optimised version with O(1) space
```java
class Solution {
    public int pivotIndex(int[] nums) {
        //calculate total sum of array elements
        int total = 0;
        for(int x: nums){
            total += x;
        }

        int leftsum = 0; //leftsum of 0th index element is taken 0
        for(int i=0; i<nums.length; i++){
            int rightsum = total - leftsum - nums[i]; //pivot index should always be excluded thus subtracting nums[i]
            if(rightsum == leftsum) return i;
            leftsum += nums[i]; //calculating running left sum  
        }
        return -1;
    }
}
```

### Medium
### Problem 560: Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/


#### Method 1: Brute Force:
The brute-force idea is:

- Check all **possible subarrays** using **two nested loops**
    
- For each subarray, calculate the **sum** and compare with k.
```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for(int start = 0; start < nums.length; start++){
            int sum = 0;
            for(int end = start; end < nums.length; end++){
                sum += nums[end];

                if(sum == k) count++;
            }
        }
        return count;
    }
}
```

- **Time:** `O(n^2)` — due to nested loops
- **Space:** `O(1)` — no extra data structures used
#### Method 1: (refer notebook) 
```plaintext
Input: nums = [1,1,1], k = 2
Output: 2
```
- as length = 3, subarrays size could either be 1 or 2 (length-1)
- so first calculate sub arrays of size 1, then of 2 and so on until s `size <= length`
```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int prefix[] = new int[nums.length];
		prefix[0] = nums[0]; //keeping first element same
		for(int i=1; i<prefix.length; i++){  //running loop from i=1 not i=0 because it is already placed at its position
			prefix[i] = prefix[i-1] + nums[i]; //calculating sum of each element with its previous elements
		}
        
        int count = 0; //number of sub arrays
      for(int i=1; i<=nums.length; i++){ //for sizing sub arrays.size can be 1 to array.length-1
        for(int j=0; j<=nums.length-i; j++){ //for iterating on sub arrays, to find first and last index of each subarray
        int sum;

            if(i==1){ 
               sum = nums[j]; //subarrays of size 1 will be equal to the array individual elements
            }
            //then we increment size of subarrays next to i=2 then to 3 and so on until stopped by a condition
            else{
                if( j==0 ){
                    sum = prefix[i-1]; //as no elements before 0th index
                }
                else{
                    sum = prefix[j+(i-1)] - prefix[j-1]; //last element of prefix subarray - element before the first element of prefix subarray
                }
            }
            if(sum == k) //checking condition
                count++;
        }
      } 
      return count;
    }
}
```
#### Method 2: prefix sum and hash map
```java
import java.util.HashMap;
import java.util.Map;

class GfG {
    static int cntSubarrays(int[] arr, int k) {
        // HashMap to store prefix sums and their frequencies
        Map<Integer, Integer> prefixSums = new HashMap<>();

        int res = 0;        // number of subarrays found
        int currSum = 0;    // running prefix sum

        for (int i = 0; i < arr.length; i++) {
            // Step 1: add current element to running sum
            currSum += arr[i];

            // Step 2: if the sum from 0..i equals k, we found a subarray
            if (currSum == k) {
                res++;
            }

            // Step 3: check if (currSum - k) exists in map
            // If yes, then some subarray ending here has sum = k
            if (prefixSums.containsKey(currSum - k)) {
                res += prefixSums.get(currSum - k);
            }

            // Step 4: update the frequency of currSum in the map
            if (prefixSums.containsKey(currSum)) {
                // already exists → increment count
                int oldFreq = prefixSums.get(currSum);
                prefixSums.put(currSum, oldFreq + 1);
            } else {
                // first time we see this currSum
                prefixSums.put(currSum, 1);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = {10, 2, -2, -20, 10};
        int k = -10;
        System.out.println(cntSubarrays(arr, k));  // Output: 3
    }
}

```



###  Problem 1991: 
[Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/)
```java
class Solution {
    public int findMiddleIndex(int[] nums) {
        int total = 0;
        
        for (int i = 0; i < nums.length; i++){
            total += nums[i];
        }

        int leftSum = 0;
        for (int i = 0; i < nums.length; i++) {
            int rightSum = total - leftSum - nums[i];

            if (leftSum == rightSum) return i;

            leftSum += nums[i];
        }
        return -1;
    }
}
```

---
### Problem 238: Product of Array itself
#### Method 1: Brute Force
- For each index `i`, loop through the array again and multiply all elements **except `i`**.

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        // Step 1: prefix product
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // Step 2: suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * suffix;
            suffix *= nums[i];
        }

        return result;
    }
}
```
