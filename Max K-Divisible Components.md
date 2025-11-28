# ✨ Max K-Divisible Components — Explanation & Code ✨

> **Tree problems with modulo sums look hard — but with DFS + smart reduction, it becomes beautifully simple!**

---

## 🎯 **Intuition**

> We are given a **tree** (connected, acyclic graph).  
> Each node has a value.  
> We want to count how many **components** (subtrees) have a **total sum divisible by k**.
>
> A powerful trick:  
> - When you do DFS on a tree, each subtree naturally forms a component.  
> - If the **sum of a subtree % k == 0**, then we can “cut” that subtree and count it as one valid component.

---

## 🎯 **What I want to do (high-level goal)**

> - Build the tree using adjacency lists.  
> - Run a DFS from root `0`.  
> - For each subtree, compute its **sum modulo k**.  
> - Whenever a subtree sum becomes divisible by k → count it as a component.  
> - Return total number of such divisible components.

---

## 🧠 **Why this works**

> - Since this is a **tree**, every child leads to exactly one parent — no cycles (except implicit back edge).  
> - DFS naturally accumulates child-subtree sums.  
> - Instead of storing large sums, we reduce with `% k` at each step to keep values small.  
> - If a subtree sum is divisible by `k`, we increment the component count.  
> - Returning `subtotal % k` ensures parent calculations remain correct.  
> - Each subtree is tested exactly once → linear time.

---

## 🔧 **Approach (step-by-step)**

> 1. Create adjacency list `graph[n]`.  
> 2. Build the tree from the `edges`.  
> 3. Use a global variable `components = 0`.  
> 4. DFS(node, parent):  
>    - Start `subtotal = 0`.  
>    - For each child:  
>      - Recursively compute child sum.  
>      - Add to subtotal (mod k).  
>    - After processing children, add the node’s own value.  
>    - If `subtotal % k == 0`:  
>      - This subtree forms a valid component → increment counter.  
>    - Return `subtotal % k` to parent.  
> 5. Final answer is `components`.

---

## 🔍 **Dry Run Example (conceptual)**

> Suppose k = 3  
>  
> Node 2 returns subtree sum = 3 → divisible → components++  
> Node 1 combines children → returns sum % 3  
> Root sees combined sum → maybe divisible → components++  
>
> Every subtree is processed once in DFS order.

---

## 📊 **Complexity**

> - **Time Complexity:** `O(n)` — DFS on tree  
> - **Space Complexity:** `O(n)` — adjacency list + recursion stack

---

## 💻 **Code**

```java
class Solution {
    private int components;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        // Build adjacency list using array of lists instead of Map
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].add(v);
            graph[v].add(u);
        }

        components = 0;
        dfs(0, -1, graph, values, k);
        return components;
    }

    private int dfs(int node, int parent, List<Integer>[] graph, int[] values, int k) {
        int subtotal = 0;

        for (int nxt : graph[node]) {
            if (nxt == parent) continue;
            int childSum = dfs(nxt, node, graph, values, k);
            subtotal += childSum;
            if (subtotal >= k) subtotal %= k;
        }

        subtotal += values[node];
        subtotal %= k;

        if (subtotal == 0) {
            components++;
        }

        return subtotal;
    }
}
