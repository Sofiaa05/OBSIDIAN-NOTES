- Bubble sort
- Selection sort
- Insertion sort
- Time complexity: O(n^2)

## Bubble Sort
- Bubble Sort works by **repeatedly swapping adjacent elements** if they are in the wrong order.  
- After each full pass through the array, the **largest element “bubbles up”** to its correct position at the end.

```java
static void bubbleSort(int arr[], int n){
        int i, j, temp;
        boolean swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    
                    // Swap arr[j] and arr[j+1]
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were
            // swapped by inner loop, then break
            if (swapped == false)
                break;
        }
    }
```

### Time Complexity Analysis
| Case             | Explanation                                          | Time Complexity |
| :--------------- | :--------------------------------------------------- | :-------------- |
| **Best Case**    | Array already sorted (no swaps needed). Only 1 pass. | **O(n)**        |
| **Average Case** | Random order, about half swaps each pass.            | **O(n²)**       |
| **Worst Case**   | Reverse sorted, maximum comparisons and swaps.       | **O(n²)**       |
### Space Complexity Analysis
| Type                | Explanation                                         | Complexity |
| :------------------ | :-------------------------------------------------- | :--------- |
| **Auxiliary Space** | Sorting is done **in-place** (no extra array used). | **O(1)**   |
| **Total Space**     | Just variables `temp`, `swapped`.                   | **O(1)**   |

---
## Selection Sort
- Selection Sort works by **repeatedly finding the smallest (or largest) element** from the **unsorted portion** of the array and **placing it at the beginning**.

- So we “select” the smallest element in each pass — hence the name **Selection Sort**.
```java
public class SelectionSort{
	public static void selection sort(int[] arr){
		int n = arr.length;
		for (int i = 0; i < n - 1; i++){
			int minIndex = i; //// assume current index has smallest element
			
			//find index of the smallest element in remaining array
			for (int j = i + 1; j < n; j++){
				if (arr[j] < arr[minIndex]){
					minIndex = j;
				}
			}
			
			// swap the smallest element with the first element of unsorted part
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}
```
### Time Complexity Analysis
| Case             | Explanation                                                | Time Complexity |
| :--------------- | :--------------------------------------------------------- | :-------------- |
| **Best Case**    | Even if already sorted, algorithm still scans all elements | **O(n²)**       |
| **Average Case** | Regular unsorted array                                     | **O(n²)**       |
| **Worst Case**   | Reverse sorted array                                       | **O(n²)**       |
### Space Complexity Analysis

|Type|Explanation|Complexity|
|:--|:--|:--|
|**Auxiliary Space**|No extra array used|**O(1)**|
|**Total Space**|Only a few variables (`minIndex`, `temp`)|**O(1)**|

---
## Insertion Sort
- Insertion Sort works the same way you **sort playing cards in your hand**.  
- You take one card at a time and insert it into its correct position among the cards already sorted.
### Step-by-Step Logic

1. Start from the **second element** (index `1`) — assume the first element is already sorted.
    
2. Compare the current element (called `key`) with elements in the sorted part (left side).
    
3. Shift all elements **greater than `key`** one position to the right.
    
4. Insert the `key` into its correct place.
    
5. Repeat this process for all elements.

```java
public class InsertionSort{
	public void insertionsort(int[] arr){
		int n = arr.length;
		
		for (int i = 1; i < n; i++){
			int key = arr[i];
			int j = i - 1;
			
			while (j >= 0 && arr[j] > key){
				arr[j+1] = arr[j];
				i--;
			}
			
			arr[j+1] = key;
		}
	}
}
```
### Complexity Analysis
| Case                 | Explanation                                                           | Time Complexity |
| -------------------- | --------------------------------------------------------------------- | --------------- |
| **Best Case**        | Array already sorted → only 1 comparison per element                  | **O(n)**        |
| **Average Case**     | Random order → elements move halfway on average                       | **O(n²)**       |
| **Worst Case**       | Reverse sorted → each new element moves through all previous elements | **O(n²)**       |
| **Space Complexity** | In-place sorting (no extra array)                                     | **O(1)**        |

---

## Quick Sort
- **Quick Sort** is a **Divide and Conquer** algorithm.  
- It works by picking a **pivot element**, then:

- **Partitioning** the array such that:  
    → Elements **smaller than pivot** go to the **left**  
    → Elements **greater than pivot** go to the **right**
    
- Then it **recursively** sorts both parts.
    
### Step-by-Step Working

1. Choose a **pivot** (e.g., the last element).
    
2. Rearrange elements so that smaller ones come before pivot and larger ones after.
    
3. Recursively apply steps (1) and (2) to the left and right subarrays.

```java
class QuickSort{
	//function to partition the array
	public int partition(int arr[], int start, int end){
		int pivot = arr[end]; //pivot element. Usually the last element in the array
		int i = low - 1; //index of smaller element. 
		
		for (int j = low; j < end; j++){
			if (arr[j] < pivot){
				i++;
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
			//place pivot at correct position
			int temp = arr[end];
			arr[end] = arr[i + 1];
			arr[i + 1] = temp;
			
			return i + 1; //return pivot index
	}
	
	public void quicksort(int arr[], int start, int end){
		if (start < end){
			//logic for partitioning the array. pi for partition index
			int pi = partition(arr, start, end);
			quicksort(arr, low, pi - 1);
			quicksort(arr, pi + 1, end);
		}
	}
	public static void main(String[] args){
		int arr[] = {10, 7, 8, 9, 1, 5};
		int n = arr.length;
		quicksort(arr, 0, n - 1);
	}
}
```

### Complexity Analysis
|Case|Description|Time Complexity|
|---|---|---|
|**Best Case**|Pivot divides array into two equal halves|**O(n log n)**|
|**Average Case**|Random pivot|**O(n log n)**|
|**Worst Case**|Pivot always smallest or largest (e.g., sorted array)|**O(n²)**|
|**Space Complexity**|Recursive stack space|**O(log n)**|

## Merge Sort
- Merge Sort works by **dividing the array into two halves**, sorting each half recursively, and then **merging** the two sorted halves together.

- It’s based on the **Divide and Conquer** principle:
	
	1. **Divide** → Split the array into two halves.
	    
	2. **Conquer** → Sort both halves recursively.
	    
	3. **Combine** → Merge the two sorted halves into a single sorted array.

```java
class MergeSort{
	//function to merge two halves
	public void mergesort(int arr[], int start, int end){
		public void merge(int arr[], int start, int mid, int end){
			//find sizes of two subarrays
			int n1 = mid - start + 1;
			int n2 = end - mid;
			
			//create temporary arrays
			int left[] = new int[n1];
			int right[] = new int[n2];
			
			//copy data to temporary arrays
			for (int i = 0; i < n1; i++){
				left[i] = arr[start + i];
			}
			for (int i = 0; i < n2; i++){
				right[i] = arr[mid + 1 + i]
			}
			
			//merge the two temporary arrays
			int i = 0, j = 0;
			int k = start; //nitial index of merged subarray
			
			while (i < n1 && j < n2){
				if (left[i] <= right[j]){
					arr[k] = left[i];
					i++; 
				}
				else{
					arr[k] = right[j];
					j++;
				}
				k++;
			}
			
			//copy remaining elements of left subarray (if any)
			while (i < n1){
				arr[k] = left[i];
				i++;
				k++;
			}
			
			//copy remaining elements of right array (if any)
			while (j < n2){
				arr[k] = right[j];
				j++;
				k++;
			}	
		}
		
		if (start < end){
			int mid = (start + end) / 2;
			
			//sort first and second halves
			mergesort(arr, start, mid);
			mergesort(arr, mid + 1, end);
			
			//merege the sorted halves
			merge(arr, start, mid, end);
		}
	}
	public static void main(String[] args){
		int arr[] = {12, 11, 13, 5, 6, 7};
		int n = arr.length;
		mergesort(arr, 0, n - 1);
	}
}
```

### Complexity Analysis

|Case|Description|Time Complexity|
|---|---|---|
|**Best Case**|Always divides equally and merges|**O(n log n)**|
|**Average Case**|Random input|**O(n log n)**|
|**Worst Case**|Even in worst case (already sorted / reverse)|**O(n log n)**|
|**Space Complexity**|Temporary arrays used|**O(n)**|

## Radix Sort

- Radix Sort is a **non-comparative sorting algorithm** that sorts numbers **digit by digit**, starting either from:

	- **Least Significant Digit (LSD)** → rightmost digit first (most common), or
	    
	- **Most Significant Digit (MSD)** → leftmost digit first.
    
- We’ll use **LSD Radix Sort** here.

---

### How it Works 

Example: Sort \[170, 45, 75, 90, 802, 24, 2, 66]

**Step 1:** Sort by 1st digit (ones place)  
→ \[170, 90, 802, 2, 24, 45, 75, 66]

**Step 2:** Sort by 2nd digit (tens place)  
→ \[802, 2, 24, 45, 66, 170, 75, 90]

**Step 3:** Sort by 3rd digit (hundreds place)  
→ \[2, 24, 45, 66, 75, 90, 170, 802]

Final sorted list!

---

### Radix Sort uses **Counting Sort** as a subroutine

- Counting Sort is a **stable sorting algorithm** that sorts digits (0–9) efficiently.
```java
class RadixSort{

	//function to get maximum value in an array
	public static int getMax(int arr[]){
		int max = arr[0];
		
		for (int x: arr){
			if (x > max) max = x;
		}
		
		return max;
	}
	
	// Counting Sort used by Radix Sort to sort by specific digit
	public static void countingSort(int arr[], int exp){
		int n = arr.length;
		int output[] = new int[n]; //output array
		int count[] = new int[10]; //digit range 0 - 9
		
		//step 1: count occurance of each digit
		for (int i = 0; i < n; i++){
			int digit = (arr[i] / exp) % 10;
			count[digit]++;
		}
		
		//step 2: cumulative sum. Change count[i] so it contains the actual position
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}
		
		//Step 3: Build the output array (traverse backwards for stability)
		for (int i = n - 1; i >= 0; i--){
			int digit = (arr[i] / exp) % 10;
			output[count[digit] - 1] = arr[i]
			count[digit]--;
		}
		
		//Step 4: Copy the output array to arr[]
		for (int i = 0; i < n; i++){
	        arr[i] = output[i];
	    }
	}
	//main radix xort function
	public static void radixsort(int arr[]){
		int max = getMax(arr); //// Find the max number to know number of digits
		
		// Apply counting sort for every digit (1, 10, 100, 1000)
		for (int exp = 1; max / exp > 0; exp *= 10){
			countingSort(arr, exp);
		}
	}
	
	//main function
	public static void main(String[] args){
		int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
		radixsort(arr);
	}
}
```
### Complexity Analysis
|Case|Time Complexity|Explanation|
|---|---|---|
|Best|O(n·k)|k = number of digits (here, 4)|
|Average|O(n·k)|Works same for all cases|
|Worst|O(n·k)|Always processes all digits|
|Space Complexity|O(n + k)|Uses counting array and output array|
