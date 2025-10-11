 
 ### Searching (done)
 
 ###  Boyer-Moore voting algorithm(DONE)

### Kadane's Algorithm
### Hashing

### Two Pointers (DONE)
- **pair sum**, **remove duplicates**, **reverse words**

### Sorting

### In place (done)

### Sliding Window
### Prefix sum/difference (DONE)

### Backtracking
### Recursion


---

# ✅ Optimization Techniques in Arrays & Strings

---

## 🔹 **Boyer-Moore Voting Algorithm**

### 🔸 **Intro:**

Finds the **majority element** (> n/2 times) in linear time and constant space.

### 🔸 **Use Cases:**

- Find majority element in a list
    
- Electoral vote winner (simple case)
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n)
    
- 💾 Space: O(1)
    

### 🔸 **LeetCode:**

- Easy: [169. Majority Element](https://leetcode.com/problems/majority-element/)
    
- Harder: [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) (modified)
    

### 🔸 **Why preferred:**

- 💥 Over hashing (which takes O(n) space)
    
- 👑 Constant space and simple
    

---

## 🔹 **Kadane's Algorithm**

### 🔸 **Intro:**

Finds the **maximum sum of a contiguous subarray** using a dynamic programming concept in linear time.

### 🔸 **Use Cases:**

- Max subarray sum
    
- Stock price profit (single transaction)
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n)
    
- 💾 Space: O(1)
    

### 🔸 **LeetCode:**

- Easy: [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
    
- Medium: [918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)
    
- Medium: [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
    

### 🔸 **Why preferred:**

- 🚀 O(n) vs brute-force O(n²)
    
- ✅ Best for "contiguous subarray sum" type problems
    

---

## 🔹 **Hashing**

### 🔸 **Intro:**

Maps data to quick-access keys (hash maps/sets) to check frequencies, existence, etc.

### 🔸 **Use Cases:**

- Detect duplicates
    
- Frequency counting
    
- Map value to index
    
- Check if subarray sum exists
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n) average
    
- 💾 Space: O(n)
    

### 🔸 **LeetCode:**

- Easy: [1. Two Sum](https://leetcode.com/problems/two-sum/)
    
- Medium: [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
    
- Medium: [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)
    

### 🔸 **Why preferred:**

- 🔥 Replaces nested loops with O(1) lookups
    
- 🧠 Great for counting, mapping, lookups
    

---

## 🔹 **Two Pointers**

### 🔸 **Intro:**

Use two indices (start, end or left/right) to reduce nested loops.

### 🔸 **Use Cases:**

- Pair sum in sorted array
    
- Remove duplicates in-place
    
- Reverse words, reverse string
    
- Partition problems
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n)
    
- 💾 Space: O(1)
    

### 🔸 **LeetCode:**

- Easy: [344. Reverse String](https://leetcode.com/problems/reverse-string/)
    
- Easy: [26. Remove Duplicates](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
    
- Medium: [167. Two Sum II (Sorted)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
    
- Medium: [15. 3Sum](https://leetcode.com/problems/3sum/)
    

### 🔸 **Why preferred:**

- 🌀 Beats O(n²) brute-force
    
- Perfect for sorted data or palindromes
    

---

## 🔹 **Sorting**

### 🔸 **Intro:**

Sort data to unlock easier access patterns or comparisons.

### 🔸 **Use Cases:**

- Binary search
    
- Pairing problems
    
- Greedy algorithms
    
- K-sum family (2Sum, 3Sum, etc.)
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n log n)
    
- 💾 Space: O(log n) or O(n) depending on algorithm
    

### 🔸 **LeetCode:**

- Easy: [561. Array Partition](https://leetcode.com/problems/array-partition-i/)
    
- Medium: [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)
    
- Medium: [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
    

### 🔸 **Why preferred:**

- 🧭 Prepares data for binary search, two pointers
    
- 🎯 Enables greedy algorithms
    

---

## 🔹 **In-place Techniques**

### 🔸 **Intro:**

Modify data in the original array without using extra space.

### 🔸 **Use Cases:**

- Reverse array
    
- Rotate array
    
- Remove duplicates
    
- Move zeroes
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n)
    
- 💾 Space: O(1)
    

### 🔸 **LeetCode:**

- Easy: [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)
    
- Easy: [26. Remove Duplicates]
    
- Medium: [189. Rotate Array](https://leetcode.com/problems/rotate-array/)
    

### 🔸 **Why preferred:**

- 🚫 Saves space
    
- Used when memory is limited or constraints specify "in-place"
    

---

## 🔹 **Sliding Window**

### 🔸 **Intro:**

Move a window across the array to maintain a dynamic subarray or substring.

### 🔸 **Use Cases:**

- Longest substring without repeating
    
- Max sum subarray of size k
    
- Character frequencies in substrings
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n)
    
- 💾 Space: O(1) or O(k)
    

### 🔸 **LeetCode:**

- Easy: [643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
    
- Medium: [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
    
- Medium: [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
    

### 🔸 **Why preferred:**

- 📏 Turns O(n²) brute-force into O(n)
    
- Great for dynamic ranges, substrings, subarrays
    

---

## 🔹 **Prefix Sum / Difference**

### 🔸 **Intro:**

Build a running sum array to calculate range sums in O(1)

### 🔸 **Use Cases:**

- Range sum queries
    
- Subarray sums
    
- Difference arrays for range updates
    

### 🔸 **Time & Space:**

- ⏱ Time: O(n) to build, O(1) to query
    
- 💾 Space: O(n)
    

### 🔸 **LeetCode:**

- Easy: [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
    
- Medium: [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
    
- Medium: [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) (prefix product)
    

### 🔸 **Why preferred:**

- ⏩ Replaces nested sums with fast lookups
    
- ✅ Great for precomputing and reducing repeated work
    
