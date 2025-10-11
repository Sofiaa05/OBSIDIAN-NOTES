### Transpose
```java
class Solution {
    public int[][] transpose(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int transpose[][] = new int[cols][rows];

        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
}

//transpose in place
        for(int i = 0; i < rows; i++){
            for(int j = i; j < cols; j++){
               int temp = mat[i][j];
               mat[j][i] = mat[i][j];
               mat[i][j] = temp;
            }
        }

```

### Matrix diagonal sum
```java
class Solution {
    public int diagonalSum(int[][] mat) {
        int row = mat.length;
        int col = mat[0].length;
        int sum = 0;
        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                if( i == j || i+j == row - 1){
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
}
```

### Clockise rotation (in-place)
```java

class Solution {
    public void rotate(int[][] matrix) {
       int n = matrix.length;

       //transpose
       for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i]= temp;
        }
       }

       //for clockwise rotation everse each row 
       for(int i = 0; i < n; i++){
        int left = 0, right = n-1;
        while(left < right){
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left ++;
            right--;
        }
       }
    }
}
```

### Anticlockise Rotation (in-place)
```java
class Solution {
    public void rotateMatrix(int[][] mat) {
        // code here
        int rows = mat.length;

        //transpose in place
        for(int i = 0; i < rows; i++){
            for(int j = i + 1; j < rows; j++){
               int temp = mat[i][j];
               mat[i][j] = mat[j][i];
               mat[j][i] = temp;
            }
        }
        
        //reverse each column
        for (int j = 0; j < rows; j++) { // column by column
            int top = 0, bottom = rows - 1;
            while (top < bottom) {
                int temp = mat[top][j];
                mat[top][j] = mat[bottom][j];
                mat[bottom][j] = temp;
                top++;
                bottom--;
            }        
        }
        
    }
}
```

### Search in a sorted matrix

#### Naive approach
- O(n * m) , O(1)

```java
		int n = mat.length;
        int m = mat[0].length;

        // traverse every element in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == x)
                    return true;
            }
        }
        return false;
    }
```

#### Binary search on potential row / also works for row-wise sorted matrix
- O(n logm), n = rows m = cols
```java
int rows = matrix.length;
int cols = matrix[0].length;

for(int i = 0; i < rowsl; i++){
//first check if current row elements are in the range of target
//decide row to perform search in 
	if(target >= matrix[i][0] && target <= matrix[i][cols - 1]){
		int low = 0, high = cols - 1;
		
		while (low <= high){
			int mid = low + (high - low) / 2;
			
			if(target == matrix[i][mid]) return true;
			else if(target < matrix[i][mid]){
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
	}	
}

return false;
```

#### O(log m\*n)
- Binary search on searching potential row and then binary search  to search element in that row
```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rowIdx = searchPotentialRow(matrix, target);
        if (rowIdx != -1) return binarySearchOverRow(matrix, target, rowIdx);
        else return false;
    }

    private int searchPotentialRow(int[][] matrix, int target){
        int low = 0;
        int high = matrix.length - 1;

        while (low <= high){
            int mid = low + (high - low) / 2; //random row using binary search

            //checking if potential row or not
            if (matrix[mid][0] <= target && target <= matrix[mid][matrix[0].length - 1] ) {
                return mid;
            }

            else if (target > matrix[mid][0]) low = mid + 1;
            else if (target < matrix[mid][0]) high = mid - 1;
        }

        return -1;
    }

    private boolean binarySearchOverRow(int matrix[][], int target, int rowIdx){
        int low = 0;
        int high = matrix[rowIdx].length - 1;

        while (low <= high){
            int mid = low + (high - low) / 2;

            if (matrix[rowIdx][mid] == target) return true;
            else if (target < matrix[rowIdx][mid]) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
}
```