# 🤔 Am I the only one who solved this in such a simple way? 😌✨

---

## 🎯 Intuition — what you want to do  
> A trapezoid is formed when you pick **two points from one horizontal line** and **two points from another horizontal line**.  
> The two lines are parallel because they share the same `y` value.  
>  
> So for each horizontal line `y`, if it has `cnt` points, then the number of ways to pick 2 points is:  
>  
> **C(cnt, 2)**  
>
> Once you know this value for each level, the total trapezoids are:  
>  
> **Sum over all pairs of levels (i < j) of:**  
> `C(cnt[i], 2) × C(cnt[j], 2)`  

The trick is computing this efficiently without an O(n²) loop.

---

## 🎯 What you want to do (high-level goal / why)  
> - Count how many points lie on each horizontal level.  
> - Compute how many “point pairs” each level contributes: `f[i] = C(cnt[i], 2)`.  
> - We want ALL combinations of levels → all products `f[i] * f[j]`.  
>
> Instead of looping all pairs, use the identity:  
>
> \[
> \sum_{i<j} f[i]f[j] = \frac{( \sum f )^2 - \sum f^2}{2}
> \]

This reduces the problem to summations only → O(n).

---

## 🧠 Why this works  
> - A trapezoid must take 2 points from one horizontal line, and 2 from another.  
> - `C(cnt,2)` gives the number of pairs on one line.  
> - Every pair on line A can combine with every pair on line B.  
> - So the total is exactly all pairwise products of the `f[i]` values.  
>  
> The algebraic identity allows computing all pairwise products without a double-loop.  
>
> Division by 2 is handled via modular inverse `(MOD + 1) / 2`.

---

## 🔧 Approach (matching your implementation)

### **1. Count points per horizontal level**  
Store frequency of each `y` in `levelCount`.

### **2. For each level compute:**  
f = C(cnt,2) = cnt*(cnt-1)/2

yaml
Copy code
Accumulate:  
- `totalPairs += f`  
- `totalPairsSq += f*f`

### **3. Apply the identity**
\[
\text{Answer} = \frac{(totalPairs)^2 - totalPairsSq}{2}
\]

### **4. Apply modulo and modular inverse**  
Keep everything modulo `1e9+7`.

---

## 🔍 What each part contributes (detailed)

### Counting level frequencies  
> Determines how many points lie on each horizontal line.

### Computing `C(cnt,2)`  
> Gives number of point-pairs on that line — essential building block of trapezoids.

### Accumulating sum(f) and sum(f²)  
> Prepares for the formula that computes all cross-level trapezoids efficiently.

### Applying the identity  
> Computes the final trapezoid count in O(1) time from aggregated sums.

---

## 🧪 Dry Run (conceptual)

Assume frequency per level gives:  
cnt = [3, 2, 4]

makefile
Copy code

Then:  
C(3,2) = 3
C(2,2) = 1
C(4,2) = 6

cpp
Copy code

Level pair products:  
31 = 3
36 = 18
1*6 = 6
Total = 27

powershell
Copy code

Using formula:  
sum f = 3+1+6 = 10
sum f^2 = 9+1+36 = 46

((10^2) - 46) / 2 = (100 - 46)/2 = 54/2 = 27 ✔️

yaml
Copy code

---

## 📊 Complexity  
> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(n)` for map  

---

## 💻 Code

```java
import java.util.*;

class Solution {
    /**
     * Calculates the number of pairs of horizontal segments that can form a trapezoid.
     * A trapezoid is formed by picking two points on one horizontal line (y1) 
     * and two points on a different horizontal line (y2).
     */
    public int countTrapezoids(int[][] points) {
        final long MOD = 1_000_000_007L;
        // HALF is the modular multiplicative inverse of 2 under MOD.
        // Used to perform (x / 2) % MOD.
        final long HALF = (MOD + 1L) / 2L;

        // Step 1: Count how many points exist on each horizontal line (y-level).
        Map<Integer, Integer> levelCount = new HashMap<>();
        for (int[] pt : points) {
            int y = pt[1];
            levelCount.merge(y, 1, Integer::sum);
        }

        long totalPairs = 0L;   // Sum of (nCr(points_at_y, 2)) for all y
        long totalPairsSq = 0L; // Sum of (nCr(points_at_y, 2)^2) for all y

        // Step 2: Calculate combinations of 2 points for every y-level.
        for (int cnt : levelCount.values()) {
            // A line needs at least 2 points to form a horizontal segment.
            if (cnt < 2) continue;

            long c = cnt;
            // nCr calculation: ways to pick 2 points from 'c' points on this line.
            long pairsOnThisLine = c * (c - 1L) / 2L;
            long val = pairsOnThisLine % MOD;

            // We track the sum and the sum of squares to use the identity:
            // (Sum a_i)^2 - (Sum a_i^2) = 2 * (Sum of all pairs a_i * a_j)
            totalPairs = (totalPairs + val) % MOD;
            totalPairsSq = (totalPairsSq + val * val % MOD) % MOD;
        }

        // Step 3: Calculate the final count.
        // We want to pick two different y-levels (i, j) and multiply their pairs: val_i * val_j.
        // The result is the sum of products for all unique pairs of levels.
        
        // (totalPairs)^2 includes (val_i * val_j) twice and (val_i^2) once.
        long res = (totalPairs * totalPairs) % MOD;
        // Subtract the squares (val_i^2) to leave only the cross-products.
        res = (res - totalPairsSq + MOD) % MOD;
        // Divide by 2 (multiply by HALF) because (val_i * val_j) and (val_j * val_i) 
        // represent the same trapezoid.
        res = (res * HALF) % MOD;

        return (int) res;
    }
}
