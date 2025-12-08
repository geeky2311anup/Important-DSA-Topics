# 🤔 Am I the only one who solved **Count Square Sum Triples** in such a simple way? 😌✨

---

## 🎯 Intuition — what you want to do  
> We need to count ordered Pythagorean triples of the form `(i, j, k)` with `1 ≤ i, j, k ≤ n`, `i < j < k`, and `i² + j² = k²`.  
>  
> The simplest approach is brute force: try every triple `(i, j, k)` and check the equation. Because `n` is small in typical constraints for this problem (e.g., `n ≤ 250` on LeetCode), the direct cubic scan is practical and straightforward.

---

## 🎯 What you want to do (high-level goal / why)  
> - Enumerate all triples with `1 ≤ i < j < k ≤ n`.  
> - For each triple, check if `i*i + j*j == k*k`.  
> - When it holds, two ordered triples count: `(i,j,k)` and `(j,i,k)`.  
> - Sum these counts and return the total.  
>
> Why this? Because the problem explicitly treats `(i,j,k)` and `(j,i,k)` as separate valid ordered triples when `i != j`. Counting both by adding `2` for each found pair is easy and correct.

---

## 🧠 Why this works  
> - The constraint ordering `i < j < k` ensures each unordered triple is considered once.  
> - For every unordered pair `{i, j}` with `i < j` that satisfies `i² + j² = k²`, there are exactly two ordered pairs that map to the same `k`: `(i,j,k)` and `(j,i,k)`.  
> - Adding `2` at each detection accounts for these ordered permutations without extra bookkeeping.

---

## 🔧 Approach (matching the implementation)

1. Initialize `count = 0`.  
2. Loop `i` from `1` to `n-2`.  
3. Loop `j` from `i+1` to `n-1`.  
4. Loop `k` from `j+1` to `n`.  
5. If `i*i + j*j == k*k`, increment `count` by `2`.  
6. Return `count`.

This mirrors your original code exactly — clear and literal.

---

## 🔍 What each part contributes (detailed)

### Outer loop `i`  
> picks the smallest element of the triple.

### Middle loop `j`  
> picks the middle element (strictly greater than `i`).

### Inner loop `k`  
> picks the largest element (strictly greater than `j`) and is the potential hypotenuse.

### Check `i*i + j*j == k*k`  
> validates Pythagorean relation. If true, we add `2` to account for both `(i,j,k)` and `(j,i,k)` ordered triples.

---

## 🧪 Dry Run (small example)

Let `n = 5`.

Triples to check include `(3,4,5)`:
- `3*3 + 4*4 = 9 + 16 = 25 = 5*5` → match
- We add `2` (for `(3,4,5)` and `(4,3,5)`)

No other valid triples ≤ 5.  
Final answer = **2**.

---

## 📊 Complexity

> - **Time Complexity:** `O(n³)` — three nested loops.  
> - **Space Complexity:** `O(1)` — constant extra space.

Given typical constraints (n up to a few hundreds), this is acceptable and simplest to implement.

---

## 💻 Code

```java
class Solution {
    public int countTriples(int n) {
        int c = 0;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (i * i + j * j == k * k) {
                        c += 2; // (i,j,k) and (j,i,k)
                    }
                }
            }
        }
        return c;
    }
}
