## `pipe()` vs `pipe2()`

`pipe()` creates a read end and a write end with the default settings (blocking, inherited across `exec`). If the program later needs flags like `O_NONBLOCK` or `O_CLOEXEC`, it must change them with extra `fcntl()` calls.

`pipe2(flags)` creates the same two ends but lets you apply selected flags right in that call, so there is no window where other threads could see the unconfigured descriptors.

```c
int fds[2];

// Using pipe(): defaults first, fix later
pipe(fds);
fcntl(fds[0], F_SETFL, O_NONBLOCK);
fcntl(fds[0], F_SETFD, FD_CLOEXEC);
fcntl(fds[1], F_SETFL, O_NONBLOCK);
fcntl(fds[1], F_SETFD, FD_CLOEXEC);

// Using pipe2(): same result in one step
pipe2(fds, O_NONBLOCK | O_CLOEXEC);
```

Use `pipe2()` when the flags are known upfront or when you want to avoid the race window that exists between the `pipe()` call and the follow-up `fcntl()` adjustments.
