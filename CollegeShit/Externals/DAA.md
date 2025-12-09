## Strassen Multiplication method
### **Definition**

**Strassen’s matrix multiplication algorithm** is an optimized divide-and-conquer technique used to multiply two square matrices. It reduces the number of multiplications and improves the time complexity from **O(n³)** to **O(n².8074)**.

---

### **Basic Idea**

Let A and B be two **n × n** matrices. They are divided into four equal submatrices of size **(n/2 × n/2)**:

```
A = |A11 A12|    B = |B11 B12|
    |A21 A22|        |B21 B22|
```

Instead of performing 8 multiplications, Strassen computes **7 products** using the following formulas:

---

### **Strassen’s 7 Products**

```
M1 = (A11 + A22)(B11 + B22)
M2 = (A21 + A22)(B11)
M3 = (A11)(B12 - B22)
M4 = (A22)(B21 - B11)
M5 = (A11 + A12)(B22)
M6 = (A21 - A11)(B11 + B12)
M7 = (A12 - A22)(B21 + B22)
```

---

### **Construction of Result Matrix C**

```
C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6
```

The final matrix **C** is:

```
C = |C11 C12|
    |C21 C22|
```

---

### **Algorithm**

```
Strassen(A, B, n)
1. If n == 1:
       return A * B
2. Divide matrices A and B into four submatrices:
       A11, A12, A21, A22
       B11, B12, B21, B22
3. Compute the seven products M1 to M7 using Strassen’s formulas
4. Compute C11, C12, C21, and C22 from M1 to M7
5. Combine these four matrices to form the result matrix C
6. Return C
```

---

### **Time Complexity Analysis**

![[Pasted image 20251208221721.png]]

---

### **Advantages**

- Faster than the conventional matrix multiplication
    
- Reduces the number of multiplications from 8 to 7
    
- Better asymptotic time complexity
    

---

### **Disadvantages**

- Not suitable for very small matrices
    
- Requires more additions and subtractions
    
- More complex and less numerically stable
    
- Requires extra memory for storing intermediate matrices

---
---

## Control abstraction 

### **Definition**
Control abstraction refers to representing algorithms using high-level structures without focusing on the internal implementation details. It hides the unnecessary details and provides a general pattern for writing algorithms.

**Divide and Conquer** is a control abstraction (algorithmic strategy) that solves a problem by dividing it into smaller subproblems, solving each subproblem recursively, and then combining the results to form the final solution.

---

#### **Control Abstraction for Divide and Conquer**

```
DAC(P)
1. If P is small enough:
       solve P directly
2. Else:
       divide P into P1, P2, ..., Pk
       for i = 1 to k do
            Xi = DAC(Pi)     // recursively solve subproblems
       combine all Xi to form solution of P
3. Return solution
```

Where:

- **P** is the original problem
    
- **Pi** are the smaller subproblems
    
- **Xi** is the solution to each subproblem
    

This abstraction hides implementation details and provides a **general template** for divide and conquer algorithms.

---

#### **Example: Merge Sort using Divide and Conquer**

Let P be an unsorted array.

### Step 1: **Divide**

Split the array into two halves:

```
Left half  → L
Right half → R
```

### Step 2: **Conquer**

Recursively sort both halves:

```
DAC(L)
DAC(R)
```

### Step 3: **Combine**

Merge the two sorted halves to get the final sorted array.

---

### **Control Abstraction of Merge Sort**

```
MERGE_SORT(A, n)
1. If n ≤ 1:
       return A
2. Divide A into two subarrays: L and R
3. L = MERGE_SORT(L)
   R = MERGE_SORT(R)
4. A = MERGE(L, R)  // combine step
5. Return A
```

---

## Counting sort
### **Definition**

Counting Sort is a non-comparison-based sorting algorithm that sorts elements by counting the number of occurrences of each distinct element. It is efficient when the range of input values (**k**) is not significantly larger than the number of elements (**n**). Counting Sort works in **O(n + k)** time, making it faster than comparison-based algorithms like Merge Sort and Quick Sort for small ranges.

---

### **Algorithm**

Let the input array be **A[1…n]**, and elements lie in the range **0 to k**.

```
COUNTING_SORT(A, n, k)
1. Create an array C[0…k] and initialize all values to 0
2. For each element x in A:
       C[x] = C[x] + 1     // count occurrences
3. For i = 1 to k:
       C[i] = C[i] + C[i-1]   // cumulative count
4. Create an output array B[1…n]
5. For j = n down to 1:
       B[C[A[j]]] = A[j]
       C[A[j]] = C[A[j]] - 1
6. Return array B
```

---

### **Working Explanation**

- **Step 1**: Count how many times each number appears.
    
- **Step 2**: Convert counts into cumulative counts to determine each element’s final position.
    
- **Step 3**: Place elements into the output array in sorted order.
    

Counting Sort is **stable**, meaning it preserves the order of equal elements.

---

### **Example Run**

Sort the array:

```
A = [4, 2, 2, 8, 3, 3, 1]
```

**Step 1: Find max element = 8 → k = 8**

**Step 2: Count array C (frequency of elements)**

|Index|0|1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|---|---|
|C (initial)|0|1|2|2|1|0|0|0|1|

(1 occurs once, 2 twice, 3 twice, 4 once, 8 once)

**Step 3: Cumulative Count**

|Index|0|1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|---|---|
|C (cum.)|0|1|3|5|6|6|6|6|7|

This tells the final positions:

- `1` goes to position 1
    
- numbers ≤2 end at position 3, etc.
    

**Step 4: Placing values in output array**

Process input from right to left:

```
B = [1, 2, 2, 3, 3, 4, 8]
```

**Sorted Output =** `[1, 2, 2, 3, 3, 4, 8]`

---

### **Time and Space Complexity Analysis**

|Operation|Complexity|
|---|---|
|Time Complexity|**O(n + k)**|
|Space Complexity|**O(k)**|
|Stability|**Stable**|
|Sorting Technique|Non-comparison based|


---
## **Radix Sort**

### **Definition**

Radix Sort is a non-comparison-based sorting algorithm that sorts numbers digit by digit, starting either from the **least significant digit (LSD)** or the **most significant digit (MSD)**. It uses a stable intermediate sorting technique, usually **Counting Sort**, to sort elements based on each digit. Radix Sort is efficient when the number of digits (d) in the largest number is small.

---

### **Idea of Radix Sort**

Instead of comparing values directly, Radix Sort groups numbers according to their digit places:

- 1st pass → units place
    
- 2nd pass → tens place
    
- 3rd pass → hundreds place  
    ...and so on
    

Each pass sorts the list **stably**, ensuring correct ordering.

---

### **Algorithm (LSD Radix Sort)**

Assume we have an array **A[1…n]** with maximum **d digits**.

```
RADIX_SORT(A, n, d)
1. For i = 1 to d do:
       Perform a stable Counting Sort on A based on the i-th digit
2. Return A
```

Here, **i = 1** means sorting by units place, **i = 2** means tens, etc.

> Counting Sort is used because it is stable and handles digit-based ordering efficiently.

---

### **Example Run**

Sort the following numbers:

```
A = [170, 45, 75, 90, 802, 24, 2, 66]
```

**Step 1: Units place sort**

|Units digit|Numbers sorted|
|---|---|
|0|170, 90|
|2|2|
|4|24|
|5|45, 75|
|6|66|
|2|already counted|
|8|802|

After units sort:

```
[170, 90, 802, 2, 24, 45, 75, 66]
```

---

**Step 2: Tens place sort**

Digits considered: 7, 9, 0, 0, 2, 4, 7, 6

After stable sort by tens digit:

```
[802, 2, 24, 45, 66, 170, 75, 90]
```

---

**Step 3: Hundreds place sort**

Digits considered: 8, 0, 0, 0, 0, 1, 0, 0

After sort:

```
[2, 24, 45, 66, 75, 90, 170, 802]
```

**Final Sorted Output:**

```
[2, 24, 45, 66, 75, 90, 170, 802]
```

---

### **Time and Space Complexity Analysis**

Let:

- **n** = number of elements
    
- **d** = number of digits in the largest number
    
- **k** = range of digits (0 to 9 → k = 10)
    

|Operation|Complexity|
|---|---|
|Time Complexity|**O(d·(n + k))**|
|Space Complexity|**O(n + k)**|
|Stable|**Yes**|
|Technique|Non-comparison based|

When **d** is constant (like integers up to 32 bits), Radix Sort runs in **O(n)**.

---

## Fractional Knapsack

### **Definition**

The **Fractional Knapsack Problem** is an optimization problem where a thief wants to maximize the total profit by selecting items with given weights and profit such that they fit into a knapsack of limited capacity. Unlike the 0/1 Knapsack, here the thief is allowed to take **fractions of items**, not necessarily whole items.

---

## **Greedy Strategy**

The greedy approach selects items based on the **maximum value-to-weight ratio** (profit per unit weight). The idea is:

> **Pick the item with the highest value/weight ratio first, then the next highest, and continue until the knapsack is full.**

This approach always gives the **optimal solution** for the fractional knapsack.

---

## **Algorithm (Greedy Approach)**

Let:

- `n` = number of items
    
- `W` = capacity of knapsack
    
- `value[i]`, `weight[i]` = value and weight of item `i`
    

```
FRACTIONAL_KNAPSACK(value[], weight[], n, W)
1. Calculate ratio[i] = value[i] / weight[i] for all items
2. Sort items in decreasing order of ratio[i]
3. Set totalValue = 0
4. For i = 1 to n
       if weight[i] ≤ W:
            W = W - weight[i]
            totalValue += value[i]
       else:
            totalValue += value[i] * (W / weight[i])
            break
5. Return totalValue
```


## **Time Complexity**

- Sorting items by ratio → **O(n log n)**
    
- Selecting items → **O(n)**
    

So overall complexity: 
O(n log n)  

---

## **Advantages**

✔ Always produces optimal solution  
✔ Efficient and simple  
✔ Works for large input sizes

---


## Huffman Coding


### **Definition**

**Huffman Coding** is a greedy algorithm used for **lossless data compression**. It assigns **variable-length prefix codes** to characters such that the characters with **higher frequency get shorter codes** and those with **lower frequency get longer codes**. This results in minimal total encoded length.

---

## **Key Idea**

- Build a binary tree where:
    
    - Left edge → `0`
        
    - Right edge → `1`
        
- Each leaf node represents a character
    
- No code is a prefix of another code (**prefix-free codes**)
    

---

## **Algorithm (Greedy Approach)**

```
HUFFMAN(C)
1. Create a leaf node for each character and insert into a min-heap (priority queue),
   keyed by frequency.
2. While more than one node in heap:
       a. Remove two nodes with minimum frequency
       b. Create a new internal node with frequency = sum of the two
       c. Make the two nodes children of this new node
       d. Insert the new node back into heap
3. The remaining node is the root of the Huffman Tree
4. Assign codes:
       Traverse left → 0
       Traverse right → 1
```

---


## **Analysis**

### **Time Complexity**

- Building min-heap: **O(n)**
    
- Extracting and combining nodes: **O(n log n)**
    
T(n) = O(n log n)  
### **Space Complexity**

O(n)  

---

## **Advantages**

✔ Optimal prefix-free coding  
✔ Reduces storage space  
✔ Used in real compression algorithms (ZIP, GZIP, JPEG, MP3)

---

[[CollegeShit/3rd SEM/DAA/UNIT 3|UNIT 3]]