## Kruskal Algorithm (MST) 
(https://www.geeksforgeeks.org/dsa/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, and undirected graph is a spanning tree (no cycles and connects all vertices) that has minimum weight. The weight of a spanning tree is the sum of all edges in the tree.  

In Kruskal's algorithm, we sort all edges of the given graph in increasing order. Then it keeps on adding new edges and nodes in the MST if the newly added edge does not form a cycle. It picks the minimum weighted edge at first and the maximum weighted edge at last. Thus we can say that it makes a locally optimal choice in each step in order to find the optimal solution. Hence this is a Greedy Algorithm.
#### Algorithm:
- Sort all the edges in a non-decreasing order of their weight. 
- Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
- Repeat step 2 until there are (V-1) edges in the spanning tree.

### Correctness

**Greedy choice property:**  
Selecting the smallest weight edge that doesn’t form a cycle is always safe — it’s guaranteed to be in some MST.

**Proof idea (Cut Property):**  
For any cut in the graph, the smallest edge crossing that cut belongs to an MST.

**Optimal substructure:**  
Combining MSTs of connected components still gives a global MST.

## Prim's
(https://www.w3schools.com/dsa/dsa_algo_mst_prim.php)
- Prim's algorithm finds the Minimum Spanning Tree (MST) in a connected and undirected graph.
- The MST found by Prim's algorithm is the collection of edges in a graph, that connects all vertices, with a minimum sum of edge weights.

Prim's algorithm finds the MST by first including a random vertex to the MST. The algorithm then finds the vertex with the lowest edge weight from the current MST, and includes that to the MST. Prim's algorithm keeps doing this until all nodes are included in the MST.

Prim's algorithm is greedy, and has a straightforward way to create a minimum spanning tree.
#### Algorithm

1. Choose a random vertex as the starting point, and include it as the first vertex in the MST.
2. Compare the edges going out from the MST. Choose the edge with the lowest weight that connects a vertex among the MST vertices to a vertex outside the MST and which doesn't form a cycle
3. Add that edge and vertex to the MST.
4. Keep doing step 2 and 3 until all vertices belong to the MST.

### Correctness

**Greedy choice property:**  
At every step, the smallest edge connecting the current tree to a new vertex **always belongs to some MST**.

**Proof idea:**  
If there were a smaller MST that didn’t include this edge, you could swap edges and get another MST of equal or lesser weight — contradiction.  
Thus, the choice is safe.

**Optimal substructure:**  
Once you include an edge, the remaining graph still forms a smaller MST problem.  
Hence, building step by step gives the global optimum.

### Time Complexity

| Step                  | Operation                       | Complexity |
| --------------------- | ------------------------------- | ---------- |
| Sorting edges         | O(E log E)                      |            |
| Union-Find operations | O(E α(V)) ≈ O(E)                |            |
| **Total**             | **O(E log E)** ≈ **O(E log V)** |            |
## Dijkstra Algorithm
(https://www.tutorialspoint.com/data_structures_algorithms/dijkstras_shortest_path_algorithm.htm)
- To find the shortest path in the graph from one vertex to other remaining vertices in the graph. Dijkstras algorithm can be performed on both directed and undirected graphs.

#### Algorithm
- Declare two arrays − _distance_[] to store the distances from the source vertex to the other vertices in graph and _visited_[] to store the visited vertices.
    
- Set distance[S] to 0 and distance[v] = ∞, where v represents all the other vertices in the graph.
    
- Add S to the visited[] array and find the adjacent vertices of S with the minimum distance.
    
- The adjacent vertex to S, say A, has the minimum distance and is not in the visited array yet. A is picked and added to the visited array and the distance of A is changed from ∞ to the assigned distance of A, say d1, where d1 < ∞.
    
- Repeat the process for the adjacent vertices of the visited vertices until the shortest path spanning tree is formed.
### Correctness

**Greedy choice property:**  
At each step, the vertex chosen with the smallest distance **already has its final shortest distance** (since no smaller path can exist later).

**Proof idea:**  
When a vertex `u` is picked, all edges with smaller total weight have already been processed — hence `dist[u]` is final.

**Optimal substructure:**  
Shortest path from `s` to `v` can be built using shortest paths from `s` to intermediate nodes.

### Analysis
|Implementation|Time Complexity|Space|
|---|---|---|
|Using adjacency matrix|O(V²)|O(V)|
|Using min-heap / adjacency list|O(E log V)|O(V + E)|

---


## BellMan Ford
- **Bellman-Ford*** is a **single source** shortest path algorithm. It effectively works in the cases of negative edges and is able to detect negative cycles as well. It works on the principle of **relaxation of the edges**.
### Detection of a Negative Weight Cycle

- As we have discussed earlier that, we need (V - 1) relaxations of all the edges to achieve single source shortest path. If one **additional relaxation** (Vth) for any edge is possible, it indicates that some edges with overall negative weight has been traversed once more. This indicates the presence of a **negative weight cycle** in the graph.
### Principle of Relaxation of Edges

- Relaxation means **updating** the shortest distance to a node if a shorter path is found through another node. For an edge ****(u, v)**** with weight **w**:
    - If going through u gives a shorter path to v from the source node (i.e., **distance\[v] > distance\[u] + w**), we update the distance\[v] as distance\[u] + w.
- In the bellman-ford algorithm, this process is repeated ****(V - 1)**** times for all the edges.

#### Algorithm
1. Set initial distance to zero for the source vertex, and set initial distances to infinity for all other vertices.
2. For each edge, check if a shorter distance can be calculated, and update the distance if the calculated distance is shorter.
3. Check all edges (step 2) V−1 times. This is as many times as there are vertices (V), minus one.
4. Optional: Check for negative cycles. 

---

## Floyd Warshall
The **Floyd–Warshall algorithm** works by maintaining a two-dimensional array that represents the distances between nodes. Initially, this array is filled using only the direct edges between nodes. Then, the algorithm gradually updates these distances by checking if shorter paths exist through intermediate nodes.

This algorithm works for both the **directed** and **undirected weighted** graphs and can handle graphs with both **positive** and **negative weight edges**.

**Note**: It does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).

#### Algorithm
- **Start by updating the distance matrix** by treating each vertex as a possible intermediate node between all pairs of vertices.
- **Iterate through each vertex**, one at a time. For each selected vertex `k`, attempt to improve the shortest paths that pass through it.
- When we pick vertex number **k** as an intermediate vertex, we already have considered vertices ****{0, 1, 2, .. k-1}**** as intermediate vertices. 
- For every pair ****(i, j)**** of the source and destination vertices respectively, there are two possible cases. 
    - **k** is not an intermediate vertex in shortest path from **i** to **j**. We keep the value of **dist\[i]\[j]** as it is. 
    - **k** is an intermediate vertex in shortest path from **i** to **j**. We update the value of **dist\[i]\[j]** as **dist\[i]\[k] + dist\[k]\[j],** if **dist\[i]\[j] > dist\[i]\[k] + dist\[k]\[j]**
- Repeat this process for each vertex `k` until all intermediate possibilities have been considered.

#### Pseudocode
```java
for (int k = 0; k < n; k++) {           // for each intermediate vertex
    for (int i = 0; i < n; i++) {       // for each source vertex
        for (int j = 0; j < n; j++) {   // for each destination vertex
            if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
}
```

### Correctness (Proof Outline)

The **Floyd–Warshall algorithm** is based on **Dynamic Programming**.

Let `dist[i][j][k]` be the shortest distance from vertex `i` to vertex `j` using only the **first k vertices** `{1, 2, ..., k}` as intermediate vertices.

**Base Case:**  
When `k = 0` → no intermediate vertices allowed

dist\[i]\[j]\[0] = w(i,j)

**Recursive Case:**  
For `k ≥ 1`:

dist\[i]\[j]\[k] = min⁡(dist\[i]\[j]\[k−1],  dist\[i]\[k]\[k−1]+dist\[k]\[j]\[k−1])

→ Either:

- The shortest path **doesn’t use vertex `k`**, or
    
- It **passes through `k`** (then path = `i → k → j`)
    

By iterating through `k = 1` to `n`,  
we ensure every vertex is considered as an intermediate node, so final `dist[i][j]` gives the **shortest possible distance**.

Hence, algorithm is **correct** by induction

---


## Huffman Encoding
- To encode symbols (characters) based on their frequencies so that the total encoded message length is **minimum**.  
- Frequently occurring characters get **shorter codes**, and rare ones get **longer codes**.

### Data Structures Used

- **Min-Heap (Priority Queue)** — to always extract two nodes with the smallest frequency.
    

---

### Algorithm Steps

#### **Step 1: Input**

Take a set of characters and their corresponding frequencies.  

---

#### **Step 2: Create Leaf Nodes**

For each character, create a leaf node containing:

`symbol, frequency`

and insert all nodes into a **min-heap** based on frequency.

---

#### **Step 3: Build Huffman Tree**

While there is **more than one node** in the heap:

1. Remove two nodes with the **smallest frequency** (say `left` and `right`).
    
2. Create a new internal node with:
    
    `frequency = left.freq + right.freq`
    
3. Set:
    
    `new.left = left new.right = right`
    
4. Insert the new node back into the heap.
    

When only one node remains, it becomes the **root** of the Huffman Tree.

---

#### **Step 4: Assign Codes**

Traverse the Huffman Tree:

- Assign **‘0’** for left edge and **‘1’** for right edge.
    
- Keep adding bits until a leaf node is reached → that bit sequence becomes the **Huffman code** for that character.
    

---

#### **Step 5: Encoding**

Replace each character in the input text by its Huffman code.

---

#### **Step 6: Decoding (Reverse Process)**

Start from the root of the Huffman Tree:

- Read the encoded bits one by one.
    
- Move **left** for `0`, **right** for `1`.
    
- When a **leaf node** is reached, output its character and go back to the root.

### Time Complexity

| Step                                                | Operation  |
| --------------------------------------------------- | ---------- |
| Building min-heap                                   | O(n)       |
| Extracting 2 nodes and inserting 1 (for n–1 merges) | O(n log n) |
| Assigning codes (tree traversal)                    | O(n)       |
**Total Time Complexity:**
O(nlog⁡n)

### Space Complexity

- Each node stored in heap → **O(n)**
- Huffman tree storage → **O(n)**
    
**Total Space Complexity:**
O(n)

---
## 0/1 Knapsack Problem
### Problem Statement

Given:

- `n` items, each with a **weight** and a **value**.
    
- A knapsack (bag) with **capacity W**.
    

Find:

> The **maximum total value** that can be obtained by selecting items such that the total weight does **not exceed W**.

Each item can be **included (1)** or **excluded (0)** → hence **“0/1”** knapsack.

### Approach: Dynamic Programming (Efficient)

We use a **DP table** to store solutions to subproblems.

---

### **DP Table Definition**

`dp[i][w]` = maximum value that can be achieved using first `i` items and capacity `w`.


---

### **Algorithm Steps**

1. Initialize a 2D array `dp[n+1][W+1]` with zeros.
    
2. For each item `i` from `1` to `n`:  
    For each capacity `w` from `1` to `W`:
    
    - If `wt[i-1] ≤ w`:  
        `dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])`
        
    - Else:  
        `dp[i][w] = dp[i-1][w]`
        
1. The result is stored in `dp[n][W]`.

#### Analysis

|Aspect|Complexity|
|---|---|
|Time|O(n × W)|
|Space|O(n × W)|
|Optimized Space (1D DP)|O(W)|

---

## Longest Common Subsequence (LCS)

> The **Longest Common Subsequence (LCS)** problem finds the **longest sequence** that appears **in both strings in the same relative order**, but **not necessarily contiguous**.

---

### Difference Between Substring and Subsequence

|Concept|Must Be Continuous?|Example (for "abcde" & "ace")|
|---|---|---|
|**Substring**|Yes|`"abc"`|
|**Subsequence**|No|`"ace"`|

---

### Dynamic Programming Approach

We use a **2D DP table** to store the length of the longest common subsequence between prefixes of the two strings.

---

#### Step 1: Define the DP Table

Let:

- String `S1` length = `m`
    
- String `S2` length = `n`
    
- Create a table `dp[m+1][n+1]` initialized to 0
    

`dp[i][j]` → length of LCS of `S1[0..i-1]` and `S2[0..j-1]`

---

#### Step 2: Recurrence Relation

```
If S1[i-1] == S2[j-1]:
      dp[i][j] = 1 + dp[i-1][j-1]

Else:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

---

#### Step 3: Initialization

- `dp[0][*] = 0` and `dp[*][0] = 0`  
    (because an empty string has no common subsequence)
    

---

#### Step 4: Final Answer

- The **length** of LCS = `dp[m][n]`
    
- To **reconstruct** the sequence, trace back from `dp[m][n]`.
    

---

### Example

```
S1 = "ABCBDAB"
S2 = "BDCABA"
```

|i/j|""|B|D|C|A|B|A|
|---|---|---|---|---|---|---|---|
|""|0|0|0|0|0|0|0|
|A|0|0|0|0|1|1|1|
|B|0|1|1|1|1|2|2|
|C|0|1|1|2|2|2|2|
|B|0|1|1|2|2|3|3|
|D|0|1|2|2|2|3|3|
|A|0|1|2|2|3|3|4|
|B|0|1|2|2|3|4|4|

LCS = `"BCBA"` (or `"BDAB"`, both valid)  
Length = 4

---

### Complexity

|Type|Complexity|Description|
|---|---|---|
|**Time**|O(m × n)|Nested loops for each character pair|
|**Space**|O(m × n)|DP table storage|
|**Optimized Space**|O(min(m, n))|Using rolling arrays (store only previous row)|