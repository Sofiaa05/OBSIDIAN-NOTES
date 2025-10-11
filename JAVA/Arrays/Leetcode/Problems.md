### Problem 1:
#### Method 1:
```java
class Duplicate{
	public static boolean containsDuplicate(int[] A){
		for(int i=0; i<A.length; i++){
			for(int j=i+1; j<A.length; j++){
				if(A[i]==A[j]){
					return true;
				}
			}	
		}
        return false;
    }
	public static void main(String[] args){
		int A[]= {1,3,2};
		boolean res = containsDuplicate(A);
		if(res==true){
			System.out.println("true");
		}
		else{
			System.out.println("false");
		}
	}
}
```

##### Analysis:  (for both methods)
###### Time complexity: `O(n^2)`

###### Space Complexity: `O(1)`

https://leetcode.com/problems/contains-duplicate/solutions/3163705/java-best-solution-3-ways/?envType=problem-list-v2&envId=array

#### METHOD 2:


- First Sort the Array.
- Then Compare elements one by one.
- We Only have to return a boolean value.


```java
import java.util.*;
class Solution {
    public static boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);  //sort
        for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] == nums[i+1]) { //compare
                    return true;
                }
        }
        return false;
    }
    public static void main(String[] args) {
        int num[] = {1,4,2,3,5};
        if(containsDuplicate(num)){
            System.out.println("true");
        }
        else{
            System.out.println("false");
        }
    }
}

```

##### Analysis:  (for both methods)
###### Time complexity: `O(nLOGN)`

###### Space Complexity: `O(1)`

