| Signal              | Number | Default Action | Description                                                             |
| ------------------- | -------- | -------------- | ----------------------------------------------------------------------- |
| `SIGHUP`            | 1      | Terminate      | Hangup detected on controlling terminal or death of controlling process |
| `SIGINT`            | 2      | Terminate      | Interrupt from keyboard (Ctrl+C)                                        |
| `SIGQUIT`           | 3      | Core dump      | Quit from keyboard (Ctrl+\)                                             |
| `SIGILL`            | 4      | Core dump      | Illegal Instruction                                                     |
| `SIGTRAP`           | 5      | Core dump      | Trace/breakpoint trap                                                   |
| `SIGABRT`           | 6      | Core dump      | Abort signal from `abort(3)`                                            |
| `SIGBUS`            | 7      | Core dump      | Bus error (bad memory access)                                           |
| `SIGFPE`            | 8      | Core dump      | Floating-point exception                                                |
| `SIGKILL`           | 9      | Terminate      | Kill signal (cannot be caught or ignored)                               |
| `SIGUSR1`           | 10     | Terminate      | User-defined signal 1                                                   |
| `SIGSEGV`           | 11     | Core dump      | Invalid memory reference (segmentation fault)                           |
| `SIGUSR2`           | 12     | Terminate      | User-defined signal 2                                                   |
| `SIGPIPE`           | 13     | Terminate      | Broken pipe: write to pipe with no readers                              |
| `SIGALRM`           | 14     | Terminate      | Timer signal from `alarm(2)`                                            |
| `SIGTERM`           | 15     | Terminate      | Termination signal (default for `kill`)                                 |
| `SIGSTKFLT`         | 16     | Terminate      | Stack fault (Linux-specific, unused on many systems)                    |
| `SIGCHLD`           | 17     | Ignore         | Child stopped or terminated                                             |
| `SIGCONT`           | 18     | Continue       | Continue if stopped                                                     |
| `SIGSTOP`           | 19     | Stop           | Stop process (cannot be caught or ignored)                              |
| `SIGTSTP`           | 20     | Stop           | Stop typed at terminal (Ctrl+Z)                                         |
| `SIGTTIN`           | 21     | Stop           | Terminal input for background process                                   |
| `SIGTTOU`           | 22     | Stop           | Terminal output for background process                                  |
| `SIGURG`            | 23     | Ignore         | Urgent condition on socket (POSIX)                                      |
| `SIGXCPU`           | 24     | Core dump      | CPU time limit exceeded (see `setrlimit`)                               |
| `SIGXFSZ`           | 25     | Core dump      | File size limit exceeded                                                |
| `SIGVTALRM`         | 26     | Terminate      | Virtual alarm clock                                                     |
| `SIGPROF`           | 27     | Terminate      | Profiling timer expired                                                 |
| `SIGWINCH`          | 28     | Ignore         | Window resize signal                                                    |
| `SIGIO` / `SIGPOLL` | 29     | Terminate      | I/O now possible (pollable event)                                       |
| `SIGPWR`            | 30     | Terminate      | Power failure (system-specific)                                         |
| `SIGSYS`            | 31     | Core dump      | Bad system call (invalid syscall)                                       |
