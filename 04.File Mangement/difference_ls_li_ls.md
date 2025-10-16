# Difference between `ls -li` and `ls -ls`

Both commands show file details, but they emphasize **different aspects**:

---

## 🧩 `ls -li`

- **`-l`** → long listing format (permissions, owner, size, timestamp, name)  
- **`-i`** → displays the **inode number** of each file  

📘 **Purpose:**  
Used to identify files by their **inode number**, which is useful to check **hard links** (because hard-linked files share the same inode).

🔍 **Example Output:**
```
10902465 -rw-rw-r-- 1 prahadeesh prahadeesh 0 Oct 16 17:47 ChechFileisLinked.c
```
→ `10902465` is the inode number.

---

## ⚙️ `ls -ls`

- **`-l`** → long listing format  
- **`-s`** → shows the **file size in blocks** (usually 1 block = 1 KB or 4 KB depending on the filesystem)

📘 **Purpose:**  
Used to check **disk space usage** per file.

🔍 **Example Output:**
```
0 -rw-rw-r-- 1 prahadeesh prahadeesh 0 Oct 16 17:47 ChechFileisLinked.c
```
→ `0` is the number of **disk blocks** the file occupies (since the file is empty).

---

## 🧠 Summary Table

| Command | Shows | First Column | Use Case |
|----------|--------|--------------|-----------|
| `ls -li` | Inode + details | Inode number | Identify hard links |
| `ls -ls` | Disk usage + details | Block count | Check file space usage |

---

So in your case:
- `ls -li` → shows inode `10902465`
- `ls -ls` → shows block count `0`

👉 Both describe the same file but highlight **different filesystem attributes**.
