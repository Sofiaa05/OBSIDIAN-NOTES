- DS to store and organise data.
- Follows all properties of Binary Trees
- The left subtree of a node contains only nodes with keys less than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.  
- There must be no duplicate nodes.
### Operations :
#### 1. Insertion
#### 2. Deletion
#### 3. Searching

```c
// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node *createNode(int key){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->key=key;
	newnode->left = newnode->right = NULL;
	return newnode;
}

//insertion
void insert(struct node **root, int key){
	if(*root == NULL){
		*root = createNode(key);
        return;
	}

	if(key <= (*root)->key){
		insert((&(*root)->left),key);
	}
	else{
	insert((&(*root)->right),key);
	}
}

//void inorder traversal
void inorder(struct node* root){
	if(root==NULL) return;
	else {
		inorder(root->left);
		printf("%d ->",root->key);
		inorder(root->right);
	}
}

//searching
void search(struct node* root, int key){
	if (root==NULL){
	printf("Element not found.");
    return;
	}
	if(key == root->key){
		printf("Found");
        return;
	}
	if( key < root->key){
		search(root->left, key);
	}
	else{
		search(root->right, key);
	}
}

//inorder successor
int iSuc(struct node *root){
	root=root->right;
	while(root->left != NULL){
		root = root->left;
	}
	return root->key;
}

//deletion
void delete(struct node **root, int key){
	struct node *temp;
	if(*root==NULL) return;

	else if(key < (*root)->key){
		delete((&(*root)->left), key);
	}
	else if(key > (*root)->key){
		delete((&(*root)->right), key);
	}
	else{
		if((*root)->left == NULL){
			temp=(*root)->right;
			free(*root);
			*root=temp;
		}
		else if((*root)->right == NULL){
			temp=(*root)->left;
			free(*root);
			*root=temp;
		}
		else{
			int min = iSuc(*root);
			(*root)->key = min;
			delete(&((*root)->right), min);
		}
	}
}

int main(){
	struct node *root = NULL;
	insert(&root,2);
    inorder(root);

    printf("\n");
    search(root,5);
	delete(&root,2);
    inorder(root);

    return 0;
}
```

##### Each of these operations takes O(logn).
#### Maximum Height
**n** represents the **number of nodes**
- **Unbalanced (skewed)**: n
- **Balanced BST**: log2n
- **Random BST**: log2n 
##### How log2n for Balanced and Random?
**Number of Nodes at Each Level**

- 
    - **Level 0 (Root)**: `1` node
    - **Level 1**: `2` nodes
    - **Level 2**: `4` nodes
    - **Level 3**: `8` nodes
    - In general, at **level h**, the number of nodes is at most: 2^h

#### **2️⃣ Total Nodes in a Balanced BST**

A balanced BST has a **complete** structure, so the **total number of nodes (n) is approximately the sum of nodes at all levels**:

n ≈ 1+2+4+8+...+2^h

This forms a **geometric series**, and its sum is given by:

n ≈ 2^(h+1) − 1


n≈2^(h+1)

#### **3️⃣ Solving for Height (h)**

Taking the logarithm base 2 on both sides:

=> log⁡2(n) ≈ h+1
=> h≈log2​(n) -1 

Since we consider **big-O notation**, we drop the `-1`, so:

h=O(log⁡2(n))

- Also, Random BST is Not Perfect, But Close

	- In **random insertions**, the tree is **not fully balanced** but also **not skewed**.

---
### Strict BST: 
Properties of BST +
A **Strict Binary Tree** is a binary tree where **every node has either 0 or 2 children**. This means:

- No node has only one child.
- All internal nodes have exactly **two** children.