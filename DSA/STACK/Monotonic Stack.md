A **monotonic stack** is a stack that is maintained in **sorted order** (either increasing or decreasing) as you push elements into it.

- **Monotonic Increasing Stack** → elements inside stack are always in **increasing order** from bottom to top.
    
- **Monotonic Decreasing Stack** → elements inside stack are always in **decreasing order** from bottom to top.
    

-  The "monotonic" part means **the order is preserved** (non-decreasing or non-increasing).

---

It is commonly used to solve problems like:

- **Next Greater Element** (find next number greater than current).
    
- **Next Smaller Element** (find next smaller number).
    
- **Stock Span problem**.
    
- **Largest Rectangle in Histogram**.
    
- **Trapping Rain Water**.
    

Basically, when you need to efficiently find "next greater/smaller element" in an array, monotonic stacks help reduce time complexity from **O(n²) → O(n)**

![[Pasted image 20250823163343.png]]