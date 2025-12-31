# 🤔 Am I the only one who solved **Latest Day to Cross** using Union-Find this way? 😌✨

---

## 🧠 Problem Name  
**Latest Day to Cross**

---

## 🎯 Intuition — what you want to do  
> You are given a grid of size `rows × cols`.  
>  
> Each day, one cell becomes **land** (initially everything is water).  
>  
> You want to know the **latest day** such that there exists **a connected path of land from the left border to the right border**.  
>
> Connectivity is allowed in **8 directions** (horizontal, vertical, diagonal).

So the real question becomes:
> 👉 **On which day do the left and right borders become connected for the first time?**

Once they connect, crossing is possible — and that day is the answer.

---

## 🎯 What you want to do (high-level goal / why)  
> - Turn cells into land **day by day**.
> - Dynamically maintain connectivity between land cells.
> - As soon as **any land path connects the leftmost column to the rightmost column**, stop.
> - Return that day.

Why Union-Find?
> Because we need to **frequently merge components and check connectivity efficiently**.

---

## 🧠 Why this works  
> - Each land cell becomes a node in a graph.
> - Adjacent land cells (8 directions) are connected using Union-Find.
> - Two special nodes represent:
>   - `leftNode` → all land in column `0`
>   - `rightNode` → all land in column `cols-1`
> - The moment `leftNode` and `rightNode` belong to the same component, a crossing path exists.

Union-Find gives:
> - **Almost O(1)** merge  
> - **Almost O(1)** connectivity check  

Perfect for this incremental process.

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Represent each cell as a node  
> Cell `(r, c)` is mapped to a unique id:
id = r * cols + c + 1

yaml
Copy code

Two extra nodes:
- `0` → left border  
- `rows*cols + 1` → right border  

---

### 2️⃣ Process days one by one  
For each day:
- Convert the given cell to **land**
- Connect it to all neighboring land cells (8 directions)

---

### 3️⃣ Connect borders  
> - If the cell is in column `0`, connect it to `leftNode`
> - If the cell is in column `cols-1`, connect it to `rightNode`

---

### 4️⃣ Check connectivity  
> After each day:
if find(leftNode) == find(rightNode)
return current day

yaml
Copy code

That day is the **latest day to cross**.

---

## 🔍 What each part contributes

### `land[][]`
> Tracks which cells are land so we only connect valid neighbors.

---

### `directions`
> Allows **8-directional connectivity**:
- left, right, up, down
- 4 diagonals

---

### `UnionFind`
> Efficiently manages connected components:
- `find(x)` → finds component root
- `connect(a, b)` → merges components with union-by-size

---

### `leftNode` & `rightNode`
> Virtual nodes that simplify checking whether a full left-to-right path exists.

---

## 🧪 Dry Run (conceptual)

Example:
rows = 2, cols = 3
cells = [(1,2), (2,2), (1,1), (2,1), ...]

pgsql
Copy code

- Day 0: land at (1,2)
- Day 1: land at (2,2) → connected vertically
- Day 2: land at (1,1) → connects toward left
- Day 3: land at (2,1) → left and right borders now connected

➡️ Answer = **3**

---

## 📊 Complexity

> - **Time Complexity:** `O(rows * cols * α(n))`  
>   (`α` = inverse Ackermann, practically constant)
>
> - **Space Complexity:** `O(rows * cols)`  
>   (Union-Find + grid)

---

## 💻 Code

```java
class Solution {

    public int latestDayToCross(int rows, int cols, int[][] cells) {

        UnionFind uf = new UnionFind(rows * cols + 2);
        int[][] land = new int[rows][cols];

        // 8-direction connectivity
        int[][] directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        int leftNode = 0;
        int rightNode = rows * cols + 1;

        for (int day = 0; day < rows * cols; day++) {

            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            land[r][c] = 1;

            int id = r * cols + c + 1;

            // connect with neighboring land cells
            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && land[nr][nc] == 1) {
                    uf.connect(id, nr * cols + nc + 1);
                }
            }

            // connect borders
            if (c == 0) uf.connect(leftNode, id);
            if (c == cols - 1) uf.connect(rightNode, id);

            // check if left and right borders are connected
            if (uf.find(leftNode) == uf.find(rightNode)) {
                return day;
            }
        }

        return -1;
    }
}

/* ---------- Union Find ---------- */
class UnionFind {

    private int[] parent;
    private int[] weight;

    public UnionFind(int n) {
        parent = new int[n];
        weight = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            weight[i] = 1;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void connect(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (weight[pa] > weight[pb]) {
            int temp = pa;
            pa = pb;
            pb = temp;
        }

        parent[pa] = pb;
        weight[pb] += weight[pa];
    }
}
