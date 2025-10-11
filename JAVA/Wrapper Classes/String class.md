### String
- Immutable - cannot modify the same object
- if changes are made then another object is created with changes
- faster as it is immutable

### StringBuffer
- similar to String, all the methods of string plus other methods too
- mutable
- by default of capacity of 16 bytes
- if string exceeds given capacity then it will create another object with new capacity and new string
- Thread safe: more than two threads cannot use same stringBuffer object simultaneously. if they could do so then data loss will be there.
	- Two threads can hold the reference of same object
	- But at a time, two threads are not allowed inside method.
- slower as it is thread safe (synchronised)
- useful when want mutability and  multiple threads will be using it
### StringBuilder
- same as StringBuffer
- Not thread safe
- allows one or more thread to enter inside method or call method
- faster than StringBuffer
- useful when want mutable and one thread will be using it