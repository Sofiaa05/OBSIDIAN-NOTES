| Use Case                 | Loop Condition | Why                                  |
| ------------------------ | -------------- | ------------------------------------ |
| Searching for a value    | `start <= end` | You want to check all elements       |
| Finding min/max/boundary | `start < end`  | You want to stop **at** the boundary |

start = mid+1 or end = mid-1: when finding target
start= mid or end = mid: when finding a boundary (min/max/ first/lastoccurance)
## Leet code Problems:  & GFG Problems (mixed)

## LEETCODE:
## Easy

### Problem 704: (Interviews)
https://leetcode.com/problems/binary-search/description/

```java
class Solution {
    public int search(int[] arr, int target) {
        int start = 0, end = arr.length -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target==arr[mid]) return mid;
            else if (target<arr[mid]) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
}
```

### Problem  35: (Interview)
https://leetcode.com/problems/search-insert-position/?envType=problem-list-v2&envId=binary-search
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0; 
        int end = nums.length-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
    public static void main(String[] args){
        Solution s = new Solution();
        int nums[] = {1,3,5,6};
        int target =5;
        int result = s.searchInsert(nums,target);
        System.out.println(result);
    }
}
```

### Problem 69:
https://leetcode.com/problems/sqrtx/description/?envType=problem-list-v2&envId=binary-search
```java
class Solution {
    public int mySqrt(int x) {
        if (x<2) return x; //edge case when x =1
        int start = 1, end = x/2; //range of numbers for suitable sq roots of a number lies between 1 and x/2
        int result = 0;
        while (start<=end){
            int mid = start+ (end-start)/2;
            long square =  (long) mid * mid; //edge case when x =256843 to avoid integet overflow
            if(x == square) return mid;
            else if(square < x){
                result = mid; //possible answer for when not found perfect square
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return result;
    }
    public static void main(String[] args){
        Solution s = new Solution();
        int result = s.mySqrt(1);
        System.out.println(result);
    }
}
```

### Problem 278: 
https://leetcode.com/problems/first-bad-version/description/

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
		int start = 1, end = n
		while(start<end){
			int mid = start +(end-start)/2;
			if(isBadVersion(mid)){
				end = mid; // mid might be the first bad, so keep it
			}
			else{
				start = mid+1; // first bad must be after mid
			}
		}
		return start; // start will point to the first bad version
	} 
}
```

--- 

## Medium 
### Problem 852:
https://leetcode.com/problems/peak-index-in-a-mountain-array/?envType=problem-list-v2&envId=binary-search

```java
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0, end = arr.length-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr[mid]<arr[mid+1]){
                start = mid+1; // we're on the increasing slope → peak is to the right
            }
            else{
                end=mid;    // we're on the decreasing slope or at the peak
            }
        }
        return start; //can also return end
    }
}
```

### Problem 34: (Interview)
http://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        int result[] = {-1,-1};
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                result[0]=mid;
                end = mid-1;
            }
			else if(target<nums[mid]){
				end = mid -1;
			}
			else{
				start=mid+1;
			}            
        }

        start = 0; end = nums.length-1;  //reset values to find last index with the similar process   
        while(start<=end){
            int mid = start+ (end-start)/2;
            if(nums[mid]==target){
                result[1]=mid;
                start = mid+1;
            }
			else if(target<nums[mid]){
				end = mid -1;
			}
			else{
				start=mid+1;
			}                    
        }
        return result;
    }
}
```

#### Intuition:
#### **First Occurrence (Leftmost index)**:

- Do a **binary search**.
    
- If `nums[mid] == target`, store it in `result[0]`, but **keep searching left** (`end = mid - 1`) to find earlier occurrence.
    

#### 2. **Last Occurrence (Rightmost index)**:

- Do another **binary search**.
    
- If `nums[mid] == target`, store it in `result[1]`, but **keep searching right** (`start = mid + 1`) to find later occurrence.
    

---
### Problem 33: 
https://leetcode.com/problems/search-in-rotated-sorted-array/description/

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0; int right = nums.length-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(target == nums[mid]) return mid;
            
            //left half is sorted
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid -1;
                }
                else left = mid+1;
            }

            //right half is sorted
            else{
                if(target > nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else right = mid-1;
            }
        }
        return -1;
    }
}
```

#### Summary of Logic:

1. Find the middle index.
    
2. If `nums[mid] == target` → return mid.
    
3. If left half is sorted (`nums[left] <= nums[mid]`)
    
    - Check if target lies in it.
        
    - If yes → move `right = mid - 1`
        
    - Else → move `left = mid + 1`
        
4. Else right half is sorted:
    
    - Check if target lies in it.
        
    - If yes → move `left = mid + 1`
        
    - Else → move `right = mid - 1`
### Problem 153: (Interview)
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
```java
class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if (nums[mid]>nums[end]){
                start = mid+1;
            }
            else end = mid;
        }
        return nums[start];
    }
}
```

#### Intuition
Because the rotated array still retains a partially sorted structure.  
At any point in the binary search:

- We can decide which half **must contain** the minimum using a simple comparison.
    
- We don’t **need** to check both sides — we **eliminate half the array each time**.
---
### Problem 162: 
https://leetcode.com/problems/find-peak-element/

```java
class Solution {
    public int findPeakElement(int[] nums) {
        int start = 0;
        int end = nums.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Move left even if both sides could have peaks
                end = mid;
            } else {
                // Keep moving left-ish to try and find the first peak
                start = mid + 1;
            }
        }

        // start == end is a peak
        return start;
    }
}
```

#### summary of logic
Even though the array is **not sorted**, we can still apply **binary search** because of a clever observation:

> **If `nums[mid] > nums[mid + 1]`, there must be a peak on the left side** (including `mid`)  
> **If `nums[mid] < nums[mid + 1]`, there must be a peak on the right side** (excluding `mid`)

This works because:

- If you're on a slope going **down**, then somewhere **before or at** `mid` there's a peak.
    
- If you're on a slope going **up**, then a peak is still coming **ahead**.
---
### Problem 875: Koko eating Bananas
(https://leetcode.com/problems/koko-eating-bananas/)

```java
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = getMax(piles);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, h, mid)) {
                answer = mid;
                high = mid - 1; // try smaller speed
            } else {
                low = mid + 1; // speed too slow
            }
        }

        return answer;
    }

    // Helper: Get max pile (used to set high for binary search)
    private int getMax(int[] piles) {
        int max = 0;
        for (int pile : piles) {
            if (pile > max) max = pile;
        }
        return max;
    }

    // Helper: Simulate eating bananas at speed k and see if it fits in h hours
    private boolean canEatAll(int[] piles, int h, int k) {
        long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; //ceil value
        }
        return hours <= h;
    }
}

```

#### Summary of logic
1. **Goal:**  
    Find the **minimum speed `k`** so Koko can eat all bananas in `≤ h` hours.
    
2. **Why Binary Search?**
    
    - As `k` increases, total time decreases → **monotonic** → perfect for binary search.
        
3. **Binary Search Range:**
    
    - `low = 1`, `high = max(piles)`
        
4. **Key Formula (time for one pile):**
    
    - Time = `(pile + k - 1) / k` → simulates `ceil(pile / k)` using integers
        
5. **Check Function:**
    
    - For a given `k`, sum all pile times
        
    - If `total time ≤ h` → try smaller `k`
        
    - Else → try bigger `k`
        
6. **Use `long` for hours** to prevent overflow on big inputs.
---
---

# GFG

### Problem: Number of occurence / Count Occurrences in a Sorted Array
https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
```java
class Solution {
    int countFreq(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        int first = -1;
        int last = -1;
        
        // Find first occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) {
                first = mid;
                end = mid - 1; // search on the left
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // Find last occurrence
        start = 0;
        end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) {
                last = mid;
                start = mid + 1; // search on the right
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (first == -1 || last == -1) {
            return 0; // target not found
        }
        return last - first + 1;
    }
}

```