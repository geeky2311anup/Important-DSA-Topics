# 🤔 Am I the only one who solved **Pyramid Transition Matrix** with clean DFS + memoization? 😌✨

---

## 🧩 Problem Name  
**Pyramid Transition Matrix** (LeetCode)

---

## 🎯 Intuition — what you want to do  
> You are given:
> - A **bottom row** string (like `"ABC"`).
> - A list of **allowed rules** where each rule `"XY Z"` means:
>   > If two adjacent blocks are `X` and `Y`, you are allowed to place `Z` on top of them.
>
> Your goal:
> 👉 **Check whether it is possible to build the pyramid all the way up to a single block.**

At every level:
> - Adjacent characters decide what character can be placed above.
> - The next row is **one character shorter**.
> - You must try **all valid possibilities**.

This screams:
> 🔁 **Backtracking + DFS**  
> 🧠 **Memoization** to avoid recomputation.

---

## 🎯 What you want to do (high-level goal / why)  
> - Convert the rules into a fast lookup structure.
> - Recursively try to build the pyramid row by row.
> - If you reach a row of length `1`, success 🎉.
> - Use memoization to avoid recomputing the same rows again and again.

Why DFS?
> Because each adjacent pair can lead to **multiple choices**, forming a tree of possibilities.

---

## 🧠 Why this works  
> - Each row uniquely defines all future possibilities.
> - If a row has already been proven impossible, we never retry it.
> - Total states are small because:
>   - Row length shrinks every level.
>   - Characters are limited (`A` to `F`).

This makes DFS + memo **fast enough**.

---

## 🔧 Approach (matching the implementation)

### 1) Preprocess rules into a 2D table  
> `next[a][b]` = list of characters that can be placed above `(a, b)`.

Why?
> Instead of scanning `allowed` every time, we get **O(1)** transitions.

---

### 2) DFS on current row  
> - If row length is `1` → return `true`.
> - Convert row into a string key.
> - If already in `memo`, reuse the answer.

---

### 3) Build the next row recursively  
> - For every adjacent pair `(curr[i], curr[i+1])`:
>   - Try all valid characters from `next[a][b]`.
>   - Fill `upper[i]`.
> - Once upper row is fully built, recurse.

---

### 4) Memoize results  
> - Store whether a given row can lead to a valid pyramid.
> - Prevents exponential recomputation.

---

## 🔍 What each method contributes

### `pyramidTransition(...)`
> - Builds the rule lookup table.
> - Starts DFS from the bottom row.

---

### `dfs(row)`
> - Base case: row length = 1 → success.
> - Memo lookup.
> - Tries to build the next row.

---

### `buildNextRow(idx, curr, upper)`
> - Backtracking engine.
> - Fills the `upper` row character by character.
> - Once complete, calls `dfs` on the new row.

---

### `memo`
> - Key: current row as a string.
> - Value: whether it can lead to a valid pyramid.
> - Massive performance boost.

---

## 🧪 Dry Run (small example)

Bottom:
"ABC"

makefile
Copy code

Allowed:
AB -> D
BC -> E
DE -> F

arduino
Copy code

Steps:
- Row 1: `"ABC"`
- Row 2: `"DE"`
- Row 3: `"F"` ✅

Return `true`.

---

## 📊 Complexity

> - **Time Complexity:** Exponential in worst case, but **pruned heavily** by memoization  
> - **Space Complexity:** `O(number of unique rows)` for memo  

Given constraints, this easily passes.

---

## 💻 Code

```java
class Solution {

    public boolean pyramidTransition(String bottom, List<String> allowed) {

        // next[a][b] = list of characters that can be placed above (a,b)
        List<Character>[][] next = new ArrayList[6][6];
        Map<String, Boolean> memo = new HashMap<>();

        for (String rule : allowed) {
            int x = rule.charAt(0) - 'A';
            int y = rule.charAt(1) - 'A';
            char top = rule.charAt(2);

            if (next[x][y] == null) {
                next[x][y] = new ArrayList<>();
            }
            next[x][y].add(top);
        }

        return dfs(bottom.toCharArray(), next, memo);
    }

    private boolean dfs(char[] row, List<Character>[][] next, Map<String, Boolean> memo) {

        if (row.length == 1) return true;

        String key = new String(row);
        if (memo.containsKey(key)) return memo.get(key);

        char[] upper = new char[row.length - 1];
        boolean possible = buildNextRow(0, row, upper, next, memo);

        memo.put(key, possible);
        return possible;
    }

    private boolean buildNextRow(
            int idx,
            char[] curr,
            char[] upper,
            List<Character>[][] next,
            Map<String, Boolean> memo) {

        if (idx == upper.length) {
            return dfs(upper, next, memo);
        }

        int a = curr[idx] - 'A';
        int b = curr[idx + 1] - 'A';

        if (next[a][b] == null) return false;

        for (char ch : next[a][b]) {
            upper[idx] = ch;
            if (buildNextRow(idx + 1, curr, upper, next, memo)) {
                return true;
            }
        }

        return false;
    }
}
