### Diameter of a BST
- longest possible path that you can find between any two nodes in a binary tree.
```java
import java.util.LinkedList;
import java.util.Queue;
class TreeNode{
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode (int data){
        this.data = data;
        left = null;
        right = null;
    }
}
public class BinaryTree{

    //inorder traversal
    public static void inorderTraversal (TreeNode root){
        if (root == null) return;

        //traverse the left node
        inorderTraversal (root.left);
        
        //print the root node
        System.out.print(root.data + " -> ");

        //traverse the right node
        inorderTraversal(root.right);
    }

    //pre-order traversal
    public static void preOrderTraversal (TreeNode root){
        if (root == null) return;

        //print the root node
        System.out.print(root.data + " -> ");

        //traverse the left node
        preOrderTraversal(root.left);

        //traverse the right node
        preOrderTraversal(root.right);
    }

    //post order traversal
    public static void postOrderTraversal (TreeNode root) {
        if (root == null) return;

        //traverse left node
        postOrderTraversal(root.left);

        //traverse right node
        postOrderTraversal(root.right);

        //print the root node
        System.out.print(root.data + " -> ");
    }

    //Level-Order Traversal / Breadth First Search
    public static void levelOrderTraversal (TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> queue = new LinkedList<>(); //queue is created to keep nodes in the order they should be visited
        queue.add(root); //start by adding the root node (top of the tree) into the queue.

        while ( !queue.isEmpty()) {
            TreeNode node = queue.poll(); //removes and returns the front element of the queue

            System.out.print(node.data + " -> ");

            if (node.left != null) {
                queue.add(node.left);
            }

            if (node.right != null) {
                queue.add(node.right);
            }
        }
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(9);

        root.left = new TreeNode(7);
        root.right = new TreeNode(10);

        TreeNode leftNode = root.left;
        TreeNode rightNode = root.right;

        leftNode.left = new TreeNode(6);
        // leftNode.right = new TreeNode(8);

        rightNode.left = new TreeNode(0);
        rightNode.right = new TreeNode(89);
        rightNode.right.right = new TreeNode(78);

        // System.out.println(root.data);
        // System.out.println(root.left.left.data);
        // // System.out.println(root.left.right.data);
        // System.out.println(root.right.data);
        System.out.println("Inorder Traversal: ");
        inorderTraversal(root);
        System.out.println();
        System.out.println("Pre-Order Traversal");
        preOrderTraversal(root);
        System.out.println();
        System.out.println("Post-Order Traversal");
        postOrderTraversal(root);
        System.out.println();
        System.out.println("Level-Order Traversal / Breadth First Search: ");
        levelOrderTraversal(root);

    }
}
```

| **Concept**                 | **Explanation**                  |
| --------------------------- | -------------------------------- |
| **Traversal Type**          | Breadth-First (Level-wise)       |
| **Data Structure Used**     | Queue                            |
| **Order of Visiting Nodes** | Level by level, left to right    |
| **Time Complexity**         | O(n) — each node is visited once |
| **Space Complexity**        | O(n) — for the queue             |

### Leetcode 104: Maximum Depth of Binary Tree 
(https://leetcode.com/problems/maximum-depth-of-binary-tree/)

#### Method 1: Iterative approach using BFS / Level-Order Traversal
```java
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return  0; 
        Queue <TreeNode> elementQueue = new LinkedList<>();

        elementQueue.add(root);
        int numberOfLevels = 0;

        while (true){
            int nodeCountAtLevel = elementQueue.size();
            
            if (nodeCountAtLevel == 0) {
                return numberOfLevels;
            }

            while (nodeCountAtLevel > 0) {
                TreeNode current = elementQueue.poll();

                if (current.left != null){
                    elementQueue.add(current.left);
                }
                if (current.right != null){
                    elementQueue.add(current.right);
                }
                nodeCountAtLevel--;
            }
            numberOfLevels++;
        }
    }
}
```

```plaintext
Space: O(N) -> Traversing through each node in the tree
Time: O(N) -> maintaing a queue data structure
```
#### Method 2: Recursive Approach using DFS

```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }

        int lh =  maxDepth(root.left);
        int rh =  maxDepth(root.right);
        return Math.max(lh, rh) + 1;
    }
}
```