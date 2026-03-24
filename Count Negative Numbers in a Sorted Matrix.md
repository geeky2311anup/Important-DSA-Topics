# 🤔 Am I the only one who solved **Count Negative Numbers in a Sorted Matrix** in the most straightforward way? 😌✨

---

## 🧩 Problem Name  
**Count Negative Numbers in a Sorted Matrix** (LeetCode)

---

## 🎯 Intuition — what you want to do  
> You are given a 2D matrix where:
> - Each row is sorted in **non-increasing order**
> - Each column is also sorted in **non-increasing order**
>
> Your task is simple:
> 👉 **Count how many elements in the matrix are negative.**

At its core, this is just:
> **Scan the matrix and count values `< 0`.**

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse every cell in the matrix.
> - Check if the value is negative.
> - Maintain a running counter.
> - Return the total count.

Why does this work?
> Because regardless of sorting, **every negative element must be counted exactly once**.

---

## 🧠 Why this works  
> - The matrix size is manageable.
> - A full traversal guarantees correctness.
> - No tricky edge cases:
>   - Zero is not negative.
>   - All negatives are counted.
>
> This is the **most readable and safest approach**, especially when constraints are small.

---

## 🔧 Approach (matching the implementation)

### 1) Get matrix dimensions  
> - `rows = matrix.length`  
> - `cols = matrix[0].length`

---

### 2) Traverse every cell  
> Use two nested loops:
> - Outer loop → rows  
> - Inner loop → columns  

---

### 3) Count negatives  
> - If `matrix[r][c] < 0`, increment the counter.

---

### 4) Return the count  
> After scanning all cells, return the total.

---

## 🔍 What each variable contributes

### `total`
> Stores the number of negative elements found so far.

### `rows`
> Number of rows in the matrix.

### `cols`
> Number of columns in the matrix.

---

## 🧪 Dry Run (small example)

Matrix:
[
[ 5, 3, -1],
[ 2, -2, -4],
[-1, -3, -5]
]

yaml
Copy code

Traversal:
- Row 0 → one negative
- Row 1 → two negatives
- Row 2 → three negatives

Total = **6**

---

## 📊 Complexity

> - **Time Complexity:** `O(rows × cols)`  
> - **Space Complexity:** `O(1)`  

*(Only a counter is used.)*

---

## 💻 Code

```java
```java
class Solution {
    public int countNegatives(int[][] matrix) {

        // Stores total number of negative values
        int total = 0;

        // Total number of rows
        int rows = matrix.length;

        // Total number of columns (matrix assumed non-empty)
        int cols = matrix[0].length;

        // Iterate through each row
        for (int r = 0; r < rows; r++) {

            // Iterate through each column in current row
            for (int c = 0; c < cols; c++) {

                // If current element is negative, increment counter
                if (matrix[r][c] < 0) {
                    total++;
                }
            }
        }

        // Return final count of negative numbers
        return total;
    }
}
```

