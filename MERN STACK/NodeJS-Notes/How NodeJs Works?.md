![[Screenshot 2025-02-28 at 2.10.20 PM.png]]

### If nodejs does not support multiple threads then how are we able to get multiple workers?
By using `libuv`

libuv is a **C library** that powers Node.js by **handling asynchronous I/O operations.** It provides the **event loop, thread pool, and cross-platform support**, making Node.js fast and efficient.

#### Why is libuv important?
Since JavaScript is single-threaded, Node.js uses libuv to **handle non-blocking I/O operations** efficiently. It offloads blocking tasks to background threads when necessary.


#### libuv manages:

**The Event Loop** – Handles asynchronous operations.
**Thread Pool** – Runs CPU-intensive tasks in separate threads.
**Asynchronous I/O** – Handles network requests, file system operations, and timers.
**Cross-Platform Support** – Works on Linux, Windows, macOS, etc.
