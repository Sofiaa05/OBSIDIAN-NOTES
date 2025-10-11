Nested loops are loops **inside other loops**, used for **repetitive tasks within repetitions**—like **printing patterns, matrices, or traversing 2D arrays**

```java
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 5; j++) {
        System.out.print(i * j + "\t");
    }
    System.out.println();
}

```

```plaintext
OUTPUT:

1	 2	 3	 4	 5	 
2	 4	 6	 8	 10	 
3	 6	 9	 12	 15	 
4	 8	 12	 16	 20	 
5	 10	 15	 20	 25	 
6	 12	 18	 24	 30	 
7	 14	 21	 28	 35	 
8	 16	 24	 32	 40	 
9	 18	 27	 36	 45	 
10	 20	 30	 40	 50
```
## Patterns
### Pattern 1:
```java
		for (int i=1; i<=5; i++){
			for(int j=1; j<=5; j++){
				System.out.print(j + " ");
			}
			System.out.println();
		}

```

```plaintext
OUTPUT:

1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
```

### Pattern 2:
```java
		for (int i=1; i<=5; i++){
			for(int j=1; j<=5; j++){
				System.out.print(i + " ");
			}
			System.out.println();
		}

```

```plaintext
OUTPUT:

1 1 1 1 1 
2 2 2 2 2 
3 3 3 3 3 
4 4 4 4 4 
5 5 5 5 5
```
### Pattern 3:
```java
		int count=0;
		for (int i=1; i<=5; i++){
			for(int j=1; j<=5; j++){
				System.out.format("%02d " , ++count);
			}
			System.out.println();
		}

```

```plaintext
OUTPUT:

01 02 03 04 05 
06 07 08 09 10 
11 12 13 14 15 
16 17 18 19 20 
21 22 23 24 25 
```

##### NOTE FOLLOWING PATTERN INVOLVES TWO LOOP (SINGLE PATTERNS)
### Pattern 4:  Right Angled Triangle
```java
		for (int i=1; i<=5; i++){
			for(int j=1; j<=i; j++){
				System.out.print("j" + " "); //can put * in place of j
			}
			System.out.println();
		}

```

```plaintext
OUTPUT:

1  
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

* 
* * 
* * * 
* * * * 
* * * * *
```
### Pattern 5:
```java
		int count=0;
		for (int i=1; i<=5 ; i++){
			for(int j=1; j<=i; j++){
				System.out.format("%02d ", ++count);
			}
			System.out.println();
		}

```

```plaintext
OUTPUT:

01 
02 03 
04 05 06 
07 08 09 10 
11 12 13 14 15
```
### Pattern 6.1: Inverted Right angled triangle
- reversing outer loop

```plaintext

printing j

1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 

printing i

5 5 5 5 5 
4 4 4 4 
3 3 3 
2 2 
1
```

```java
		for(int i=5; i>=1; i--){
			for(int j=1; j<=i;j++){
				System.out.print(j + " "); // if printing i in place of j
			}
			System.out.println();
		}
```
### Pattern 6.2: above pattern also be done as: (without reversing outer loop)
```java
		for(int i=1; i<=5; i++){
			for(int j=1; j<=5-i+1;j++){
				System.out.print(j + " "); //can print i in place of j
			}
			System.out.println();
		}

```

```plaintext
OUTPUT: printing i

1 1 1 1 1 
2 2 2 2 
3 3 3 
4 4 
5
```
### Pattern 7: Right aligned inverted triangle
```plaintext
 * * * * * 
   * * * * 
     * * * 
       * * 
         *
```

```java
		for(int i=1; i<=5; i++){
			System.out.print(" ");
			for(int j=1; j<=5;j++){
				if(i<=j){
					System.out.print("* ");
				}
				else{
					System.out.print("  ");
				}
			}
			System.out.println();
		}
//OR
		int rows =5;
		for (int i = rows; i>=1; i--){
			for(int space=0; space < rows-i; space++){
				System.out.print("  ");
			}

			for(int star=1; star <= i; star++ ){
				System.out.print("* ");
			}
			System.out.println(" ");
		}


```
### Pattern 8: Reversed Right angled triangle
```plaintext

        * 
      * * 
    * * * 
  * * * * 
* * * * *
```

```java
		for(int i=5; i>=1; i--){
			for(int j=1; j<=5;j++){
				if(i>j){
					System.out.print("  ");
				}
				else{
					System.out.print("* ");
				}
			}
			System.out.println();
		}

//or
		int rows=5;
		for(int i=1; i<=rows; i++){
			for(int space=1; space <= rows-i; space ++){
				System.out.print("  ");
			}
			for(int star=1; star <=i; star++){
				System.out.print("* ");
			}
			System.out.println();
		}

```

##### NOTE: Following patterns involve mixture of above patterns 
- use `i`, `space` , `star` loops
### Pattern 8 : Pyramid 

```plaintext
        * 
      * * * 
    * * * * * 
  * * * * * * * 
* * * * * * * * * 
```

```java
		int rows =12;
		for(int i=1; i<=rows; i++){ //handles rows and moving to next line
			//space handles particular space count "  "
			for(int space = 1; space <= rows-i; space++){
				System.out.print("  ");
			}
			//star handles particular star count "* "
			for(int star=1; star <= 2*i-1; star++){
				System.out.print("* ");
			}
			System.out.println();
		}

```

### Pattern 9: Inverted Pyramid

```plaintext
* * * * * * * * * 
  * * * * * * * 
    * * * * * 
      * * * 
        * 
```

```java
		int rows =5;
		for(int i=rows; i>=1; i--){
			for(int space=0; space<rows-i; space++){
				System.out.print("  ");
			}
			for(int star=1; star <= (2*i-1); star++){
				System.out.print("* ");
			}
			System.out.println();
		}

```

### Pattern 10: Diamond
![[Pasted image 20250401201709.png]]
```plaintext
        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 
  * * * * * * *   
    * * * * *     
      * * *       
        *         
```

```java


public class Diamond{
    public static void main(String[] args) {
        
    //PYRAMID
		int rows = 9;
		for(int i=1; i<= (rows+1)/2; i++){ //handles rows and moving to next line
			//space handles particular space count "  "
			for(int space = 1; space <= rows-i; space++){
				System.out.print("  ");
			}
			//star handles particular star count "* "
			for(int star=1; star <= 2*i-1; star++){
				System.out.print("* ");
			}
			System.out.println();
		}
//inverted pyramid
        for(int i=rows/2; i>=1; i--){
            for(int space=0; space<rows-i; space++){
                System.out.print("  ");
            }
            for(int star=1; star <= (2*i-1); star++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}

// or you can also do this: ( not prefered tho)
// first outer loop for above pattern. gives a pyramid
		for(int i=5; i>=1; i--){
		//first inner loop for left pattern
			for(int j=1; j<=5;j++){
				if(i>j){
					System.out.print("  ");
				}
				else{
					System.out.print("* ");
				}
			}
		//second inner loop for right pattern
			for(int k=1; k<=4; k++){
				if(k+i >= 6){
					System.out.print("  ");
				}
				else{
					System.out.print("* ");
				}
			}
			System.out.println();
		}

//second outer loop for below pattern
		for(int i=1; i<=4; i++){ 
		//inner loop for left pattern
			for(int j=1; j<=5; j++){
				if(i<j){
					System.out.print("* ");
				}
				else{
					System.out.print("  ");
				}
			}

		// outer loop for right pattern

			for(int k=1; k<=4; k++){
				if(i+k <= 4){
					System.out.print("* ");
				}
				else{
					System.out.print("  ");
				}
			}
			System.out.println();
		}
```

#### NOTE:
- If a row contains the same repeated value → Outer loop handles printing, Inner loop handles repetition.
    
- If values change within a row → Inner loop must also control printing.
---
## Hollow Patterns
### Pattern 1: Hollow right angled triangle
```plaintext
*
* * 
*   * 
*     * 
*       * 
*         * 
* * * * * * * 
```

```java
    int rows =8;
    for(int i=1; i<=rows; i++){
            for(int j=1; j<=i; j++){
                if( j==1 || j==i || i==rows){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }
}
```

### Pattern 2: Hollow right angled inverted triangle
- just like right angled triangle but reverse looping for both i and j
```plaintext
* * * * * * 
*       * 
*     * 
*   * 
* * 
*
```

```java
        for(int i=rows; i>=1; i--){
            for(int j=i; j>=1; j--){
                if( j==1 || i==j || i==rows){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

```

### Pattern 3:  Hollow Right aligned triangle
```plaintext
          * 
        * * 
      *   * 
    *     * 
  *       * 
* * * * * * 
```

```java
for(int i=1; i<=rows; i++){
    for(int j=rows; j>=1; j--){
        if( j==1 || i==j || i==rows){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}

```

### Pattern 4: Hollow inverted right aligned triangle

```plaintext

* * * * * * 
  *       * 
    *     * 
      *   * 
        * * 
          * 
```

```java
for(int i=rows; i>=1; i--){
    for(int j=rows; j>=1; j--){
        if( j==1 || i==j || i==rows){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}

```

### Pattern 5: Hollow pyramid
```plaintext
        *         
      *   *       
    *       *     
  *           *   
* * * * * * * * * 
```

```java
int rows=5;
for(int i=rows; i>=1; i--){
    for(int j=1; j <= rows*2-1; j++){
        if(i==j || i==1|| i+j == 2*rows){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}
```

### Program 6: Hollow inverted pyramid
```plaintext
* * * * * * * * * 
  *           *   
    *       *     
      *   *       
        *      
```

```java
for(int i=1; i<=rows; i++){
    for(int j=rows*2-1; j >= 1; j--){
        if(i==j || i==1|| i+j == 2*rows){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}
```

### Program 9: Hollow Diamond
```plaintext
      *       
    *   *     
  *       *   
*           * 
  *       *               
    *   *                 
      *        
```

```java
int rows=7;
for(int i=rows/2+1; i>=1; i--){
    for(int j=1; j <= rows; j++){
        if(i==j || i+j == rows+1){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}
    //Hollow inverted pyramid
for(int i=2; i<=rows/2+1; i++){
    for(int j=1; j <= rows*2-1; j++){
        if(i==j || i+j == 2*(rows/2)+2){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}
```

### Program 10: Cross
```plaintext
*           * 
  *       *   
    *   *     
      *       
    *   *     
  *       *   
*           * 
```

```java
        int rows = 7;
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=rows; j++){
                if(i==j || i+j == rows+1){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

```

### Pattern 12: Plus sign
```plaintext
      *       
      *       
      *       
* * * * * * * 
      *       
      *       
      *       
```

```java
for(int i=1; i<=rows; i++){
    for(int j=1; j<=rows; j++){
        if(i==rows/2+1 || j==rows/2+1){
            System.out.print("* ");
        }
        else{
            System.out.print("  ");
        }
    }
    System.out.println();
}
```