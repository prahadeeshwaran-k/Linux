# 🧩 How `pause()` Works in Linux

## Overview

The **`pause()`** function in Linux suspends the calling process until a
signal is delivered that either terminates the process or invokes a
signal handler.

------------------------------------------------------------------------

## Function Prototype

``` c
#include <unistd.h>

int pause(void);
```

------------------------------------------------------------------------

## Description

-   When a process calls `pause()`, it enters a **blocked (sleeping)**
    state.
-   It remains in that state until a **signal** is received.
-   Once a signal is caught, the process wakes up:
    -   If a **signal handler** is defined, it executes the handler.
    -   After returning from the handler, `pause()` **returns -1** and
        sets `errno` to `EINTR`.

------------------------------------------------------------------------

## Example Code

``` c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nCaught signal %d (SIGINT)\n", sig);
}

int main() {
    signal(SIGINT, handle_sigint); // Register handler for Ctrl + C

    printf("Process PID: %d\n", getpid());
    printf("Waiting for signal...\n");

    pause();  // Wait indefinitely for any signal

    printf("pause() returned, continuing execution...\n");
    return 0;
}
```

### Example Output

    Process PID: 12345
    Waiting for signal...
    ^C
    Caught signal 2 (SIGINT)
    pause() returned, continuing execution...

------------------------------------------------------------------------

## Internal Working (Step-by-Step)

1.  The process executes `pause()`.
2.  The kernel marks it as **TASK_INTERRUPTIBLE** (sleeping state).
3.  The scheduler removes it from the run queue (no CPU usage).
4.  When a signal is sent (e.g., `Ctrl+C` or `kill`), the kernel wakes
    it.
5.  If a signal handler exists, it runs first.
6.  After handler execution, `pause()` returns with `errno = EINTR`.

------------------------------------------------------------------------

## Key Points

  Concept            Description
  ------------------ -------------------------------------------------------
  **Return Value**   Always `-1`
  **errno**          Set to `EINTR` after signal interruption
  **Timeout**        Not supported (unlike `sleep()`)
  **Use Case**       Waiting for signals in daemons or background services

------------------------------------------------------------------------

## Summary

-   `pause()` is a **signal-driven blocking function**.
-   It's commonly used in processes that remain idle until a signal
    arrives.
-   Perfect for event-driven or signal-handling based programs.

------------------------------------------------------------------------
