# INODE

```bash
$stat
```

stat - Display file or file system status.ststat is a userspace command .It uses the stat() system call internally.at is system call which is independent from programming

```bash
$ stat file.txt
  File: file.txt
  size: 1038            Blocks: 8          IO Block: 4096   regular file
Device: 10305h/66309d   Inode: 10880003    Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/prahadeesh)   Gid: ( 1000/prahadeesh)
Access: 2025-12-03 12:11:53.929836615 +0530
Modify: 2025-12-03 12:11:53.920744029 +0530
Change: 2025-12-03 12:11:53.920744029 +0530
Birth: 2025-12-03 12:10:00.421688281 +0530
```

| Field                   | Meaning                                               |
| ----------------------- | ----------------------------------------------------- |
| **Size**                | Actual size of the file in bytes                      |
| **Blocks**              | Number of disk blocks allocated                       |
| **IO Block**            | Filesystem block size for I/O                         |
| **Inode**               | Unique inode number for this file                     |
| **Links**               | Hard link count                                       |
| **Access**              | File permissions                                      |
| **Modify Time (mtime)** | When contents last changed                            |
| **Access Time (atime)** | When file was last read                               |
| **Change Time (ctime)** | When metadata last changed (permissions, owner, etc.) |
| **Birth Time**          | When the file was created (not available on all FS)   |

>**Important Note: The file is not part of the meta data or inode.** 

## stat()  
```bash
$ man 2 stat
```

#include <sys/stat.h>

int stat(const char *restrict pathname, struct stat *restrict statbuf);

int fstat(int fd, struct stat *statbuf);

int lstat(const char *restrict pathname, struct stat *restrict statbuf);


### DESCRIPTION
       These functions return information about a file, in the buffer pointed to by statbuf.  No permissions are required on the file itself, but—in the case of stat(),
       fstatat(), and lstat()—execute (search) permission is required on all of the directories in pathname that lead to the file.

## About Time in inode

| Field                   | Meaning                                                                                      |
| ----------------------- | -------------------------------------------------------------------------------------------- |
| **Access Time (atime)** | When the file was last **opened or read**.                                                   |
| **Modify Time (mtime)** | When the file's **content** was last **changed**.                                            |
| **Change Time (ctime)** | When the file's **metadata** was changed (permissions, owner, name, etc.) — not the content. |

**In one line:**

* **atime** = read time
* **mtime** = content changed
* **ctime** = metadata changed


## **Difference Hard Link and Soft Link (Symbolic Link)** in Linux/Unix:


### **HARD LINK**

| Feature                  | Description                                                                                       |
| ------------------------ | ------------------------------------------------------------------------------------------------- |
| Definition               | A hard link is **another file name** for the same inode (same physical data on disk).             |
| Points to                | **Inode** of the original file.                                                                   |
| File deletion impact     | Even if the original file is deleted, the data **still exists** as long as one hard link remains. |
| Cross filesystem support | **Cannot** span across different file systems or partitions.                                      |
| Linking directories      | **Not allowed** (to avoid loops).                                                                 |
| Inode number             | **Same inode number** as the original file.                                                       |
| Size                     | Appears same as the file.                                                                         |
| Use case                 | When you want multiple file names to point to the **same content safely**.                        |

Example:

```bash
ln file1 file2
```

---

### **SOFT LINK (SYMBOLIC LINK)**

| Feature                  | Description                                                            |
| ------------------------ | ---------------------------------------------------------------------- |
| Definition               | A soft link is a **shortcut** or a pointer to another file’s **path**. |
| Points to                | **Path name** of the target file. Not the inode directly.              |
| File deletion impact     | If original file is deleted, soft link becomes a **broken link**.      |
| Cross filesystem support | **Can** span across different file systems.                            |
| Linking directories      | **Allowed**.                                                           |
| Inode number             | **Different inode** from the target file.                              |
| Size                     | Size contains length of the path stored.                               |
| Use case                 | Useful for creating shortcuts and navigating easily.                   |

Example:

```bash
ln -s file1 link1
```

---

### **Quick Summary**

| Hard Link                   | Soft Link                 |
| --------------------------- | ------------------------- |
| Same inode                  | Different inode           |
| Points to data              | Points to filename        |
| Survives deletion of target | Broken if target removed  |
| Same filesystem only        | Cross filesystem possible |
| Cannot link directories     | Can link directories      |

---

Interview-Ready 3-Line Answer

1. A hard link creates another name for the same file by pointing to the same inode, so even if the original file is deleted, the data remains accessible.

2. A soft link (symbolic link) acts like a shortcut that stores the path of the original file, so if the target file is removed, the link breaks.

Hard links cannot span filesystems or link directories, while soft links can.
