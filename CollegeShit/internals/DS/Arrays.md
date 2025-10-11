
###  1. 2D Array Memory Representation

**1. Row-Major Order (Used in C)**:
All elements of row `0` are stored first, followed by row `1`, and so on
##### Example:
```c
int matrix[2][3] = { {1, 2, 3}, 
                     {4, 5, 6} };

```
`1 → 2 → 3 → 4 → 5 → 6` (left to right, row by row)

#### Address Calculation:
`Base Address + ((row_index × total_columns + column_index) × element_size)`

 ##### Example: `matrix[1][2]`  
= `1000 + (1 × 3 + 2) × 4`  
= `1000 + (5 × 4)`  
= 1020 

**2. Column-Major Order :**  
All elements of the first column are stored first, followed by the second column, and so on.

`1 → 4 → 2 → 5 → 3 → 6` (top to bottom, column by column)

#### Address Calculation:
`Base Address + ( Column Index × Total Rows + Row Index ) × Element Size) `
##### Example: `matrix[1][2]`  

= `1000 + (2 × 2 + 1) × 4`  
= `1000 + (5 × 4)`  
= 1020 

### 2. Accessing Array Elements Using Pointers
#### 1D Array:
```c
#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;  // Pointer to first element

    printf("First element: %d\n", *ptr);      // 10
    printf("Second element: %d\n", *(ptr+1)); // 20
    printf("Third element: %d\n", *(ptr+2));  // 30

    return 0;
}

```

#### 2D Array:
```c
#include <stdio.h>

int main() {
    int matrix[2][2] = { {1, 2}, {3, 4} };
    int *ptr = &matrix[0][0];  // Pointer to first element

    printf("First element: %d\n", *(ptr));      // 1
    printf("Second element: %d\n", *(ptr + 1)); // 2
    printf("Third element: %d\n", *(ptr + 2));  // 3
    printf("Fourth element: %d\n", *(ptr + 3)); // 4

    return 0;
}

```

### 3. Sparse Matrix :
A **sparse matrix** is a matrix that has **a large number of zero elements** compared to non-zero elements. Instead of storing all elements (including zeros), we store only the **non-zero elements** efficiently.

##### Representation and transpose of a sparse matrix:

```c
#include <stdio.h>

#define MAX 10  // Maximum non-zero elements

struct Sparse {
    int row, col, val;
};

// Function to display sparse matrix
void display(struct Sparse sparse[], int n) {
    printf("Row  Col  Value\n");
    for (int i = 0; i < n; i++)
        printf("%d    %d    %d\n", sparse[i].row, sparse[i].col, sparse[i].val);
}

// Function to find transpose of a sparse matrix
void transpose(struct Sparse A[], struct Sparse T[], int n) {
    int i, j, k = 0;

    // Swap row and column for each non-zero element
    for (i = 0; i < n; i++) {
        T[i].row = A[i].col;
        T[i].col = A[i].row;
        T[i].val = A[i].val;
    }

    // Sort elements by row (to maintain row-wise order)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (T[i].row > T[j].row || (T[i].row == T[j].row && T[i].col > T[j].col)) {
                struct Sparse temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

int main() {
    struct Sparse sparse[MAX] = { {0, 2, 3}, {0, 4, 4}, {1, 2, 5}, {1, 3, 7}, {3, 1, 2}, {3, 2, 6} };
    int n = 6;  // Number of non-zero elements

    struct Sparse transposed[MAX]; // Array to store transpose

    printf("Original Sparse Matrix Representation:\n");
    display(sparse, n);

    // Transpose the sparse matrix
    transpose(sparse, transposed, n);

    printf("\nTransposed Sparse Matrix Representation:\n");
    display(transposed, n);

    return 0;
}

```

### 4. Searching:
#### Linear Search:
```c
#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return index where found
        }
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {10, 25, 30, 45, 60, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 45;

    int result = linearSearch(arr, n, key);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

```

##### Time Complexity:

- **Best case**: O(1) (if the element is the first one).
- **Worst and Average case**: O(n) (if the element is at the end or not present).
#### Binary Search :
```c
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + (high-low)) / 2;

        if (arr[mid] == key)
            return mid;  // Found
        else if (arr[mid] < key)
            low = mid + 1;  // Search right half
        else
            high = mid - 1;  // Search left half
    }
    return -1;  // Not found
}
```

##### Time Complexity:
- **Best case**: O(1) (if the middle element is the target).
- **Worst & Average case**: O(log⁡n) (since we reduce the array by half each time).
### 5. Sorting
#### 1. Bubble Sort

##### How it Works?
1. Compare adjacent elements and swap them if they are in the wrong order.
2. Repeat the process for all elements until no swaps are needed.
##### Time Complexity:
- **Best case**: O(n) (Already sorted).
- **Worst & Average case**: O(n^2) (Array in Descending ordered or randomly ordered).
```c
#include<stdio.h>
void bubbleSort(int a[],int size){
    int temp;
    for (int i = 0; i < size -1 ; i++){
        for (int j = 0; j< size-i-1; j++){        
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int n,i;
    printf("Enter the size of array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements for the array : \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d :", i+1) ;
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr,n);

    printf("Array after sorting :\n ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]) ;
    }
    return 0;
}

```


#### 2. Selection Sort:
##### How it Works?
- Find the **smallest element** in the unsorted part.
- Swap it with the **first element** of the unsorted part.
- Move the boundary between sorted and unsorted sections to the right.
- Repeat until the entire array is sorted.
##### Time Complexity:
- **Best case**: O(n^2) (Already sorted).
- **Worst & Average case**: O(n^2) (Array in Descending ordered or randomly ordered).
- **Space Complexity:** O(1) (sorts in place).

```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i; // Assume the current element is the smallest

        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

```
#### Insertion sort:
##### How it works?
- Assume the **first element is sorted**.
- Take the **next element**, insert it into its correct position in the sorted part.
##### Time Complexity:
- **Worst & Average Case:** O(n²)
- **Best Case (Already Sorted):** O(n)
- **Space Complexity:** O(1)
```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, hole, value;
    
    for (i = 1; i < n; i++) {
        value = arr[i];  // Current element to be inserted
        hole = i - 1;

        // Shift elements that are greater than key to the right
        while (hole >= 0 && arr[hole] > value) {
            arr[hole + 1] = arr[hole];
            hole--;
        }
        
        arr[hole + 1] = value;  // Insert the key at the correct position
    }
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

```
