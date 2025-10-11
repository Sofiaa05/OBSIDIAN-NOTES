- Buffer: memory object used for holding data temporarily to bring compatibility between sending and receiving devices (you tube video buffering)
In Java, streams are the sequence of data that are read from the source and written to the destination.

- An **input stream** is used to read data from the source. And, an **output stream** is used to write data to the destination.

## 1. Java InputStream Class
- The `InputStream` class of the `java.io` package is an abstract superclass that represents an input stream of bytes.
- Since `InputStream` is an abstract class, it is not useful by itself. However, its subclasses can be used to read data
##### Commonly used methods:
- `read()` - reads one byte of data from the input stream
- `read(byte[] array)` - reads bytes from the stream and stores in the specified [array](https://www.programiz.com/java-programming/arrays "array")
- `available()` - returns the number of bytes available in the input stream
- `mark()` - marks the position in the input stream up to which data has been read
- `reset()` - returns the control to the point in the stream where the mark was set
- `markSupported()` - checks if the `mark()` and `reset()` method is supported in the stream
- `skips()` - skips and discards the specified number of bytes from the input stream
- `close()` - closes the input stream
### Subclasses of InputStream:
- FileInputStream [[FileInputStreams FileOutputStreams]]
- ByteArrayInputStream
- ObjectInputStream

---
## 2. Java OutputStream Class

- The `OutputStream` class of the `java.io` package is an abstract superclass that represents an output stream of bytes.

### Subclasses of InputStream:
- FileOutputStream [[FileInputStreams FileOutputStreams]]. 
- ByteArrayOutputStream
- ObjectOutputStream

### Types of Streams

#### 1. Byte Stream: 
  - Byte stream is used to read and write a single byte (8 bits) of data.
- All byte stream classes are derived from base abstract classes called `InputStream` and `OutputStream`

--- 
