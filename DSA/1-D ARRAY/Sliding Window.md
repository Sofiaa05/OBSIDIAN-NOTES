- with sliding window you iterate over each element only once, reducing overall time complexity to order of n O(N)
- space complexity: O(1)
#### Two types of sliding window:
- Fixed sliding window
- Dynamic sliding window

---
## Fixed Sliding Window
### Problem 643:  Maximum Average subarray I
https://leetcode.com/problems/maximum-average-subarray-i/

#### Method 1: Brute force
- iterate through all possible pairs of window size in array and calculate sum, comparing each window sum and return the max avg from it.

```java
class Solution{
    public double findMaxAverage(int[] nums, int k){
        int n = nums.length;
        int maxSum = Integer.MIN_VALUE;

        //iterate through all possible subarrays of length k
        for(int i = 0; i <= n - k; i++){
            int sum = 0;

            //calculate sum of subarrays starting at index i
            for(int j = i; j < i + k; j++){
                sum += nums[j];
            }
            maxSum = Math.max(maxSum, sum);
        }
        return (double)maxSum/k;
    }
}
```

#### Method 2: Sliding window 
- calculate first window of given size
- calculate next window:
	- remove first element of previous window
	- add newest element in new window

```java
class Solution{
    public double findMaxAverage(int[] nums, int k){
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double maxSum = sum;

        //move to next window by removing the first element and adding the last element in window
        for(int j = 1; j <= nums.length - k; j++){
            sum = sum - nums[j-1] + nums[j+k-1];
            maxSum = Math.max(sum,maxSum);
        }
        return maxSum / k;
    }
}
```

---
## Dynamic Sliding Window

### Problem  3: Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

#### Method 1: HashSet
```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();

        int start =0, end = 0, maxLength = 0;

        while(end < s.length()){
            char current = s.charAt(end);

            if(!set.contains(current)){
                set.add(current);
                end++;
                maxLength = Math.max(maxLength, end - start);
            }
            else{
                set.remove(s.charAt(start));
                start++;
            }
        }
        return maxLength;
    }
}
```

### Algorithm Setup:

We will use:

- `start`: beginning of the sliding window
    
- `end`: end of the sliding window
    
- `HashSet`: to track characters inside the window
    
- `maxLen`: stores the maximum length of substring found so far
#### Method 2: Frequency Array (ASCII Based) (Optimised) 

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int freq[] = new int[128];
        int left = 0, right = 0, maxLength = 0;

        while(right < s.length()){
            char ch = s.charAt(right);

            freq[ch]++;

            while(freq[ch] > 1){
                freq[s.charAt(left)]--;
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
}
```

### Core Logic:

- Create an `int[128]` array to track how many times each character appears in the current window.
    
- Expand the window by moving `end` pointer.
    
- If a character count becomes more than 1 → it's a duplicate → shrink the window from `start` until the window is valid again.
    
- At each step, update `maxLen`.

---
### Problem 121: Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#### Method 1: Brute Force
- A brute force solution would be to check all possible pairs of buy and sell days using two loops —  but that would take O(n²) time, which is inefficient for large inputs.

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;

        // int max = prices[0]; 
        for( int i = 1; i < prices.length; i++){
            for(int j = 0; j <= i; j++){
                int sum = prices[i] - prices[j];
                if(sum > profit){
                    profit = sum;
                }
            }
        }
        return profit;
    }
}
```

#### Method 2: One pass Appraoch
- So instead, I use a **greedy one-pass approach** to solve it in **O(n)** time.

I maintain two variables:

- `minPrice`: the lowest stock price seen so far
    
- `maxProfit`: the maximum profit seen so far
    

As I iterate through the array:

- If the current price is less than `minPrice`, I update `minPrice` because this would be a better day to buy.
    
- Otherwise, I calculate the potential profit using `currentPrice - minPrice`, and update `maxProfit` if it's higher."
```java
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE; //2147483647
        int maxProfit = 0; //return 0 as default if no profit is found

        for(int i = 0; i < prices.length; i++){
            if(prices[i] < minPrice) minPrice = prices[i];
            else{
                int profit = prices[i] - minPrice;
                maxProfit = Math.max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
}
```

#### Method 3: Sliding Window
```java
class Solution {
    public int maxProfit(int[] prices) {
        // Initialize the buy day index to 0 (first day)
        int left = 0;

        // Initialize the sell day index to 1 (next day)
        int right = 1;

        // Variable to store the maximum profit found so far
        int maxProfit = 0;

        // Loop until the right pointer reaches the end of the array
        while (right < prices.length) {

            // If the current sell price is greater than the current buy price
            if (prices[right] > prices[left]) {
                // Calculate the profit if we bought at 'left' and sold at 'right'
                int profit = prices[right] - prices[left];

                // Update maxProfit if this profit is greater than the current maxProfit
                maxProfit = Math.max(maxProfit, profit);
            } else {
                // If the sell price is less than or equal to the buy price,
                // move the buy pointer to the current sell day (a better buying opportunity)
                left = right;
            }

            // Move to the next day to check future selling opportunities
            right++;
        }

        // After checking all days, return the highest profit we could have made
        return maxProfit;
    }
}

```

---

### Problem 76: Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/
#### Method 1: Brute Force 
- Try all substrings of `s`
    
- For each substring, check: **does it contain `t`?**
    
- If yes, and it's smaller than what you've seen before, update your answer
```java
public class Solution {
    public String minWindow(String s, String t) {
        int minLen = Integer.MAX_VALUE;
        String result = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String sub = s.substring(i, j + 1);  // Build substrings from i to j
                if (containsAll(sub, t)) {          // Check if this substring contains all of t
                    if (sub.length() < minLen) {
                        minLen = sub.length();
                        result = sub;
                    }
                }
            }
        }
        return result;
    }

    // Helper to check if all chars in t are in sub (with frequency)
    private boolean containsAll(String sub, String t) {
        int[] subFreq = new int[128]; // ASCII
        int[] tFreq = new int[128];

        for (char ch : sub.toCharArray()) subFreq[ch]++;
        for (char ch : t.toCharArray()) tFreq[ch]++;

        for (int i = 0; i < 128; i++) {
            if (tFreq[i] > subFreq[i]) return false;
        }

        return true;
    }
}

```



| Resource          | Complexity              |
| ----------------- | ----------------------- |
| Time (worst case) | $\boxed{O(n^3 + n^2m)}$ |
| Space             | $\boxed{O(1)}$          |

