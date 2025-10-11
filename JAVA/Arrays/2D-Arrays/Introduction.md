- A **2D array** is like a **table** or a **matrix** — it’s an **array of arrays**.  
- It’s used to store data in rows and columns.
- Each element is automatically initialized to **0** (default for `int`).
-  Java stores 2D arrays as an **array of references to 1D arrays**.
- That’s why you can have jagged arrays — each row is just a separate 1D array.

## Common Use Cases

1. **Matrices (Math operations)**
    
2. **Game boards (Tic Tac Toe, Sudoku)**
    
3. **Grids (Maps, pathfinding algorithms)**
    
4. **Tabular data (like Excel)**

##### Always Use Local Variables Instead of `matrix.length` & `matrix[0].length`.
### Initialisation:
```java
int A[][] = new int[3][4]. //array with 3 rows and 4 columns

//or
int A[][] = {{1,2,3,4}, {5,6,7,8},{1,3,5,7}}

//or
int A[][];
A = new int[3][4]

//or 
int[][] A = new int[5][5];

//or 
int[] A[] = new int[5][5];

//important notes:
int[] A,B[]; //creates A as 1D array and B as 2D array

A = new int A[5]; //int[] A = new int[5]; 1D
B = new int [5][5]; //int[] B[] = new int[5][5];  //2D

//another example
int[] A,B,C,D,E[]; //Creates 1D array for A,B,C,D and 2D array for E



```

### Jagged Array:
-  Don’t assume all rows have the same length in jagged arrays.
-  Always check `array.length` and `array[i].length`.
- Different sizes per row

```java
int[][] jagged = new int[3][];
jagged[0] = new int[2]; // row 0 has 2 columns
jagged[1] = new int[3]; // row 1 has 3 columns
jagged[2] = new int[1]; // row 2 has 1 column

```
### Traversing: 
- Using  Nested `for` loops
#### Using for loop:
```java
        for(int rows = 0; rows < A.length; rows++){ //A.length actually gives rows
            for(int col=0; col<A[0].length; col++){ //A[rows].length gives column
                System.out.print(A[rows][col] + " ");
            }
            System.out.print("\n");
        }

```

#### Using for-each loop (simpler but read-only)
```java
    System.out.print("\nUsing for-each loop: \n");
    for (int[] rows : A) {  //subarray 
        for( int col: rows){ //elements of subarray
            System.out.print(col + " ");
        }
        System.out.println();
    }
```

## Practice Questions:
### Q1. Add two matrices :
```java
    static int[][] q1(int A[][], int B[][]){
        if(A.length != B.length || A[0].length != B[0].length){
            System.out.println("Matrix dimensions do not match!");
            return null; // or throw new IllegalArgumentException("Incompatible dimensions");        
        }

        int[][] C = new int[A.length][A[0].length];
        System.out.println("Printing within the loop and inside the function: ");
        for(int i=0; i < A.length; i++){
            for(int j=0; j < A[i].length; j++){
                C[i][j] = A[i][j] + B[i][j];
                System.out.print(C[i][j] + " ");
            }
            System.out.println();

        }
        return C;
    }

    public static void main(String[] args) {
        int A[][] = {{3,5,9}, {7,6,2}, {4,3,5}};
        int B[][] = {{1,5,0}, {6,8,0}, {3,9,0}};
        A = q1(A,B);
        System.out.println("Printing in main method: ");
          for(int []rows: A){
            for(int col: rows){
                System.out.print(col + " ");
            }
                System.out.println();
        }
//can either return a 2d array or simply print inside the function
```

### Q2.  Row Sum / Column Sum
```java
	static void q3(){
        int A[][] = {{3,5,9}, {7,6,2}, {4,3,5}};
        int rowSum = 0, colSum = 0;

        //row sum: keep row number same for the row ehose sum is needed
        for(int col=0; col < A[0].length; col++){
            rowSum += A[1][col];
        } 
        System.out.println("Row sum is = " + rowSum);
        //column sum: keep column number same for the column whose sum is needed
        for( int row = 0; row < A[0].length; row++){
            colSum += A[row][1];
        }  
        System.out.println("Column sum is = " + colSum);  

        //sum of each row: 
        for(int row = 0; row < A.length; row++){
            int row_sum = 0;
            for(int col = 0; col < A[0].length; col++){
                row_sum += A[row][col]; 
            }
            System.out.println("sum of row " + row + " is = " + row_sum);
        }

        //sum of each column
        for(int col = 0; col < A.length; col++){
            int col_sum = 0;
            for(int row = 0; row < A[0].length; row++){
                col_sum += A[row][col]; 
            }
            System.out.println("sum of column " + col + " is = " + col_sum);
        }
    }
```

### Q3. Matrix Multiplication
```java
    static int[][] q2(int A[][], int B[][]){
        int m1 = A.length, m2 = B.length;
        int n1 = A[0].length, n2= B[0].length;

        if(m2 != n1){
            System.out.println("Matrix dimensions do not match for multiplication!");
            return null;
        }
        int C[][] = new int[m1][n2]; //row of first matrix & col of second matrix

  
        for(int i=0; i<m1; i++){ //row of first matrix
            for(int j=0; j < n2; j++){ //col of second matrix
                C[i][j] = 0;
                for(int k=0; k < m1; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
```

### Q4. Transpose of a matrix:
```java
    class Solution {
    public int[][] transpose(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] transpose = new int[cols][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transpose[j][i] = matrix[i][j]; //row elements become column elements and vice versa
            }
        }

        return transpose;
    }
}
```

### Q5. Searching in a Matrix:
```java
    static int[] q5(int arr[][], int element){
        int i = 0, j=0;
        for( i=0; i<arr.length; i++){
            for(j=0; j<arr[0].length; j++){
                if(arr[i][j] == element){
                    return new int[] {i,j};
                }
            }
        }
        return null;
    }
    public static void main(String[] args) {
        int A[][] = {{3,5,9}, {7,6,2}, {4,3,5}};
        int[] pos = q5(A, 6);
        if (pos != null) {
            System.out.println("Element found at: (" + pos[0] + ", " + pos[1] + ")");
        } 
        else {
            System.out.println("Element not found.");
        }
    }
```

