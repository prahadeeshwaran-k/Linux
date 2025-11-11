/*
| Feature                          | Pipe (unnamed) | FIFO (named)           |
| -------------------------------- | -------------- | ---------------------- |
| Created using                    | `pipe()`       | `mkfifo()` + `open()`  |
| Blocking during creation         | ❌ No          | ✅ Yes, `open()` blocks|
| Requires both sides?             | No             | Yes: reader & writer   |
| Used between unrelated processes | No             | Yes                    |
*/

/*
FIFO is also called a Named Pipe.
It appears as a file in the filesystem (ex: /tmp/f1).
FIFO follows First In, First Out order — the data written first is read first.
Works between unrelated processes, unlike unnamed pipes.
Uses open(), read(), write(), close() system calls.
Created using mkfifo() or the command mkfifo.
Removing is done using rm (because it is a file).
*/
