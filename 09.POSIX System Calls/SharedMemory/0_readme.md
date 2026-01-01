
## Minimal Required Compile Commands
You can safely compile with just:

```bash
gcc server.c -o server -lrt
gcc client.c -o client -lrt
````

### Or (works on modern Linux)

```bash
gcc server.c -o server
gcc client.c -o client
```

---

## If You See Runtime Errors

### Permission Denied

Check shared memory filesystem:

```bash
ls /dev/shm
```

---

### Semaphore Already Exists

POSIX IPC objects persist even after program exit.
Manually remove old objects:

```bash
rm /dev/shm/sem.simplex_sem
rm /dev/shm/simplex_shm
```

Or clean programmatically using:

```c
sem_unlink("/simplex_sem");
shm_unlink("/simplex_shm");
```

---

## Important Note

* Always start the **server first**
* Then start the **client**

```

