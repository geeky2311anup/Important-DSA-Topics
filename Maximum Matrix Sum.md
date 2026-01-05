# 😌 Flipping signs like a pro — **Maximum Matrix Sum** done the smart way ✨  
*(Yes, this is one of those problems where math intuition beats brute force)*

---

## 🎯 Problem Name  
**Maximum Matrix Sum**

---

## 🎯 Intuition — what you want to do  
> You are given a matrix of integers.  
>  
> You are allowed to **flip the sign of any element any number of times** (effectively, you can choose the sign of each element).  
>  
> Your goal is to **maximize the total sum of the matrix**.

Key realization:
> 👉 You can freely flip signs, **but the parity (odd/even count) of negative numbers matters**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Convert every number to its **absolute value** to maximize contribution.
> - Track:
>   - How many numbers were originally negative
>   - The **smallest absolute value** in the entire matrix
> - If negatives are even → everything can be made positive.
> - If negatives are odd → **exactly one value must remain negative**.

This lets you compute the answer in **one pass**.

---

## 🧠 Why this works  
> - Flipping a sign twice cancels out → only parity matters.
> - With an **even** number of negatives:
>   - You can pairwise flip them → all become positive.
> - With an **odd** number of negatives:
>   - One value must stay negative.
>   - To minimize loss, keep the **smallest absolute value** negative.

So the best strategy is:
> **Sum of all absolute values − 2 × (smallest absolute value)**  
only when negatives are odd.

---

## 🔧 Approach (matching the implementation)

### 1) Traverse the matrix  
For every cell:
- Add `abs(value)` to `total`
- Count how many values are negative
- Track the smallest absolute value

---

### 2) Check parity of negatives  
> - If `negatives` is even → return `total`
> - Else → return `total - 2 × smallestAbs`

---

## 🔍 What each variable contributes

### `total`
> Sum of absolute values of all elements.

### `negatives`
> Count of negative numbers in the matrix.

### `smallestAbs`
> Minimum absolute value — the least painful number to keep negative.

---

## 🧪 Dry Run (example)

Matrix:
[ [ 1, -2 ],
[ -3, 4 ] ]

vbnet
Copy code

Step-by-step:
- Absolute sum = `1 + 2 + 3 + 4 = 10`
- Negatives = 2 (even)

Result:
10

yaml
Copy code

---

Another example:
[ [ -1, 2 ],
[ 3, 4 ] ]

markdown
Copy code

- Absolute sum = `1 + 2 + 3 + 4 = 10`
- Negatives = 1 (odd)
- smallestAbs = 1

Result:
10 - 2*1 = 8

yaml
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(n * m)`  
>   (single traversal of the matrix)
>
> - **Space Complexity:** `O(1)`  
>   (constant extra variables)

---

## 💻 Code

```java
class Solution {
    public long maxMatrixSum(int[][] grid) {
        long total = 0;
        int smallestAbs = Integer.MAX_VALUE;
        int negatives = 0;

        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                int val = grid[r][c];

                if (val < 0) negatives++;

                int absVal = Math.abs(val);
                smallestAbs = Math.min(smallestAbs, absVal);
                total += absVal;
            }
        }

        // If number of negatives is even, we can make all values positive
        if ((negatives & 1) == 0) {
            return total;
        }

        // Otherwise, one smallest absolute value must remain negative
        return total - 2L * smallestAbs;
    }
}
