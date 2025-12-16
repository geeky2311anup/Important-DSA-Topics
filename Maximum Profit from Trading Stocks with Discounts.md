# 🤯 Is it just me, or does this tree + DP problem look scary until you break it down?

---

## 🎯 Intuition — what you want to do  
> You are given a **hierarchy (tree)** of `n` nodes.  
>  
> Each node represents a project/item:
> - `present[i]` → cost you pay now  
> - `future[i]` → value you gain later  
>  
> You have a **total budget limit**, and for **each node** you can choose:
> - ❌ **No discount** → pay full cost  
> - ✅ **Discount** → pay half the cost  
>
> ⚠️ **Important constraint:**  
> If you take a node (discounted or not), **you must also take all its children** in some form.  
>
> The goal is to **maximize total profit** under the budget.

This screams:  
👉 **Tree DP + Knapsack merging**

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the tree bottom-up (DFS).  
> - At every node, compute:
>   - Best profit **if this node is NOT discounted**
>   - Best profit **if this node IS discounted**
> - For each node, merge children results using **knapsack-style DP**.
> - Finally, check the root’s DP and pick the best profit within the budget.

Why DP on tree?  
Because each node’s decision **depends on all its children**, and children subtrees are independent of each other.

---

## 🧠 Why this works  
> - Each subtree is independent once you decide how much budget it consumes.  
> - For every node, children contribute profit and consume budget → classic knapsack merge.  
> - Since the tree is rooted, DFS ensures children are solved before the parent.  
> - The discount choice only affects **this node’s cost**, not the children’s structure.  

This guarantees:
- No overlapping subproblems
- Every valid selection is considered
- Optimal profit is captured

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Build the tree  
> Convert the `hierarchy` array into an adjacency list.  
> Parent → children structure is explicitly built.

---

### 2️⃣ DP definition (core idea)  
For every node `u`, `solveNode(u)` returns **two DP arrays**:

- `dp[0][b]` → max profit using budget `b` **if node u is NOT discounted**
- `dp[1][b]` → max profit using budget `b` **if node u IS discounted**

Each DP array has size `budget + 1`.

---

### 3️⃣ Merging children (knapsack merge)  
> Each child contributes its own DP array.  
>  
> To combine multiple children:
> - Use a **2D knapsack merge**
> - For every `(i + j ≤ budget)`:
>   ```
>   res[i + j] = max(res[i + j], a[i] + b[j])
>   ```

This is exactly what `mergeDP()` does.

---

### 4️⃣ Processing a node itself  
For node `u`:

- **Normal cost**
costNormal = present[u-1]
profitNormal = future[u-1] - costNormal

markdown
Copy code

- **Discounted cost**
costHalf = costNormal / 2
profitHalf = future[u-1] - costHalf

yaml
Copy code

Now:
- Start with children merged without forcing discount
- If budget allows:
- Add `profitNormal` when node is **not discounted**
- Add `profitHalf` when node **is discounted**

Children must already be included → that’s why child DP is used first.

---

## 🔍 What each part contributes (important!)

### `mergeDP(a, b)`
> Combines two independent subtrees by budget, ensuring:
> - All combinations are explored
> - Best profit is kept for each budget

---

### `solveNode(u)`
> Returns:
> - `noDiscount[b]` → best profit if `u` not discounted
> - `withDiscount[b]` → best profit if `u` discounted
>
> It:
> - Solves all children first
> - Merges their DP
> - Then applies the cost/profit of `u`

---

### Root handling
> The root **cannot be forced discounted**, so we only consider:
rootDP[0][b]

yaml
Copy code
and take the maximum over all `b ≤ budget`.

---

## 🧪 Dry Run (conceptual)

Suppose:
budget = 10
node cost = 6
discounted cost = 3
children already consume budget 4 with profit 8

cpp
Copy code

- Without discount:
  - total cost = 4 + 6 = 10
  - profit = 8 + (future - 6)

- With discount:
  - total cost = 4 + 3 = 7
  - profit = 8 + (future - 3)

Both are evaluated, DP keeps the better one per budget.

---

## 📊 Complexity

> - **Time Complexity:**  
>   `O(n * budget²)` in worst case (knapsack merging per node)
>
> - **Space Complexity:**  
>   `O(n * budget)` for DP arrays

---

## 💻 Code

```java
class Solution {

    private List<Integer>[] tree;
    private int[] baseCost, gain;
    private int limit;

    // build tree structure
    private void buildTree(int n, int[][] edges) {
        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();

        for (int[] e : edges) {
            tree[e[0]].add(e[1]);
        }
    }

    // knapsack merge
    private int[] mergeDP(int[] a, int[] b) {
        int[] res = new int[limit + 1];
        for (int i = 0; i <= limit; i++) {
            for (int j = 0; i + j <= limit; j++) {
                res[i + j] = Math.max(res[i + j], a[i] + b[j]);
            }
        }
        return res;
    }

    // DFS returns:
    // [0] → dp when this node is NOT discounted
    // [1] → dp when this node IS discounted
    private int[][] solveNode(int u) {
        int costNormal = baseCost[u - 1];
        int profitNormal = gain[u - 1] - costNormal;

        int costHalf = costNormal / 2;
        int profitHalf = gain[u - 1] - costHalf;

        int[] dpChildNo = new int[limit + 1];
        int[] dpChildYes = new int[limit + 1];

        for (int v : tree[u]) {
            int[][] childDP = solveNode(v);
            dpChildNo = mergeDP(dpChildNo, childDP[0]);
            dpChildYes = mergeDP(dpChildYes, childDP[1]);
        }

        int[] noDiscount = Arrays.copyOf(dpChildNo, limit + 1);
        int[] withDiscount = Arrays.copyOf(dpChildNo, limit + 1);

        for (int b = costNormal; b <= limit; b++) {
            noDiscount[b] = Math.max(
                noDiscount[b],
                dpChildYes[b - costNormal] + profitNormal
            );
        }

        for (int b = costHalf; b <= limit; b++) {
            withDiscount[b] = Math.max(
                withDiscount[b],
                dpChildYes[b - costHalf] + profitHalf
            );
        }

        return new int[][]{noDiscount, withDiscount};
    }

    public int maxProfit(int n, int[] present, int[] future, int[][] hierarchy, int budget) {
        this.baseCost = present;
        this.gain = future;
        this.limit = budget;

        buildTree(n, hierarchy);

        int[][] rootDP = solveNode(1);

        int best = 0;
        for (int b = 0; b <= budget; b++) {
            best = Math.max(best, rootDP[0][b]);
        }
        return best;
    }
}
