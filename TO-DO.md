https://leetcode.com/problems/max-consecutive-ones/submissions/1615934810/
https://chatgpt.com/c/6807998a-5b2c-8005-907b-ec4efe0e62ca

---

https://leetcode.com/problems/search-a-2d-matrix/
https://chatgpt.com/c/6807998a-5b2c-8005-907b-ec4efe0e62ca

#### Method. 1 : 2d array to 1d array
- time O(log(m * n))
- space O(n*\m)
- For simplicity, when space isn’t a concern
```java
class Solution {
    public boolean searchMatrix(int[][] nums, int target) {
        int row = nums.length;
        int col = nums[0].length;
        //constructing a 1d array from 2D array then perform binary search
        int temp[] = new int[row*col];
        int k = 0;
        for(int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                temp[k++] = nums[i][j];
            }
        }
        int start = 0;
        int end = temp.length-1;

        while(start <= end){
            int mid = start + (end-start) / 2;
            if (target == temp[mid]){
                return true;
            }
            else if(target < temp[mid]){
                end = mid - 1;
            }
            else{
                start = mid+1;
            }
            
        }
        return false;   
    }
}
```
#### Method 2 : directly searching 2d array using binary search
- Matrix is globally sorted
- mapping 1D array to 2D array.
- time O(log m * n)
- space O(1)

map 1D array element to its corresponding 2d array element.
```java
for (int i = 0; i < m * n; i++) {
    int row = i / n;
    int col = i % n;
}
```

code:
```java
class Solution{
    public boolean searchMatrix(int[][] nums, int target){
        if (nums == null || nums.length == 0 || nums[0].length == 0) return false;
        int row = nums.length;
        int col = nums[0].length;

        int start = 0;
        int end = row * col - 1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int midElement = nums[mid/col][mid%col];
            if(midElement == target) return true;
            else if (target < midElement) {
                end = mid-1;
            } 
            else{
                start = mid + 1;
            }
        }
        return false;
    }
}
```

#### Method 3: for both row wise and column wise sorted matrix 
- search only within one row at a time then either decrement end pointer or increment start pointer
- time O(log n * m)
- space O(1).
```java
class Solution {
    public boolean searchMatrix(int[][] nums, int target) {
    //initialising start and end pointer for first row.
        int row = 0; 
        int col = nums[0].length - 1;

        while (row < nums.length && col >= 0) {
            if (nums[row][col] == target) {
                return true;
            } else if (target < nums[row][col]) {
                col--;  // Move left
            } else {
                row++;  // Move down
            }
        }
        return false;
    }
}

```


--- 
6-6-2025
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();

        ListNode temp1 = l1;
        ListNode temp2 = l2;
        while(temp1 != null){
            sb1.append(temp1.val);
            temp1 = temp1.next;
        }
        while(temp2 != null){
            sb2.append(temp2.val);
            temp2 = temp2.next;
        }

        int n3 = Integer.parseInt(sb1.toString()) + Integer.parseInt(sb2.toString());

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        // Special case when sum is 0
        if (n3 == 0) {
            return new ListNode(0);
        }
            
        while (n3 > 0) {
            int digit = n3 % 10;
            current.next = new ListNode(digit);
            current = current.next;
            n3 /= 10;
        }
                
        return dummy.next;
    }
}
```

### Problem 235
