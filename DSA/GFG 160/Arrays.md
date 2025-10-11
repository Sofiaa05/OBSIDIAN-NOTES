### 1. Second Largest
```java
class Solution {
    public int getSecondLargest(int[] arr) {
     
        if(arr.length == 0 || arr.length < 2) return -1;
        int max1 = -1;
        int max2 = -1;
        
        for(int num: arr){
            if(num > max1){
                max2 = max1;
                max1 = num;
            }
            else if(num > max2 && num  max1){
                max2 = num;
            }
        }
        
        return max2;
    }
}

//O(n)
```

#### Method 2: Sorting
```java
class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        if(arr.length == 0 || arr.length < 2) return -1;
        Arrays.sort(arr); //O(n log n)
        
        int n = arr.length;
        int largest = arr[n-1];
        
        for(int i = n - 2; i >= 0; i--){ //O(n)
            if(arr[i] < largest){
                return arr[i];
            }
        }
        
        return -1;
    }
}

//O(n log n)
```

### 2. Move zeroes to end
#### Method 1: Extra array (Naive approach)
```java
// User function Template for Java

class Solution {
    void pushZerosToEnd(int[] arr) {
        // code here
        int temp[] = new int[arr.length];
        int j = 0;

        //finding non zero elements
       for(int i = 0; i < arr.length; i++){
           if(arr[i] != 0){
               temp[j++] = arr[i];
           }
       }
       
       //adding zero to end
       while(j < arr.length){
           temp[j++] = 0;
       }
       
       //copying temp to original array
       for(int i = 0; i < arr.length; i++){
           arr[i] = temp[i];
       }
    }
}

//O(n) time and space
```

#### Method 2: Better appraoch (Two traversals)
- similar to above but O(1) extra space
```java
// User function Template for Java

class Solution {
    void pushZerosToEnd(int[] arr) {
        
//to count non-zero elements and position of next non-zero element at that count
        int count = 0; 
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != 0){
                arr[count++] = arr[i];
            }
        }
        while(count < arr.length){
            arr[count++] = 0;
        }
    }
}

//O(n) time and O(1) space
```

#### Method 3: Optimal approach (One pass)
```java
class Solution {
    void pushZerosToEnd(int[] arr) {
    
        int count = 0;
        int i = 0;
        while(count < arr.length){
            if(arr[count] != 0){
                int temp = arr[count];
                arr[count] = arr[i];
                arr[i] = temp;
                i++;
            }
            count++;
        }
    }
}
```

### 3. Reverse an array

#### Method 1: Extra array

```java
class Solution {
    public void reverseArray(int arr[]) {
        // code here
        int temp[] = new int[arr.length];
        int j = 0;
        
        for(int i = arr.length - 1; i >= 0; i--){
            temp[j++] = arr[i];
        }
        
        for(int i = 0; i < arr.length; i++){
            arr[i] = temp[i];
        }
    }
}

//time O(n) space O(n)
```
#### Method 2: Optimal - 1: Two pointers and swap
```java
class Solution {
    public void reverseArray(int arr[]) {
        // code here
        int left = 0;
        int right = arr.length - 1;
        
        while(left < right){
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            left++;
            right--;
        }
    }
}
//time O(n) space O(1)
```

#### Method 3: Optimal - 2: Iterate half array
- iterate over the **first half** of the array and **swap** each element with its corresponding element from the end. So, while iterating over the first half, any element at index i is swapped with the element at index ****(n - i - 1)****.
```java
class Solution {
    public void reverseArray(int arr[]) {
        // code here
        int n = arr.length;
        //iterate over half array
        for(int i = 0; i < n / 2; i++){
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
}
```

### 4. Rotate an array (counterClockWise/left)

#### Method 1: Naive approach (Brute Force):

```java
class Solution {
    static void rotateArr(int arr[], int d) {
        for(int i = 0; i < d; i++){
            int first = arr[0];
            
            for(int j = 0; j < arr.length - 1; j++){
                arr[j] = arr[j + 1];
            }
            arr[arr.length - 1] = first;
        }
        
    }
}

//O(n^2)
```

#### Method 2: Temporary array (Better Approach)
```java
class Solution {
    static void rotateArr(int arr[], int d) {
        int n = arr.length;
        if (n == 0) return; 
        
        d= d%n; //Ensure d is within the bounds of the array length
        int temp[] = new int[n];
        int j = 0;

		//copy rest elements 
        for(int i = d; i < n; i++){
            temp[j++] = arr[i];
        }

//copy first d elements
        for(int i = 0; i < d; i++){
            temp[j++] = arr[i];
        }
        
        //cooying temp to og
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
    }
}
```

#### Method 3: Reversing (Optimal approach)

```java
class Solution {
    static void rotateArr(int arr[], int d) {
        int n = arr.length;
        d %= n;
        if(n == 0) return;
        reverse(arr, 0, d - 1); //first d elements
        reverse(arr, d, n - 1); //rest elements
        reverse(arr, 0, n - 1); //reverse entire array
    }
    
    static void reverse(int arr[], int start, int end){
        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}
```
