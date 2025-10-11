## ~={pink}Break:=~ 
Loop control statement that breaks out of the loop when encountered.

```C
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
      
          // Exit the loop when i equals 5
        if (i == 5) {
            break;  
        }
        printf("%d ", i);
    }
    return 0;
}

OUTPUT: 0 1 2 3 4
```

## ~={pink}Continue:=~
To skip the current iteration of a loop and continue with the next iteration.
```c
#include <stdio.h>

int main() {
  
    // Loop from 1 to 5
    for (int i = 1; i <= 5; i++) {
      
          // Skip 3 numbers
        if (i == 3)
            continue;
        printf("%d ", i);
    }

    return 0;
}

Output: 1 2 4 5
```