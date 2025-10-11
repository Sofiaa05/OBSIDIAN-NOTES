### Prime or not
```java
public class CheckPrime {
    public static void main(String[] args) {
        int num = 20;
        boolean flag = true;

        if (num <= 1) {
            flag = false;
        } else if (num == 2) {
            flag = true;
        } else if (num % 2 == 0) {
            flag = false;
        } else {
            for (int i = 3; i <= Math.sqrt(num); i += 2) {
                if (num % i == 0) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            System.out.println("yes prime");
        } else {
            System.out.println("not a prime");
        }
    }
}

```

### Circular prime or not (1 to 100 only)
```java
public class CircularPrime {
	private static int countDigits(int num) {
		int count = 0;
		while (num > 0) {
			num /= 10;
			count++;
		}
		return count;
	}

	private static boolean checkPrime(int num) {
		if (num <= 1) return false;
		if (num == 2) return true;
		if (num % 2 == 0) return false;

		for (int i = 3; i * i <= num; i += 2) {
			if (num % i == 0)
				return false;
		}
		return true;
	}

	private static int reverse(int num) {
		int r;
		StringBuilder sb = new StringBuilder();
		int n = num;

		while (n > 0) {
			r = n % 10;
			n = n / 10;
			sb.append(r);
		}

		return Integer.parseInt(sb.toString());  // ✅ Fix here
	}

	private static int circularPrime(int[] arr) {
		int count = 0;
		for (int num : arr) {
			if (countDigits(num) == 1) {
				if (checkPrime(num))
					count++;
			} else if (countDigits(num) == 2) {
				int rev = reverse(num);
				if (checkPrime(num) && checkPrime(rev))
					count++;
			}
		}
		return count;
	}

	public static void main(String[] args) {
		int arr[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79};
		System.out.println(circularPrime(arr));  // Should print the count of circular primes
	}
}
```

#### Above question for larget inputs (1 <= num <= 100000)
```java
public class CircularPrime2{
	private static boolean checkPrime(int num){
		if (num <= 1) return false;
		else if (num == 2) return true;
		else if (num % 2 == 0) return false;

		for (int i = 3; i * i <= num; i += 2){
			if (num % i == 0) return false;
		}
		return true;
	}

	private static boolean isCircularPrime(int num){
	
		if (num <= 1) return false;
		if (num == 2) return true;

		//counting digits
		int temp = num;
		int d = 0;

		while (temp > 0){
			if (temp % 2 == 0) return false;
			temp /= 10;
			d++;
		}

		int q = (int) Math.pow(10, d - 1);

		//maximum rotations = number of digits
		for (int i = 0; i < d; i++){
			if (!checkPrime(num)) return false;

			int rem = num % 10;
			num /= 10;
			num = (q * rem) + num;
		}

		return true;
	}

	public static void main(String[] args) {
		int arr[] = {113, 1193, 2, 6};
		int count = 0;

		for (int num : arr) {
		    if (isCircularPrime(num)) {
		        count++;
		    }
		}

		System.out.println("Total circular primes: " + count);
	}
}
```