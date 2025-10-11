Height of Complete Binary Tree (h):
2^h ≤ n ≤ 2^(h+1) - 1

To find height:
Keep increasing h until:
2^h ≤ n ≤ 2^(h+1) - 1

Nodes in full tree up to height h-1:
Total_nodes = 2^0 + 2^1 + 2^2 + ... + 2^(h-1) = 2^h - 1

Nodes at the last level:
Nodes_at_last_level = n - (2^h - 1)


Try with h=4h 

- 2^4=16
    
- 2^5−1=31
    

So, 16≤27≤31

✔️ This range is correct, so:

> ✅ **Height = 4**

also,

27−15=12 nodes at the last level

---
## BST
- The left subtree of a node contains only nodes with keys lesser than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

![](https://media.geeksforgeeks.org/wp-content/uploads/20230304161652/Untitled.png)

Binary Search Tree - Structure

A BST supports operations like search, insert, delete, maximum, minimum, floor, ceil, greater, smaller, etc in O(h) time where h is height of the BST. 

### INSERTION in BST
A new key is always inserted at the leaf by maintaining the property of the binary search tree. We start searching for a key from the root until we hit a leaf node. Once a leaf node is found, the new node is added as a child of the leaf node. The below steps are followed while we try to insert a node into a binary search tree:

- Initilize the current node (say, ****currNode or node****) with root node
- Compare the ****key**** with the current node.
- ****Move left**** if the ****key**** is less than or equal to the current node value.
- ****Move right**** if the ****key**** is greater than current node value.
- Repeat steps 2 and 3 until you reach a leaf node.
- Attach the ****new key**** as a left or right child based on the comparison with the leaf node's value.
### SEARCHING in BST
Let's say we want to search for the number ****X,**** We start at the root. Then:

- We compare the value to be searched with the value of the root. 
    - If it's equal we are done with the search if it's smaller we know that we need to go to the left subtree because in a binary search tree all the elements in the left subtree are smaller and all the elements in the right subtree are larger. 
- Repeat the above step till no more traversal is possible
- If at any iteration, key is found, return True. Else False.
### DELETION in BST

1. If the node is a leaf node, remove it by removing the link to it.
2. If the node only has one child node, connect the parent node of the node you want to remove to that child node.
3. If the node has both right and left child nodes: Find the node's in-order successor, change values with that node, then delete it.
### BST Construction from Preorder:
- write inorder (arrange preorder in ascending order)
- then create tree (you know the drill).
### BST Construction from Postorder:
- reverse postorder
- arrange reversed postorder in ascending order
- then create tree (you know the drill).
----
## AVL TREES
### Rotating the subtrees (Used in Insertion and Deletion)

An AVL tree may rotate in one of the following four ways to keep itself balanced while making sure that the BST properties are maintained.

****Left Rotation****:

When a node is added into the right subtree of the right subtree, if the tree gets out of balance, we do a single left rotation.

![](https://media.geeksforgeeks.org/wp-content/uploads/20221229131815/avl11-(1)-768.png)

Left-Rotation in AVL tree

****Right Rotation****:

If a node is added to the left subtree of the left subtree, the AVL tree may get out of balance, we do a single right rotation.

![avl-tree](https://media.geeksforgeeks.org/wp-content/uploads/20231102165654/avl-tree.jpg)

Right-Rotation in AVL Tree

  

****Left-Right Rotation****:

A left-right rotation is a combination in which first left rotation takes place after that right rotation executes.

![](https://media.geeksforgeeks.org/wp-content/uploads/20221229131629/avl33-(1)-768.png)

Left-Right Rotation in AVL tree

****Right-Left Rotation****:

A right-left rotation is a combination in which first right rotation takes place after that left rotation executes.

![](https://media.geeksforgeeks.org/wp-content/uploads/20221229131517/avl44-(1)-768.png)

### AVL INSERTiON and DELETION
- perform same as you would in bst
- check balance factor and perform rotations if needed.
- repeat above steps.
---
## B Trees
![[Pasted image 20250528125045.png]]