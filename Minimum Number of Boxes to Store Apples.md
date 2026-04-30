# 🤔 Am I the only one who solved **Minimum Number of Boxes to Store Apples** in such a simple greedy way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given:
> - `apples[]`: number of apples in each pile  
> - `capacity[]`: capacity of each box  
>
> You need to find the **minimum number of boxes** required to store **all apples**.
>
> The apples are already fixed in total quantity — so the real task is:
>
> 👉 **Pick the fewest boxes whose total capacity is ≥ total apples.**

This immediately hints at a **greedy strategy**.

---

## 🎯 What you want to do (high-level goal / why)  
> - First, compute the **total number of apples** required to be stored.
> - Then, always use the **largest capacity boxes first**.
> - Keep adding box capacities until the sum becomes ≥ required apples.
> - Count how many boxes were used.

Why greedy works here?
> Because choosing the biggest box first reduces the total number of boxes needed.

---

## 🧠 Why this works  
> - Any solution must reach at least the total apple count.
> - Using a smaller box instead of a larger one **never helps reduce the box count**.
> - Sorting capacities in descending order ensures:
>   - You reach the required sum as fast as possible.
>   - You minimize the number of boxes.

This is a classic **“min elements to reach target sum”** greedy problem.

---

## 🔧 Approach (matching your implementation)

### 1) Compute total apples  
> Sum all values in `apples[]` to get `required`.

---

### 2) Sort box capacities in descending order  
> Convert `capacity[]` to `Integer[]` and sort in reverse order so that:
largest capacity boxes come first

yaml
Copy code

---

### 3) Keep filling boxes  
> - Iterate through sorted capacities.
> - Add capacity to `filled`.
> - Increment `used` box count.
> - Stop once `filled >= required`.

---

### 4) Return result  
> The number of boxes used is the answer.

---

## 🔍 What each variable contributes

### `required`
> Total number of apples that must be stored.

### `caps[]`
> Box capacities sorted in descending order for greedy selection.

### `filled`
> Total capacity accumulated so far.

### `used`
> Number of boxes used to reach the target.

---

## 🧪 Dry Run (small example)

Input:
apples = [1, 3, 2]
capacity = [4, 3, 1, 5]

diff
Copy code

Steps:
- required = 6
- sorted capacities = [5, 4, 3, 1]
- take 5 → filled = 5 (not enough)
- take 4 → filled = 9 (enough)

Answer:
2

yaml
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(n log n)`  
>   (sorting capacities)
>
> - **Space Complexity:** `O(n)`  
>   (boxed array for sorting)

---

## 💻 Code

```java
import java.util.*;

class Solution {
    public int minimumBoxes(int[] apples, int[] capacity) {

        // Step 1: Calculate total apples that need to be stored
        int required = 0;
        for (int a : apples) {
            required += a;
        }

        // Step 2: Convert capacity array to Integer[] 
        // (needed because Arrays.sort with custom comparator works on objects, not primitives)
        Integer[] caps = Arrays.stream(capacity)
                               .boxed()
                               .toArray(Integer[]::new);

        // Step 3: Sort capacities in descending order
        // so we use largest boxes first (greedy approach)
        Arrays.sort(caps, (a, b) -> b - a);

        int filled = 0; // total capacity used so far
        int used = 0;   // number of boxes used

        // Step 4: Pick boxes one by one (largest first)
        for (int c : caps) {
            filled += c; // add current box capacity
            used++;      // increment box count

            // If we can store all apples, stop early
            if (filled >= required) {
                break;
            }
        }

        // Step 5: Return number of boxes used
        return used;
    }
}
