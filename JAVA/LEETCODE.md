### Leetcode 150
https://leetcode.com/studyplan/top-interview-150/

### Leetcode 75
https://leetcode.com/studyplan/leetcode-75/

## Attempted not done
### PROBLEM 238:

#### My answer1
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int i=0, index=0, product = 1;
        int ans[] = new int[nums.length];
        while( index < nums.length){
            if(i < nums.length){
                if(index != i)
                    product *= nums[i];
            }
            i++;
            if(i >= nums.length){
                ans[index]=product;
                index++;
                product = 1;
                i=0;
            }
        }
        return ans;
    }
}
```

#### My answer 2
- using division operator
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        int p = 1;
        int count = 0; //count number of zeroes
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                count++;
            }
        }
        
        //product of all numbers except 0   
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0) continue; //dont multiply if nums[i] = 0
            p *= nums[i];
        }

        //if no zeroes are present then divide product by each number
        if(count == 0){
            for(int i = 0; i < answer.length; i++){
                answer[i] = p / nums[i];
            } 
        }
        //if one zero is present then simply put every other index value as 0 except one that contains zero and set its value as product of all numbers found earlier
        if(count == 1){   
            for(int i = 0; i < answer.length; i++){
                if(nums[i] != 0){ 
                    answer[i] = 0;
                }
                else{
                    answer[i] = p;
                }
            }
        }

        //if there are more than one zero present in array then set all elements of answer[i] to 0
        if(count > 1){
            for(int i = 0; i < answer.length; i++){
                answer[i] = 0;
            }
        }
        return answer;
    }
}
```

---

### Remove duplicates from sorted linked list
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head.next == null) return head;
        ListNode temp1 = head;
        ListNode temp2 = head.next;

        while(temp2 != null){
    
            if(temp1.val == temp2.val){
                temp2 = temp2.next;
            }
            else{
                temp1.next = temp2;
                temp1 = temp2;
                temp2 = temp2.next;

            }
        }
        return head;
    }
}
```