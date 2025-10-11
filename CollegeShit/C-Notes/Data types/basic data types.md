The ~={yellow}data type=~ specifies the size and type of information the variable will store.

| Data types      | Size(in bytes) | Description                                                                          |     |
| --------------- | -------------- | ------------------------------------------------------------------------------------ | --- |
| ~={red}int=~    | 2 or 4         | Stores whole numbers, without decimals                                               |     |
| ~={red}float=~  | 4              | fractional numbers, containing one or more decimals. precision of 6-7 decimal digits |     |
| ~={red}double=~ | 8              | precision of 15 decimal digits                                                       |     |
| ~={red}char=~   | 1              | single character/letter/number, or ASCII values                                      |     |
To  get the size (in bytes) of a data type or variable, use the ~={yellow}sizeof=~ operator:
## char data type:

```C
char myGrade = 'A'; 
printf("%c", myGrade);
```

using ascii values to print a char:
```C
#include <stdio.h>

int main() {
  char a = 65, b = 66, c = 67;
  printf("%c\n", a);
  printf("%c\n", b);
  printf("%c", c);
  return 0;
}
```

If you try to store more than a single character, it will only print the last character