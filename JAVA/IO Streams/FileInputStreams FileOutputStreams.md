
### 1. Java FileInputStream Class
- The `FileInputStream` class of the `java.io` package can be used to read data (in bytes) from files.
- It extends the `InputStream` abstract class.
- Source of data is file.

##### Example 1: read()

```java
import java.io.InputStream;
import java.io.File;
import java.io.FileInputStream;

//To read data from the file, we have used the read() method inside the while loop.
public class Input{
    public static void main(String[] args) {
        try{
            FileInputStream input = new FileInputStream("./input.txt");

            System.out.println("Available bytes at beginning: " + input.available());

            //skip
            input.skip(5);
            System.out.println("Input stream after skipping 5 bytes:");
            int i = input.read();  //reads and remove from buffer as well

            while(i != -1){
                System.out.print((char)i);
                i = input.read();
            }
            System.out.println("Available bytes at end: " + input.available());
            input.close();
        }
        catch(Exception e){
            e.getMessage();
        }
    }
}
```

##### Example 2: read(byte[] b)

```java
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.File;

public class Input2 {
    public static void main(String[] args) {
        try{
            FileInputStream input = new FileInputStream("input.txt");
            byte[] array = new byte[input.available()]; //creating arry of size text file

            input.read(array);
            String str = new String(array);
            System.out.println(str);
        }catch (Exception e){
            e.getStackTrace();
        }
    }
}

```

### 2.  Java FileOutputStream Class

- The `FileOutputStream` class of the `java.io` package can be used to write data (in bytes) to the files.
- It extends the `OutputStream` abstract class.
- Destination of data is file.
##### Commonly used methods:
- `write()` - writes the specified byte to the output stream
- `write(byte[] array)` - writes the bytes from the specified [array](https://www.programiz.com/java-programming/arrays "array") to the output stream
- `flush()` - forces to write all data present in output stream to the destination
- `close()` - closes the output stream

```java
import java.io.FileOutputStream;

public class Output {
    public static void main(String[] args) {
        String data1 = "This is example of writing data to file entire byte array in one go";
        String data2 = "Appending data one byte at a time";
        try{
            FileOutputStream output = new FileOutputStream("./output.txt");
            
            //writing data entirely
            byte[] array = data1.getBytes(); //getBytes() returns a byte array
            output.write(array);

            //writing data one byte at a time
            byte[] array2 = data2.getBytes();
            for(byte x: array2){
                output.write(x);
            }

            output.close();
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }   
}

/* output.txt
This is example of writing data to file entire byte array in one goAppending data one byte at a time
*/
```

---
### Student challenge:
- copy contents of one file to another in lowercase.
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Challenge {
    public static void main(String[] args) {
        try{

//My solution
            // //first part 
            // FileInputStream input = new FileInputStream("./challengeInput.txt");
            // byte[] inputArr = new byte[input.available()];
            // input.read(inputArr);
            // String str = new String(inputArr);

            // //second part
            // FileOutputStream output = new FileOutputStream("./challengeOutput.txt");
            // byte[] outputArr = str.toLowerCase().getBytes();
            // output.write(outputArr);

//real solution
            FileInputStream input = new FileInputStream("./challengeInput.txt");
            FileOutputStream output = new FileOutputStream("./challengeOutput.txt");

            int b;
            while((b = input.read()) != -1){
                if(b >= 65 && b <= 90){
                    output.write(b + 32);
                }else{
                    output.write(b);
                }
            }
            input.close();
            output.close();
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
```