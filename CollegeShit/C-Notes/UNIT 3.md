# GRAPH TRAVERSALS
## Breadth First Search Traversal

Breadth First Search visits all adjacent vertices of a vertex before visiting neighboring vertices to the adjacent vertices. This means that vertices with the same distance from the starting vertex are visited before vertices further away from the starting vertex are visited.

**How it works:**

1. Put the starting vertex into the queue.
2. For each vertex taken from the queue, visit the vertex, then put all unvisited adjacent vertices into the queue.
3. Continue as long as there are vertices in the queue.

```sql
BFS(G, start):
    1. Create a queue and enqueue start node
    2. Mark start node as visited
    3. While queue is not empty:
        a. Dequeue a node → current
        b. Visit the current node
        c. For each neighbor of current:
            i. If neighbor is not visited:
                - Mark neighbor as visited
                - Enqueue neighbor

```
# Depth First Search or DFS for a Graph


In Depth First Search (or DFS) for a graph, we traverse all adjacent vertices one by one. When we traverse an adjacent vertex, we completely finish the traversal of all vertices reachable through that adjacent vertex.

1. Put the starting vertex into the **stack**.
    
2. While the stack is not empty:  
    a. Take the top vertex from the stack.  
    b. If the vertex has not been visited:  
        i. Visit the vertex.  
        ii. Push all **unvisited adjacent vertices** onto the stack.
    
3. Continue until the stack becomes empty.

```sql
DFS(G, start):
    1. Create a stack and push start node
    2. Mark start node as visited
    3. While stack is not empty:
        a. Pop the top node from the stack → current
        b. Visit the current node
        c. For each neighbor of current:
            i. If neighbor is not visited:
                - Mark neighbor as visited
                - Push neighbor onto the stack

```

---
# SPANNING TREES
-  A spanning tree is a subset of Graph G, such that all the vertices are connected using minimum possible number of edges. Hence, a spanning tree does not have cycles and a graph may have more than one spanning tree.
- A Spanning tree does not exist for a disconnected graph.
- For a connected graph having **N** vertices then the number of edges in the spanning tree for that graph will be **N-1**.
- A Spanning tree does not have any cycle.

- **Cayley's Formula:** Number of spanning trees in a complete graph with N vertices is:
$N^{N-2}$

## [Minimum Spanning Tree(MST)](https://www.geeksforgeeks.org/what-is-minimum-spanning-tree-mst/):

The weight of a spanning tree is determined by the sum of weight of all the edge involved in it.

A ****minimum spanning tree (MST)**** is defined as a spanning tree that has the minimum weight among all the possible spanning trees.

## [Properties of Minimum Spanning Tree](https://www.geeksforgeeks.org/properties-of-minimum-spanning-tree-mst/):

- A minimum spanning tree connects all the vertices in the graph, ensuring that there is a path between any pair of nodes.
- An ****MST**** is ****acyclic****, meaning it contains no cycles. This property ensures that it remains a tree and not a graph with loops.
- An ****MST**** with ****V**** vertices (where ****V**** is the number of vertices in the original graph) will have exactly ****V - 1**** edges, where ****V**** is the number of vertices.
- An ****MST**** is optimal for minimizing the total edge weight, but it may not necessarily be unique.
## KRUSKAL'S ALGORITHM FOR MST

Below are the steps for finding MST using Kruskal's algorithm:

- Sort all the edges in a non-decreasing order of their weight. 
- Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
- Repeat step 2 until there are (V-1) edges in the spanning tree.
The time complexity Of Kruskal's Algorithm is: O(E log E)

## PRIM'S ALGORITHM FOR MST

It falls under a class of algorithms called [greedy algorithms](https://www.programiz.com/dsa/greedy-algorithm) that find the local optimum in the hopes of finding a global optimum.

We start from one vertex and keep adding edges with the lowest weight until we reach our goal.

The steps for implementing Prim's algorithm are as follows:

1. Initialize the minimum spanning tree with a vertex chosen at random.
2. Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree
3. Keep repeating step 2 until we get a minimum spanning tree
---
## TOPOLOGICAL SORTING
#### **Kahn's Algorithm (BFS based)**

**Steps**:

1. Compute the **in-degree** of all vertices.
    
2. Add all vertices with in-degree = 0 to a queue.
    
3. While the queue is not empty:
    
    - Remove a vertex `u`, add it to the result.
        
    - For every neighbor `v` of `u`, reduce its in-degree by 1.
        
    - If in-degree of `v` becomes 0, add `v` to the queue.
        
4. If the result has all vertices → valid topological sort.
    
5. If not → the graph has a cycle.
    

**Time Complexity**: `O(V + E)`  
**Space Complexity**: `O(V)`

---
## DIJKSTRA ALGORITHM
- Dijkstra's algorithm finds the shortest path from one vertex to all other vertices.

- It does so by repeatedly selecting the nearest unvisited vertex and calculating the distance to all the unvisited neighboring vertices.
- Dijkstra's algorithm does not work for graphs with negative edges.
### Algorithm Steps

1. Initialize a `dist[]` array with `Integer.MAX_VALUE` (infinity), except `dist[source] = 0`.
    
2. Maintain a `visited[]` array to track whether a node has been finalized.
    
3. Repeat `V` times:
    
    - Find the unvisited node with the **minimum `dist[]`** value.
        
    - Mark that node as visited.
        
    - For all its neighbors:
        
        - If not visited and `dist[u] + weight[u][v] < dist[v]`, then update `dist[v]`.

**How it works:**

1. Set initial distances for all vertices: 0 for the source vertex, and infinity for all the other.
2. Choose the unvisited vertex with the shortest distance from the start to be the current vertex. So the algorithm will always start with the source as the current vertex.
3. For each of the current vertex's unvisited neighbor vertices, calculate the distance from the source and update the distance if the new, calculated, distance is lower.
4. We are now done with the current vertex, so we mark it as visited. A visited vertex is not checked again.
5. Go back to step 2 to choose a new current vertex, and keep repeating these steps until all vertices are visited.
6. In the end we are left with the shortest path from the source vertex to every other vertex in the graph.

---
# Floyd-Warshall Algorithm

Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph. This algorithm works for both the directed and undirected weighted graphs. But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).

A weighted graph is a graph in which each edge has a numerical value associated with it.

Floyd-Warhshall algorithm is also called as Floyd's algorithm, Roy-Floyd algorithm, Roy-Warshall algorithm, or WFI algorithm.

This algorithm follows the [dynamic programming](https://www.programiz.com/dsa/dynamic-programming) approach to find the shortest paths.

---

## How Floyd-Warshall Algorithm Works?

Let the given graph be:

![graph](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-graph.png "initial graph")

Initial Graph

Follow the steps below to find the shortest path between all the pairs of vertices.

1. Create a matrix `A0` of dimension `n*n` where n is the number of vertices. The row and the column are indexed as i and j respectively. i and j are the vertices of the graph.  
      
    Each cell A[i][j] is filled with the distance from the `ith` vertex to the `jth` vertex. If there is no path from `ith` vertex to `jth` vertex, the cell is left as infinity.
    
    ![matrix floyd warshall algorithm](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-matrix-1.png "matrix")
    
    Fill each cell with the distance between ith and jth vertex
    
2. Now, create a matrix `A1` using matrix `A0`. The elements in the first column and the first row are left as they are. The remaining cells are filled in the following way.  
      
    Let k be the intermediate vertex in the shortest path from source to destination. In this step, k is the first vertex. `A[i][j]` is filled with `(A[i][k] + A[k][j]) if (A[i][j] > A[i][k] + A[k][j])`.  
      
    That is, if the direct distance from the source to the destination is greater than the path through the vertex k, then the cell is filled with `A[i][k] + A[k][j]`.  
      
    In this step, k is vertex 1. We calculate the distance from source vertex to destination vertex through this vertex k.
    
    ![matrix floyd warshall algorithm](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-matrix-2-update.png "matrix A1")
    
    Calculate the distance from the source vertex to destination vertex through this vertex k
    
      
    For example: For `A1[2, 4]`, the direct distance from vertex 2 to 4 is 4 and the sum of the distance from vertex 2 to 4 through vertex (ie. from vertex 2 to 1 and from vertex 1 to 4) is 7. Since `4 < 7`, `A0[2, 4]` is filled with 4.
3. Similarly, `A2` is created using `A1`. The elements in the second column and the second row are left as they are.  
      
    In this step, k is the second vertex (i.e. vertex 2). The remaining steps are the same as in **step 2**.
    
    ![matrix floyd warshall algorithm](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-matrix-3.png "matrix A2")
    
    Calculate the distance from the source vertex to destination vertex through this vertex 2
    
4. Similarly, `A3` and `A4` is also created.
    
    ![matrix floyd warshall algorithm](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-matrix-4.png "matrix A3")
    
    Calculate the distance from the source vertex to destination vertex through this vertex 3
    
     
    
    ![matrix floyd warshall algorithm](https://cdn.programiz.com/sites/tutorial2program/files/floydwarshall-matrix-5.png "matrix A4")
    
    Calculate the distance from the source vertex to destination vertex through this vertex 4
    
5. `A4` gives the shortest path between each pair of vertices.