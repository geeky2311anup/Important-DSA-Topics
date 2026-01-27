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

        // Union-Find with extra 2 nodes for left and right virtual borders
        UnionFind uf = new UnionFind(rows * cols + 2);

        // Grid to mark land (1 = land, 0 = water)
        int[][] land = new int[rows][cols];

        // All 8 possible directions (including diagonals)
        int[][] directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        // Virtual nodes representing left and right borders
        int leftNode = 0;
        int rightNode = rows * cols + 1;

        // Process cells day by day
        for (int day = 0; day < rows * cols; day++) {

            // Convert to 0-based index
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;

            // Mark current cell as land
            land[r][c] = 1;

            // Unique ID for this cell in Union-Find
            int id = r * cols + c + 1;

            // Connect current land cell with all neighboring land cells
            for (int[] dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check bounds and if neighbor is land
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && land[nr][nc] == 1) {
                    uf.connect(id, nr * cols + nc + 1);
                }
            }

            // If cell is on left border, connect to left virtual node
            if (c == 0) uf.connect(leftNode, id);

            // If cell is on right border, connect to right virtual node
            if (c == cols - 1) uf.connect(rightNode, id);

            // If left and right borders are connected, crossing is blocked
            if (uf.find(leftNode) == uf.find(rightNode)) {
                return day;
            }
        }

        // If never connected (shouldn't really happen)
        return -1;
    }
}

/* ---------- Union Find (Disjoint Set) ---------- */
class UnionFind {

    // parent[i] stores parent of node i
    private int[] parent;

    // weight[i] stores size of the tree rooted at i
    private int[] weight;

    public UnionFind(int n) {
        parent = new int[n];
        weight = new int[n];

        // Initially, each node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            weight[i] = 1;
        }
    }

    // Find root of x with path compression
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union two nodes using union by size
    public void connect(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        // Already connected
        if (pa == pb) return;

        // Attach smaller tree to larger tree
        if (weight[pa] > weight[pb]) {
            int temp = pa;
            pa = pb;
            pb = temp;
        }

        parent[pa] = pb;
        weight[pb] += weight[pa];
    }
}
