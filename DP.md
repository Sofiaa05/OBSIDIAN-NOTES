
Memoization stores the results of solved subproblems so future calls can reuse them instead of recomputing.

### Without memoization

```java
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2); // repeated work
}
```

### With Memoization

```java
class Solution {
    int[] dp = new int[31];   // cache for results

    public int fib(int n) {
        if (n <= 1) return n;

        if (dp[n] != 0) return dp[n]; // If the Fibonacci value for n has already been computed earlier and stored in dp[n], then just return it. Don’t compute again, return cached result

        dp[n] = fib(n - 1) + fib(n - 2); // compute and store
        return dp[n];
    }
}
```



### **1️⃣ Recursion**

**Definition:**  
Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.

**Example:**  
To compute `fib(n)`, we compute `fib(n-1)` and `fib(n-2)` recursively.

**When to use:**  
When a problem can be broken into smaller subproblems of the same type.

---

### **2️⃣ Recursion Call Stack**

**Explanation:**  
Every recursive call is stored on the call stack until it returns. Each call holds its own local variables and state.

**Key point:**  
If recursion goes too deep, stack overflow occurs.

---

### **3️⃣ Overlapping Subproblems**

**Meaning:**  
A problem has overlapping subproblems if the same subproblems are solved multiple times during recursion.

**Example:**  
In Fibonacci, `fib(3)` gets computed many times when calculating `fib(5)`.

This is where DP helps save time.

---

### **4️⃣ Optimal Substructure**

**Definition:**  
A problem has optimal substructure if the optimal solution can be constructed from optimal solutions of its subproblems.

**Example:**  
Longest Common Subsequence (LCS):  
LCS of full strings depends on the LCS of prefixes.

**Importance:**  
This property is necessary for applying dynamic programming.

---

### **5️⃣ Time Complexity of Naive Recursion**

**Example:** Fibonacci

```
fib(n) = fib(n-1) + fib(n-2)
```

**Complexity:**  
`O(2^n)` — exponential time

**Reason:**  
Each call branches into two more calls, re-solving the same subproblems again and again.

---

### **6️⃣ Fibonacci Using Recursion**

**Code logic explanation:**

```java
fib(n) = fib(n-1) + fib(n-2)
```

- Base cases: `fib(0) = 0`, `fib(1) = 1`
    
- Recursive calls compute values for smaller `n`
    

**Problem:**  
Repeated computations make it inefficient.

---

### **7️⃣ Problems Where Recursion Repeats Work**

**Examples:**

- Fibonacci
    
- Climbing stairs
    
- Coin change
    
- LCS (Longest Common Subsequence)
    

**Pattern:**  
Same subresults computed multiple times → wasted time.

---

### **8️⃣ Why Recursion Becomes Exponential**

**Reason:**  
Every call spawns two or more calls and subproblems repeat.

Example:

```
fib(5)
fib(4) fib(3)
fib(3) fib(2) ... fib(3) appears again
```

The recursive tree doubles at each level → exponential growth.

---

### **9️⃣ Why Do We Need Dynamic Programming?**

**Answer:**  
Dynamic Programming removes redundant calculations by storing results of subproblems (memoization) or by solving from the bottom up (tabulation).

It reduces exponential recursion to polynomial time like `O(n)`.

**One-liner answer:**

> We need DP because naive recursion wastes time solving the same subproblems repeatedly. DP saves those results and reuses them, making the algorithm efficient.

---

## 🔥 **Memoization (Top-Down Dynamic Programming)**

### **1️⃣ What is Memoization?**

**Interview Answer:**

Memoization is a **top-down dynamic programming technique** where we optimize recursion by storing results of already solved subproblems so that future calls can reuse those results instead of recomputing them.

**Formula-style definition:**

```
Memoization = Recursion + Cache
```

It converts **exponential recursion** into **linear/polynomial time**.

---

## **2️⃣ Recursion + Caching Results**

In recursion, the same function may be called multiple times with the same input.

Memoization adds a **cache** (array or HashMap) where:

- Key → parameter value (e.g., `n`)
    
- Value → computed result (e.g., `fib(n)`)
    

Before computing a result, we check if it’s already cached:

```java
if (dp[n] != 0) return dp[n];
```

This prevents repeated work.

---

## **3️⃣ dp array / hashmap as cache**

### When to use `dp[]` (array)?

If the subproblem index is numeric and bounded.

Examples:

- Fibonacci
    
- Climbing stairs
    
- House robber
    
- Coin change with amount ≤ constraint
    

### When to use HashMap?

If the state is complex:

- Strings (LCS, Edit distance)
    
- Trees / Graph DP
    
- Multiple parameters (e.g., `(i, j)`)
    

Example:

```java
Map<String, Integer> memo
```

for storing `dp[i,j]`.

---

## **4️⃣ Time/Space Complexity of Memoization**

### **Without memoization**

`O(2^n)` exponential — because recursive calls branch repeatedly.

### **With memoization**

Each unique subproblem is solved **once**:

```
Time = Number of states × cost per state
```

- Fibonacci: `O(n)`
    
- LCS: `O(n × m)`
    
- Knapsack: `O(n × W)`
    

Space complexity includes:

- `dp` storage
    
- recursion stack
    

So:

```
Space = O(n) or O(n*m) depending on DP dimensions
```

---

## **5️⃣ Memoization vs Storing Base Cases**

Many students get confused here — this is important.

### Base cases:

```java
if (n <= 1) return n;
```

These prevent unnecessary recursive calls.

### Memoization:

```java
if (dp[n] != 0) return dp[n];
```

This prevents **repeated computation** of already solved states.

**Difference in one line:**

|Base Case|Memo Check|
|---|---|
|stops recursion at smallest input|stops recomputation of solved inputs|

Both are required, but solve different problems.

---

## 🌟 Now the interviewer will follow-up with:

### **Memoization vs Tabulation**

| Memoization (Top-down)                                 | Tabulation (Bottom-up)                     |
| ------------------------------------------------------ | ------------------------------------------ |
| Uses recursion + cache                                 | Uses loops + dp table                      |
| Starts from `n` and breaks down to smaller subproblems | Starts from base case and builds up to `n` |
| May cause stack overflow for large n                   | No stack usage                             |
| Suitable for problems on trees                         | Suitable for linear DP problems            |

---



### **A. Overlapping Subproblems in Memoization**

Memoization only works when recursive calls revisit the same state.

Example Fibonacci recursion tree:

```
fib(5)
fib(4) fib(3)
fib(3) fib(2) ...
```

`fib(3)` appears multiple times → good DP candidate.

---

### **B. Optimal Substructure**

Memoization is valid only when subproblem solutions can be combined to form the final solution.

Example:

```
fib(n) = fib(n-1) + fib(n-2)
LCS(i,j) = 1 + LCS(i-1, j-1)
```

If this property doesn't exist → DP doesn't apply.

---

### **C. Identifying DP problems in interviews**

Say this — they LOVE it:

```
If a problem has recursion + repeated subproblems + optimal substructure,
use memoization or DP.
```

## Final One-Liner Summary (Say this in interview)

```
Memoization is a top-down dynamic programming technique that adds a cache to recursive solutions to avoid repeated computation of overlapping subproblems, reducing exponential time to polynomial while retaining the recursive intuition.
```

---

## **1️⃣ Tabulation (Bottom-Up DP)**

**Definition:**  
Tabulation is a **bottom-up** dynamic programming method where we start solving from the smallest subproblem and iteratively build the solution to the original problem using a DP table (usually an array).

**Key points:**

- Uses **loops instead of recursion**
    
- Fills the dp array starting from base cases
    
- No recursion → no stack usage → no overflow risk
    
- Often faster in practice than memoization
    

**Example: Fibonacci**

```java
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++)
    dp[i] = dp[i-1] + dp[i-2];
```

---

## **2️⃣ Memoization vs Tabulation — Differences**

|Feature|Memoization (Top-Down)|Tabulation (Bottom-Up)|
|---|---|---|
|Approach|Start with original problem and recurse down|Start with smallest subproblem and build up|
|Control flow|Recursive|Iterative|
|Space usage|Uses stack + dp array|Uses only dp array|
|Computes|Only required states|All states|
|Ease of coding|More intuitive if recursion fits problem|Sometimes tricky to fill table|
|Stack overflow|Possible|Not possible|

**One-line answer:**

```
Memoization calls recursively and stores results; tabulation builds results iteratively from base upward.
```

---

## **3️⃣ Space Optimization in DP**

Once you identify that dp[i] depends only on a few previous states (like dp[i-1], dp[i-2]), you don’t need the whole DP array.

You replace the dp array with **variables**, reducing space from `O(n)` to `O(1)`.

Example Fibonacci:

```java
int prev2 = 0, prev1 = 1, curr;
for (int i = 2; i <= n; i++) {
   curr = prev1 + prev2;
   prev2 = prev1;
   prev1 = curr;
}
```

---

## **4️⃣ Types of DP**

### **A. 1D DP**

Used when the state depends on one variable.

Examples:

- Fibonacci
    
- Climbing Stairs
    
- House Robber
    
- Coin Change (1D array version)
    
- Kadane’s Algorithm (Maximum Subarray)
    

### **B. 2D DP**

Used when decision depends on two variables.

Examples:

- LCS (Longest Common Subsequence)
    
- Edit Distance
    
- Knapsack
    
- Matrix path problems
    
- DP on strings
    

dp table:

```
dp[i][j]
```

### **C. DP on Trees**

Used when subproblems are nodes in a tree.

Examples:

- House Robber III (binary tree)
    
- Diameter of binary tree
    
- Counting paths in tree
    

We use **post-order DFS** + memoization.

---

## **5️⃣ When to Choose Recursion vs Iteration**

|Use Recursion (Memoization)|Use Iteration (Tabulation)|
|---|---|
|Tree/graph problems|Linear dp problems|
|When natural recurrence exists|When loop relations are known|
|Easier to express logic|More space-efficient|
|Small input size|Large constraints|

General rule:

```
If recursion feels natural → memoize it.
If transitions are clear and sequential → tabulate it.
```

---

## **6️⃣ When Memoization Fails / Stack Overflow Risk**

Memoization may fail when:

❌ Depth of recursion is too large  
Example: `fib(10^7)` will overflow stack

❌ Problem has no overlapping subproblems  
Memoization pointlessly stores values

❌ Cyclic dependencies without cycle check  
Graph problems without visited set

In such cases → use tabulation or BFS/DFS.

---



---

## 🎯 Quick One-Line Summaries (Memory Boost)

```
Memoization → Top-down, recursive, cache results
Tabulation  → Bottom-up, iterative, fill dp table
Space Optimization → Reduce dp array to variables
1D DP → One dimension state dependency
2D DP → Two dimension state dependency
DP on Trees → DFS + memo on nodes
Recursion vs Iteration → choose based on natural structure
Memo fails → recursion depth or no overlapping subproblems
```

---

```java
public class Knapsack01 {

    public static int knapsack(int[] wt, int[] val, int W) {
        int n = wt.length;

        // dp[i][j] meaning using first i items and j capacity
        int[][] dp = new int[n + 1][W + 1];

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {

                // If we do NOT take the item
                dp[i][w] = dp[i-1][w]; //dont include item i, weight is not reduced, profit remains what it was

                // If we CAN take the item
                if (wt[i-1] <= w) {
                    dp[i][w] = Math.max(
                        dp[i][w], //not taking item
                        val[i-1] + dp[i-1][w - wt[i-1]] //value of this item + max profit of remaining capacity
                    );
                }
            }
        }
        return dp[n][W];
    }

    public static void main(String[] args) {
        int[] wt = {1, 3, 4, 5};
        int[] val = {1, 4, 5, 7};
        int W = 7;

        System.out.println("Maximum Profit = " + knapsack(wt, val, W));
    }
}

```




### ⭐ Step 1 — Start with the Problem Statement

> We are given items with weights and profits.  
> We have a knapsack with limited capacity `W`.  
> We must select items such that total weight does not exceed `W`, and total profit is maximum.  
> Each item can be taken **0 or 1** times — hence it's called **0/1 Knapsack**.

---

### ⭐ Step 2 — Define DP State (MOST IMPORTANT)

Say this confidently:

> I am using **Dynamic Programming** because the problem has **overlapping subproblems** and **optimal substructure**.

> I define `dp[i][w]` as:
> 
> **Maximum profit using the first `i` items with capacity `w`.**

This single line will impress the interviewer.

---

### ⭐ Step 3 — Base Case

> If there are zero items (`i = 0`), or capacity is zero (`w = 0`), profit is zero.

This is why dp array starts with zeros automatically.

---

### ⭐ Step 4 — Transition / Recurrence

For each item and capacity, I have **two choices**:

### **Choice 1: Do NOT take the item**

```java
dp[i][w] = dp[i-1][w];
```

> If I don't take this item, profit is same as previous items at same capacity.

### **Choice 2: Take the item (only if it fits)**

```java
if (wt[i-1] <= w)
  dp[i][w] = Math.max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
```

Say this:

> If the current item weight is less than or equal to current capacity `w`,  
> we can include it.  
> If we include it, profit = value of this item + best profit from remaining capacity.

> Then I take maximum of include and exclude choices.

This shows your DP understanding.

---

### ⭐ Step 5 — Final Answer

```java
return dp[n][W];
```

> This returns maximum profit using all items and full knapsack capacity.

---

### **📢 Ready-to-Say Script**

> The 0/1 Knapsack problem asks us to maximize profit without exceeding capacity, and each item can be chosen only once.  
> I solve this using Dynamic Programming.  
> I define `dp[i][w]` as the maximum profit using the first `i` items and capacity `w`.  
> The DP table has `n+1` rows for items and `W+1` columns for capacities.  
> For each item, I have two choices:
> 
> **1. Not take the item** — so profit remains `dp[i-1][w]`.  
> **2. Take the item** — only if its weight fits in current capacity `w`.  
> In that case, profit is `value of item + dp of remaining capacity`.
> 
> I take the maximum of these two choices.  
> Finally, `dp[n][W]` gives the maximum profit possible.

---


