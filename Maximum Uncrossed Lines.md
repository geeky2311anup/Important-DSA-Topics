# 😌 Is it really **Uncrossed Lines**… or just LCS wearing a disguise? 🤔✨

---

## 🎯 Problem Name  
**Maximum Uncrossed Lines**

---

## 🎯 Intuition — what you want to do  
> You are given two integer arrays `a` and `b`.  
>  
> You can draw lines connecting equal numbers between `a` and `b`, but:
> - Lines **must not cross**.
>
> The goal is to find the **maximum number of such lines**.

Key realization:
> 👉 This is **exactly the same** as finding the **Longest Common Subsequence (LCS)**.

So yes… if you’ve solved LCS, you’ve already solved this 😌

---

## 🎯 What you want to do (high-level goal / why)  
> - Match equal elements in order.
> - Maintain order so lines don’t cross.
> - Maximize the total matches.

Why DP?
> Because at each pair `(i, j)` you decide:
> - match them (if equal), or  
> - skip one element.

---

## 🧠 Why this works  
> - A non-crossing line means the **relative order must be preserved**.
> - That’s the **exact definition of LCS**.
> - Instead of a full `n × m` DP table, we optimize space using **1D DP**.

Even better:
> Always make the **second array smaller** to reduce memory usage.

---

## 🔧 Approach (matching your implementation)

### 1) Space optimization trick  
> If `a` is smaller than `b`, swap them.  
>  
> This ensures the DP array size is `O(min(n, m))`.

---

### 2) DP definition  
> `dp[j]` = LCS length for:
> - `a[0..i-1]`
> - `b[0..j-1]`

---

### 3) Transition logic  
For each `a[i-1]` and `b[j-1]`:

- If they are equal:
dp[j] = diag + 1

diff
Copy code

- Else:
dp[j] = max(dp[j], dp[j-1])

yaml
Copy code

Where:
> `diag` stores the old `dp[j-1]` from the previous row (`i-1`).

---

## 🔍 What each variable does

### `dp[j]`
> Best LCS value up to current `i` and `j`.

### `diag`
> Represents the **top-left diagonal value** (`dp[i-1][j-1]` in 2D DP).

### `temp`
> Temporary storage to safely update `diag`.

---

## 🧪 Dry Run (small example)

a = [1, 4, 2]
b = [1, 2, 4]

yaml
Copy code

Matches:
- 1 ↔ 1
- 2 ↔ 2

Maximum uncrossed lines = **2**

DP builds this step-by-step without crossing any order.

---

## 📊 Complexity

> - **Time Complexity:** `O(n × m)`  
> - **Space Complexity:** `O(min(n, m))`  

Clean. Optimal. Interview-approved.

---

## 💻 Code

```java
class Solution {
    public int maxUncrossedLines(int[] a, int[] b) {
        int n = a.length, m = b.length;

        // Ensure that array b is the smaller one to reduce space usage
        // This keeps the DP array as small as possible
        if (n < m) return maxUncrossedLines(b, a);

        // dp[j] represents the result for a[0..i-1] and b[0..j-1]
        // We only store one row to optimize space
        int[] dp = new int[m + 1];

        // Iterate through elements of array a
        for (int i = 1; i <= n; i++) {
            // diag stores the value of dp[j-1] from the previous row
            // It represents the diagonal cell in the 2D DP table
            int diag = 0;

            // Iterate through elements of array b
            for (int j = 1; j <= m; j++) {
                // Store current dp[j] before updating
                int temp = dp[j];

                // If elements match, extend the line (like LCS)
                if (a[i - 1] == b[j - 1]) {
                    dp[j] = diag + 1;
                } else {
                    // Otherwise, take the maximum of:
                    // - previous value in same column (dp[j])
                    // - value to the left (dp[j - 1])
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }

                // Update diag for next iteration
                diag = temp;
            }
        }

        // Final result stored in dp[m]
        return dp[m];
    }
}

