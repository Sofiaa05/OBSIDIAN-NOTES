### Initialising
```java
		int A[] = new int[10]; //creating an array object in heap.

		//or
		int B[] = {1,2,4,5,7};

		//or
		int C[];
		C=new int[5];

		//or
		int[] D = new int[5]; //or int []D

```

### Traversing 
#### 1. using for loop
```java
		B[2]=69; //changing element at index 2

		System.out.println("Using for loop");
		for(int i=0; i<B.length; i++){
			System.out.println(B[i]);
		}
```


#### 2. Using for-each loop:
```java
		System.out.println("Using for-each loop");

		for (int x: B){ //for each element of B
			System.out.print(x+ " "); 
		}

```

```plaintext
OUTPUT:

1 2 69 5 7
```

### Printing an empty array
- prints 0 for each element
```java
for(int x: A){ 
			System.out.println(x);
		}
```

```plaintext
OUTPUT:

Printing an empty array
0 0 0 0 0 0 0 0 0 0 % 
```

### incrementing elements
#### 1. Using for each loop and incrementing each element 
- can only read values and not modify them.
```java
		System.out.println("Using for-each loop and incrementing ");

		for (int x: B){ //for each element of B
			System.out.print(x++ + " "); 
		}

		System.out.println();

		for (int x: B){ //for each element of B
			System.out.print(x+ " "); 
		}
```

```plaintext 
OUTPUT: 

Using for-each loop and incrementing 
1 2 69 5 7 
1 2 69 5 7
```

#### 2. Using for loop (counter control) and incrementing
- can modify elements using for loop
```java
		System.out.println("Using for loop and incrementing");
		for(int i=0; i<B.length; i++){
			System.out.print(B[i]++ + " ");
		}
		
		System.out.println();
		
		for (int x: B){ //for each element of B
			System.out.print(x+ " "); 
		}
```

```plaintext 
OUTPUT:

Using for loop and incrementing
1 2 69 5 7 
2 3 70 6 8
```

## Programs
## Program Type-1 : Traversing array
### Program 1 : finding sum of all elements
```java
import java.util.Scanner;
public class SumArray{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter the length of array: ");
		int l = sc.nextInt();
		int A[] = new int[l];

		System.out.println("Enter the elements of array: ");
		for(int i=0; i<l; i++){
			System.out.println("Enter element " + (i+1) + ":");
			A[i] = sc.nextInt();
		}
		
		int sum=0;
		for(int x : A){
			sum += x;
		}

		System.out.println("Sum = " + sum);
		 
	}
}
```

### Program 2: Searching an element
```java
import java.util.Scanner;
public class SearchArray{
	public static void main(String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter the length of array: ");
		int l = sc.nextInt();
		int A[] = new int[l];

		System.out.println("Enter the elements of array: ");
		for(int i=0; i<l; i++){
			System.out.println("Enter element " + (i+1) + ":" );
			A[i] = sc.nextInt();
		}

		System.out.println("Enter the element to be searched: ");
		int search = sc.nextInt();

		for(int i=0; i<l; i++){
			if(A[i] == search){
				System.out.println("Element is found at index " + i);
				System.exit(0); //break will cause "not found" statement print even when element is found
			}
		}

		System.out.println("Not found"); //prints only after traversing the whole array
	}
}
```

### Program 3: Finding maximum element
```java
		int A[] = {223,34,56,78,89,0};

		int max = A[0];

		for(int x : A){
			if(x > max){
				max = x
			}
		}
		System.out.println("Maximum Element = " + max);
	}
}
```

```plaintext
OUTPUT:

Maximum Element = 223
```

### Program 4: Second largest element
```java
public class SecondMax{
	public static void main(String[] args){
		int A[] = {-223,-34,-56,-78,-89,-89};

		int max1, max2=0;
		max1 = A[0];
		

		for(int x : A){
			if(x > max1){
				max2 = max1;
				max1 = x;
			}
			else if(x > max2 && x < max1){ //update max2 only if we find a bigger number than it. 
				//and second maximum must be different from the first maximum.
				max2 = x;
			}
		}
		System.out.println("Maximum Element = " + max1);
		System.out.println("Second Maximum Element = " + max2);

	}
}
```

```plaintext
Maximum Element = -34
Second Maximum Element = -56
```

---
---

## Program Type-2: 
- rotating an array
- inserting an Element
- deleting an element
### Program 1: Rotating an array
#### Method 1: Naive method (One-by-One Rotation)
```java
class Rotate {
//left rotation
    public static void leftRotate(int A[], int n){
        for(int j=0; j<n; j++){ //start from 0 to handle n=0
            int temp = A[0];

            for (int i = 0; i < A.length-1; i++) {
                A[i] = A[i+1];
            }
            A[A.length-1] = temp;
        }
        System.out.printf("\nAfter rotating %d place(s) to left:\n", n);
        for (int x : A) {
            System.out.print(x + " ");
        }
    }

//right rotation
    public static void rightRotate(int A[],int n){
        for(int j=0; j<n; j++){
            int temp = A[A.length-1];        
        
            for (int i = A.length-1; i > 0; i--) {
                A[i] = A[i-1];                
            }
        
            A[0] = temp;                      
        }
        System.out.printf("\nAfter rotating %d place(s) to right:\n", n);
        for (int x : A) {
            System.out.print(x + " ");
        }
    }
    public static void main(String[] args) {
        int A[] = {8,9,6,10,12,4};

        System.out.println("Original Array: ");
        for (int x: A){
            System.out.print(x + " ");
        }
        int[] left = A.clone();
        int[] right = A.clone();
        leftRotate(left,1); //n is the number of places array should rotate to
        rightRotate(right,2);

    }
}

```

```plaintext
Original Array: 
8 9 6 10 12 4 
After rotating 1 place(s) to left:
9 6 10 12 4 8 
After rotating 2 place(s) to right:
12 4 8 9 6 10 %
```

##### Analysis
###### Time complexity: `O(n * len)`

###### Space Complexity: `O(1)`

#### Method 2: Using mod
```java
class Rotate{

    public static void leftmod(int A[], int n) {
        int len = A.length;
        n = n % len;
    
        // Step 1: store first n elements
        int[] temp = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = A[i];
        }
    
        // Step 2: shift remaining elements to the left
        for (int i = 0; i < len - n; i++) {
            A[i] = A[i + n];
        }
    
        // Step 3: put temp[] elements at the end
        for (int i = 0; i < n; i++) {
            A[len - n + i] = temp[i];
        }
    
        // Print result
        System.out.println("\nArray after left rotation:");
        for (int x : A) {
            System.out.print(x + ", ");
        }
    }
    
    public static void rightmod(int A[], int n) {
        int len = A.length;
        n = n % len;
    
        // Step 1: store last n elements
        int[] temp = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = A[len - n + i];
        }
    
        // Step 2: shift elements to the right
        for (int i = len - 1; i >= n; i--) {
            A[i] = A[i - n];
        }
    
        // Step 3: put temp[] at beginning
        for (int i = 0; i < n; i++) {
            A[i] = temp[i];
        }
    
        // Print result
        System.out.println("\nArray after right rotation:");
        for (int x : A) {
            System.out.print(x + ", ");
        }
    }
        public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        int[] right = arr.clone();
        int[] left = arr.clone();
        rightmod(right,4);
        leftmod(left, 4);
        
    }
}
```

##### Analysis
###### Time complexity: `O(len)`

###### Space Complexity: `O(n)`

#### METHOD 3: Reversing Array
```java
import java.util.*;

class RotateRev {

    public static void left(int[] nums, int k) {
        int n = nums.length;
        k %= n; // Handle cases where k > n

        // Step 1: Reverse first k elements
        reverse(nums, 0, k - 1);

        // Step 2: Reverse the rest
        reverse(nums, k, n - 1);

        // Step 3: Reverse the entire array
        reverse(nums, 0, n - 1);

        System.out.println("\nArray after left rotation by " + k + " places:");
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }

    public static void right(int[] nums, int k) {
        int n = nums.length;
        k %= n; // In case k > n

        reverse(nums, 0, n - 1);     // Step 1: Reverse whole array
        reverse(nums, 0, k - 1);     // Step 2: Reverse first k elements
        reverse(nums, k, n - 1);     // Step 3: Reverse rest
        
        System.out.print("Array after right rotation by " + k + " places:\n");
        for (int num : nums) {
            System.out.print(num + " ");
        }

    }

    public static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        int k = 9;

        int right[] = nums.clone();
        int left[] = nums.clone();
        right(right, k);
        left(left,k);

    }
}

```

##### Analysis
###### Time complexity: `O(len)`

###### Space Complexity: `O(1)`

___
____


### Program 2 : Inserting an element
- insertion using index, if asked to insert after or before particular element, first search that element and return index then use this index to insert before/after it.

#### Method 1: Naive solution

```java

public class Insert {
    public static void insertEl(int A[], int index, int x){
        int len = A.length;
        int temp[] = new int[len-index];
        int tlen = temp.length;
        for(int i=0; i<tlen; i++){
            temp[i]=A[index+i];
        }

        rotate(temp, 1);
        for(int i =0; i<tlen; i++){
            A[index+i]=temp[i];
        }
        A[index]=x;
        System.out.printf("\nArray after Inserting %d at position %d\n", x,index);
        for(int el:A){
            System.out.print(el + " ");
        }
    }
    public static void rotate(int temp[], int k){
        int len = temp.length;
        reverse(temp, 0, len-1);
        reverse(temp, 0, k-1);
        reverse(temp, k, len-1);
    }

    public static void reverse(int A[], int start, int end){
        while(start<end){
            int temp = A[start];
            A[start]=A[end];
            A[end]=temp;
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        int A[] = new int[10];
        A[0] = 5;
        A[1] = 9;
        A[2] = 6;
        A[3] = 10;
        A[4] = 12;
        A[5] = 7;

        System.out.println("Original Array: ");
        for (int i : A) {
            System.out.print(i + " ");
        }
        insertEl(A, 3, 20);
        insertEl(A, 5, 69);
    }
}

```

##### Analysis
###### Time complexity: `O(n-index)`

###### Space Complexity: `O(n-index)`

#### Method 2:  (Best) Inplace insertion

```java

public class InsertInplace {
    public static boolean insertEl(int[] A, int index, int x, int size) {
        if (size >= A.length || index < 0 || index > size) {
            System.out.println("Array is full. Cannot insert.");
            return false;
        }

        // Step 1: Shift elements right from the end to the index
        for (int i = size; i > index; i--) {
            A[i] = A[i - 1];
        }

        // Step 2: Insert the element at index
        A[index] = x;

        // Step 3: Print updated array
        System.out.printf("\nArray after Inserting %d at index %d:\n", x, index);
        for (int i = 0; i <= size; i++) {
            System.out.print(A[i] + " ");
        }
        return true;
    }

    public static void main(String[] args) {
        int[] A = new int[10]; // Capacity 7
        A[0] = 5;
        A[1] = 9;
        A[2] = 6;
        A[3] = 10;
        A[4] = 12;
        A[5] = 7;
        int size = 6; // Currently 6 elements
        if(insertEl(A, 3, 20, size)) size++;
        if(insertEl(A, 4, 20, size)) size++;
    }
}
```

##### Analysis
###### Time complexity: `O(n-index)`

###### Space Complexity: `O(1)`
#### Method 3: Creating new array

```java

public class InsertNewArray {
    public static int[] insertEl(int A[], int index, int element){
        if (index<0 || index>A.length) {
            throw new IndexOutOfBoundsException();
        }
        int[] newA = new int[A.length+1];

        // Copy elements before the index
        System.arraycopy(A, 0, newA, 0, index);

        newA[index] = element;

        System.arraycopy(A, index, newA, index+1, A.length-index);

        return newA;
    }
    public static void main(String[] args) {
        int A[] = {5,9,6,10,12,4,2};

        A=insertEl(A, 0, 69);
        A=insertEl(A, 1, 69);
        A=insertEl(A, 8, 69);

        System.out.printf("\nArray after insertion \n");
            for (int i : A) {
                System.out.print(i + " ");
            }
    }
}

```

```plaintext
Array after insertion 
69 69 5 9 6 10 12 4 69 2
```

##### Analysis
###### Time complexity: `O(n)`

###### Space Complexity: `O(n+1)`

___
---


### Program 3 : Deleting Element
- deletion using index, if asked to delete particular element, first search that element and return index then use this index to delete it.
#### Method 1: In place deletion
```java

public class deleting {
    public static boolean delete(int A[], int index, int size){
        if (index<0 || index>size || size>=A.length){
            System.out.println("Array is full. Cannot insert.");
            return false;
        }   
        for(int i=index; i<size; i++){
            A[i]=A[i+1];
        }

        System.out.printf("\nArray after deleting element at index %d:\n", index);
        for (int i = 0; i < size; i++) {
            System.out.print(A[i] + " ");
        }
        return true;     
    }
    public static void main(String[] args) {
        int A[] = new int[10];
        A[0] = 5;
        A[1] = 9;
        A[2] = 6;
        A[3] = 10;
        A[4] = 12;
        A[5] = 7;
        int size = 6;
        if(delete(A, 1, size));
        if(delete(A, 3, size));
    }
}
```

```plaintext
Array after deleting element at index 1:
5 6 10 12 7 0 
Array after deleting element at index 3:
5 6 10 7 0 0 %  
```

##### Analysis
###### Time complexity: `O(n)`

###### Space Complexity: `O(1)`


#### METHOD 2: Lazy deletion (Mark as deleted)

```java
public class lazedel {
    public static void main(String[] args) {
        int[] A = {5, 9, 6, 10, 12, 7};      // original array
        boolean[] deleted = new boolean[A.length]; // all false initially

        // Lazy delete at index 1 and 3
        lazyDelete(deleted, 1);  // Mark element at index 1 (9)
        lazyDelete(deleted, 3);  // Mark element at index 3 (10)

        // Display non-deleted elements
        System.out.println("Array after lazy deletions:");
        for (int i = 0; i < A.length; i++) {
            if (!deleted[i]) {
                System.out.print(A[i] + " ");
            }
        }
    }

    static void lazyDelete(boolean[] deleted, int index) {
        if (index >= 0 && index < deleted.length) {
            deleted[index] = true;
        }
    }
}

```

```plaintext
Array after lazy deletions:
5 6 12 7 
```

##### Analysis: 
###### Time complexity: `O(1)`

###### Space Complexity: `O(n)`

---
---
## Program Type -3
- copying an array
- reverse copying an array
- increasing size of array
### Program 1: Copying an array

```java
import java.util.*;
public class Copy {
    //Method 2
    public static void arraycopy(int A[],int B[]){
        System.arraycopy(A, 0, B, 0, A.length);
        System.out.printf("\nusing System.arraycopy: \n");
        for(int x: B){
            System.out.print(x+ " ");
        }
    }
    //Method 3 (changes arent refelct in og B)
    public static void copyOf(int A[], int B[]){
        B = Arrays.copyOf(A, A.length);
        System.out.printf("\nusing Arrays.copyOf: \n");
        for(int x: B){
            System.out.print(x+ " ");
        }
    }
    
    //Method 3 (changes arent reflect in og B)
    public static void clone(int A[], int B[]){
        B = A.clone();
        System.out.printf("\nusing clone(): \n");
        for(int x: B){
            System.out.print(x+ " ");
        }
    }
    public static void main(String[] args) {
        int A[]= {1,2,3,4,5,6,7,8,10};
        int B[] = new int[A.length];

        //Method 1
        for(int i=0; i<A.length; i++){
            B[i] = A[i];
        }
        
        System.out.println("Copied array using manual loop: ");
        for (int x : B) {
            System.out.print(x + " ");   
        }

        arraycopy(A, B);
        copyOf(A, B);
        clone(A,B);
    }
}

```
##### Analysis:  (for all methods) :
###### Time complexity: `O(n)`

###### Space Complexity: `O(n)`

### Program 2: Reverse copying an array
#### METHOD 1: Manual looping
```java
        int A[] = {1,2,3,4,5,6};
        int B[] = new int[A.length];
        int newB[] = A.clone();

        for(int i=0; i<A.length; i++){
            B[B.length-1-i]=A[i];
        }
        System.out.printf("Reversed copy using manual loop: \n");
        for (int x : B) {
            System.out.print(x+" ");
        }
```

#### METHOD 2: First reverse and copy
```java
    public static void reverse(int A[], int B[]){
        int start = 0;
        int end= A.length-1;
        while(start<end){
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;    
        }
        
        System.arraycopy(A,0,B,0,A.length);
        System.out.printf("\nReverse Array copied using reverse function\n");
        for (int x : B) {
            System.out.print(x+ " ");
        }
    }

```

##### Analysis:  (for both methods)
###### Time complexity: `O(n)`

###### Space Complexity: `O(n)`

### Program 3: Increasing size of an array
- declare another array of new size

```java package Copy;

public class IncrSize {
    public static void main(String[] args) {
        int A[]={1,2,3,4,5};
        int B[] = new int[2*A.length]; //new array

        System.out.println("Length before increasing size: "+ A.length);

        System.arraycopy(A,0,B,0,A.length-1);
        A=B;  //A becomes B
        B=null; 
        System.out.printf("After increasing size: \n");
        for(int x: A){
            System.out.print(x+ " ");
        }
        System.out.print("\nLength after increasing size: " + A.length);

    }
}

```

```plaintext
Length before increasing size: 5
After increasing size: 
1 2 3 4 0 0 0 0 0 0 
Length after increasing size: 10% 
```

---
## Program Type -4:
- Merging two arrays
### Problem 8: Merging two Arrays:
#### Method 1: Two-Pointers 
- two pointer merge using new array 
- (sorted + combine)? use two pointers
```java
import java.util.Arrays;
class Merge{

	//method 1: Two pointers
	static int[] twoPointers(int a[], int b[]){
		int n = a.length;
		int m = b.length;
		int res[] = new int[n+m]; //creating array of size (n+m)

		int i=0, j=0, k=0; //i for a[]; j for b[]; k for res[]

		if (n==0) System.arraycopy(b,0, res,0, b.length); //if first array is empty
		else if(m==0) System.arraycopy(a,0, res,0, a.length); // if second array is empty

		while(i<n && j<m){
			if(a[i]<b[j]){
				res[k++]=a[i++];
			}
			else{
				res[k++]=b[j++];
			}
		}

		// if elements are still left in a[]:
		while(i<n){
			res[k++]=a[i++];
		}

		//if elements are still left in b[]:
		while(j<m){
			res[k++] = b[j++];
		}

		return res;
	}
	public static void main(String[] args){
		int a[] = {6,69};
		int b[] = {2,34,56};
		String res = Arrays.toString(twoPointers(a,b));
		System.out.printf("\n Using Two pointers: %s \n" , res);

	}
}
```

```plaintext
 Using Two pointers: [2, 6, 34, 56, 69]
```

| Metric           | Value        | Why?                         |
| ---------------- | ------------ | ---------------------------- |
| Time Complexity  | **O(n + m)** | You traverse each array once |
| Space Complexity | **O(n + m)** | You store the merged array   |
#### Method 2: In place
- In place merge from end (merge within either one array)
- Why from end:? We don’t want to **overwrite the beginning of `arr1`** where valid elements are.
- (sorted+combine) and **Space-restricted?** → Use **in-place**
```java
	static int[] inPlace(int []a, int []b, int n, int m){
		int i=n-1, j=m-1, k= m+n-1;

		while(i>=0 && j>=0){
			if(a[i]>b[j]){
				a[k--]=a[i--];
			}
			else{
				a[k--]=b[j--];
			}
		}

		//b[] is non empty
		while(j>=0){
			a[k--]=b[j--];
		}
		return a;
	}
	public static void main(String[] args){
		//input arrays must be sorted
		int b[] = {2,7,34,56};
		int n = 3, m=4; //n=size of a and  m= size of b

		int arr1[] = new int[n+m]; 
		arr1[0]=4;
		arr1[1]=6;
		arr1[2]=7;

		System.out.printf("\n Using In Place %s \n" , Arrays.toString(inPlace(arr1,b,n,m)));
	}

```

```plaintext
 Using In Place [2, 4, 6, 7, 7, 34, 56] 

```

| Metric           | Value        | Why?                                           |
| ---------------- | ------------ | ---------------------------------------------- |
| Time Complexity  | **O(n + m)** | Every element from both arrays is visited once |
| Space Complexity | **O(1)**     | Merge is done in-place using existing memory   |
#### More ways to solve this (to be studied later)
![[Pasted image 20250415202149.png]]