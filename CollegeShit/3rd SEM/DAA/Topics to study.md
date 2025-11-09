
### Unit 2:
- Counting sort (Algorithm, numeric)
- Radix sort (Algorithm, numeric)
- Bubble Sort, Insertion sort, Selction sort, Quick sort, merge sort heap sort (Algorithm, numeric, comparative analysis)
- Linear search, Binary search (Algorithm, numeric, comparative analysis)
- disjoint set structure
### Unit 3:
- ~~Huffman Coding (Algorithm, numeric)~~
~~- Longest common substring (LCS) (Algorithm, alanlysis)~~
- ~~Prims, Kruskal, Dijkstra (Algorithms, numeric, Analysis and Correctness)~~
- Matrix multiple chain multiplication problem (Algorithm, numeric)
- ~~Bellman Ford (Algorithm, numeric)~~
- ~~Floyd Warshall (Algorithms, numeric, Analysis and Correctness)~~
- ~~0/1 Knapsack (Algorithm, numeric)~~
- BST, Optimal BST problem.
---
### Exam Questions
- #### Big O vs Big Omega

| Notation    | Bound Type  | Describes               | Example                 |
| ----------- | ----------- | ----------------------- | ----------------------- |
| **O(g(n))** | Upper bound | Worst-case              | Insertion Sort → O(n²)  |
| **Ω(g(n))** | Lower bound | Best-case               | Insertion Sort → Ω(n)   |
| **Θ(g(n))** | Tight bound | Average or exact growth | Merge Sort → Θ(n log n) |

- #### Asymptotic time complexity
	- **Asymptotic Time Complexity** is a way to describe **how the running time of an algorithm grows** as the **input size (n)** becomes very large.
	-  It focuses on the **growth rate**, not the exact time.
	
- #### **dynamic programming vs greedy strategy**

| **Feature**         | **Dynamic Programming (DP)**                                                                         | **Greedy Algorithm**                                                                         |
| ------------------- | ---------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| **Approach**        | Solves problems by **breaking them into overlapping subproblems** and combining solutions.           | Builds the solution **step by step**, always choosing the **best immediate (local) option**. |
| **Decision Making** | Makes decisions **after considering all possibilities**.                                             | Makes decisions **based only on current best choice**.                                       |
| **Method**          | **Bottom-up** or **Top-down (memoization)** approach.                                                | **Iterative** approach – pick locally optimal each time.                                     |
| **Examples**        | 0/1 Knapsack, Matrix Chain Multiplication, Bellman-Ford, Floyd-Warshall, Longest Common Subsequence. | Activity Selection, Kruskal’s MST, Prim’s MST, Dijkstra’s Algorithm, Huffman Coding.         |
|                     |                                                                                                      |                                                                                              |

- **worst case input for quick sort and insertion sort and binary search**
- **worst case complexity of quick and merge sort**

|**Algorithm**|**Best Case Time**|**Average Case Time**|**Worst Case Time**|**Space Complexity**|**Best Case Input**|**Worst Case Input**|
|---|---|---|---|---|---|---|
|**Insertion Sort**|O(n)|O(n²)|O(n²)|O(1)|Already sorted array|Reverse sorted array|
|**Selection Sort**|O(n²)|O(n²)|O(n²)|O(1)|Any input (no change)|Any input (always same)|
|**Quick Sort**|O(n log n)|O(n log n)|O(n²)|O(log n) (stack)|Pivot divides array evenly|Pivot divides array very unevenly (always smallest/largest)|
|**Heap Sort**|O(n log n)|O(n log n)|O(n log n)|O(1)|Any input|Any input|
|**Merge Sort**|O(n log n)|O(n log n)|O(n log n)|O(n)|Any input|Any input|

- optimal bst problem, height of balanced bst
- #### Bellman ford vs Dijkstra

| Feature                 | **Dijkstra**                             | **Bellman-Ford**                      |
| ----------------------- | ---------------------------------------- | ------------------------------------- |
| **Edge Weights**        | Works **only with non-negative weights** | Works with **negative weights** too   |
| **Approach**            | **Greedy algorithm**                     | **Dynamic programming**               |
| **Cycle Detection**     | Cannot detect negative cycles            | Can **detect negative weight cycles** |
| **Time Complexity**     | O((V + E) log V) using a min-heap        | O(V × E)                              |
| **Space Complexity**    | O(V)                                     | O(V)                                  |

- #### **recursive equation of multiple chain matrix**
Let `m[i][j]` = minimum number of scalar multiplications needed to multiply matrices from `A_i` to `A_j`.

Then the **recursive equation** is:
![[Pasted image 20251110024828.png]]