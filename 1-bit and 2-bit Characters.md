# 717. 1-bit and 2-bit Characters

## Intuition
We are given an array `bits` representing characters that can be encoded as either:
- A **1-bit character:** represented by a single `0`
- A **2-bit character:** represented by either `10` or `11`

The goal is to determine whether the **last character** in the sequence must be a **1-bit character**.

The main observation is that:
- When we see a `1`, it means this is the start of a **2-bit character**, so we must skip two indices.
- When we see a `0`, it represents a **1-bit character**, so we move one step ahead.
We keep moving until we reach the end of the array and then check if we stopped **exactly at the last index**.

---

## Approach
1. Initialize a pointer `pointer = 0` to traverse the array.
2. Traverse until the second-last element (`pointer < n - 1`):
   - If `bits[pointer] == 1`, it means we found a **2-bit character**, so move `pointer += 2`.
   - Otherwise (`bits[pointer] == 0`), it’s a **1-bit character**, so move `pointer += 1`.
3. After the loop:
   - If `pointer == n - 1`, we landed **exactly on the last bit**, meaning the last character is **1-bit** → return `true`.
   - Otherwise, we overshot the end (pointer == n), meaning the last character was part of a **2-bit character** → return `false`.

---

## Dry Run
**Example 1:**  
bits = [1,0,0]

yaml
Copy code
Steps:
- pointer = 0 → bits[0] = 1 → move 2 steps → pointer = 2
- pointer = 2 → stop (loop condition fails)

Now `pointer == n - 1` (2 == 2) → ✅ last bit is a **1-bit character**  
**Output:** true

---

**Example 2:**  
bits = [1,1,1,0]

yaml
Copy code
Steps:
- pointer = 0 → bits[0] = 1 → move 2 → pointer = 2  
- pointer = 2 → bits[2] = 1 → move 2 → pointer = 4 → end  

Now `pointer != n - 1` → ❌ last bit is **not** a 1-bit character  
**Output:** false

---

## Complexity
- **Time Complexity:** O(n) — we traverse the array once.  
- **Space Complexity:** O(1) — uses only one pointer variable.

---

## Code
```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        int pointer = 0;

        while (pointer < n - 1) {
            if (bits[pointer] == 1) {
                // skip two-bit character
                pointer += 2;
            } else {
                // skip one-bit character
                pointer += 1;
            }
        }

        // if we land exactly on last index → last character is 1-bit
        return pointer == n - 1;
    }
}
