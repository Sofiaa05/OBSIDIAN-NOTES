converting one data type to another 

### Implicit Type Conversion:
- done automatically by compiler

```C
// Automatic conversion: float to int  
int myInt = 9.99;  
  
printf("%d", myInt); // 9


// Automatic conversion: int to float  
float myFloat = 9;  
  
printf("%f", myFloat); // 9.000000
```

### Explicit Conversion

Explicit conversion is done manually by placing the type in parentheses ~={yellow}()=~ in front of the value.
```C
#include <stdio.h>

int main() {
  int num1 = 5;
  int num2 = 2;
  float sum = (float) num1 / num2;

  printf("%f", sum);
  return 0;
}
```
