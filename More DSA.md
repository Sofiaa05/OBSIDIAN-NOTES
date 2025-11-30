- Sorting (advanced)
    
- Two pointers & sliding window
    
- Recursion
    
- Backtracking
    
- BST
    
- Heaps & Priority Queue
    
- **Greedy Algorithms ← do greedy here**
    
- Graphs
    
- Dynamic Programming
    
- Tries
    
- Segment tree (optional)


### **Sort Colors (Easy version using counting / library sort)**

🔗 #75 — (Though marked Medium, the counting version is Easy)

### **2. Merge Sorted Array**

**#88**  
Classic merging two sorted arrays.

### **3. Third Maximum Number**

**#414**  
Sorting or using logic.

### **4. Largest Perimeter Triangle**

**#976**  
Sort array → check triangle condition.

### **5. Sort Array By Parity**

**#905**  
Two-pointer or sorting logic.

### **6. Sort Array By Parity II**

**#922**  
Even numbers go to even indices.

### **7. Height Checker**

**#1051**  
Compare array with sorted copy.

### **8. Minimum Absolute Difference**

**#1200**  
Sort first → then check pairs.

### **9. Relative Sort Array**

**#1122**  
Sort based on custom order.

### **10. Squares of a Sorted Array**

**#977**  
Two-pointer OR sort.

### **11. Array Partition I**

**#561**  
Sort & pick alternate elements.

### **12. Number of Good Pairs**

**#1512**  
Sort + count duplicates (optional approach).

### **13. Rank Transform of an Array**

**#1331**  
Sort unique array + map ranks.

### **14. Maximum Product of Two Elements**

**#1464**  
Sort & pick last two.

### **15. Check If N and Its Double Exist**

**#1346**  
Sort + two pointers.


```java
class Solution {
    public int largestPerimeter(int[] nums) {
         quickSort(nums, 0, nums.length - 1);
        for (int i = nums.length - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
    private void quickSort(int[] arr, int low, int high) {
        if (low >= high) return;
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }
}


```