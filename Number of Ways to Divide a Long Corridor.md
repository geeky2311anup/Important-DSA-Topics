
### (Problem: **Number of Ways to Divide a Long Corridor**)

---

## 🎯 Intuition — what you want to do  
> You are given a corridor represented by a string of `'S'` (seats) and `'P'` (plants).  
>  
> The task is to divide the corridor into **sections**, where **each section must contain exactly 2 seats**.  
>  
> You can place dividers **only between characters**, and the number of valid ways to place dividers should be returned.

So the real idea is:
- Every section must have **exactly 2 seats**.
- Plants (`P`) don’t matter directly, but they give **choices** for placing dividers.
- Count how many valid ways those dividers can be placed.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the corridor from left to right.  
> - Count seats as you go.  
> - Every time you finish a **pair of seats**, you mark the position.  
> - When you start the **next pair**, the distance from the previous pair determines how many ways you can place a divider.  
> - Multiply all such choices together to get the total number of ways.

This turns a “place dividers” problem into a **simple multiplication of gaps**.

---

## 🧠 Why this works  
> - Each valid section must contain exactly 2 seats.  
> - Between two seat-pairs, there may be multiple positions (plants or gaps) where a divider can go.  
> - If there are `k` possible divider positions between two seat-pairs, then:
>   - total ways = product of all such `k` values.  
> - If the total number of seats is odd or zero, it’s **impossible** to divide correctly.

This is a classic **combinatorics-by-gaps** problem.

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Initialize tracking variables
- `ways = 1` → stores final answer  
- `seats = 0` → total seats seen so far  
- `lastPairEnd = -1` → index where the previous seat-pair ended  

---

### 2️⃣ Traverse the corridor
For each character at index `i`:

#### If it is a seat `'S'`:
- Increment seat count.
- If this seat is the **first seat of a new pair** (i.e., seat count is odd and > 2):
  - Multiply `ways` by `(i - lastPairEnd)`  
  - This represents all possible divider positions between seat-pairs.
- If this seat completes a **pair** (seat count is even):
  - Update `lastPairEnd = i`

---

### 3️⃣ Final validity check
- If total seats = 0 → no valid sections → return 0  
- If total seats is odd → impossible to form pairs → return 0  
- Otherwise return `ways % MOD`

---

## 🔍 What each variable contributes

### `seats`
> Tracks how many seats have appeared so far, helping identify pair boundaries.

### `lastPairEnd`
> Marks the index where the last completed pair ended — used to calculate gap size.

### `(i - lastPairEnd)`
> Counts the number of valid divider positions between consecutive seat-pairs.

### `ways`
> Accumulates total number of valid divider arrangements using multiplication.

---

## 🧪 Dry Run (example)

Input:
corridor = "SSPPSPS"

makefile
Copy code

Indices:
0:S, 1:S, 2:P, 3:P, 4:S, 5:P, 6:S

arduino
Copy code

Process:
- Seats at 0 & 1 → first pair → lastPairEnd = 1  
- Next seat at 4 starts new pair:
  - gap = 4 - 1 = 3 → ways = 3  
- Seats at 4 & 6 complete second pair  

Final answer = **3**

---

## 📊 Complexity

> - **Time Complexity:** `O(n)` — single pass over the string  
> - **Space Complexity:** `O(1)` — constant extra space  

---

## 💻 Code

```java
class Solution {
    public int numberOfWays(String corridor) {

        // Mod value to avoid integer overflow
        final int MOD = 1_000_000_007;

        long ways = 1;

        // Counts total seats encountered
        int seats = 0;

        // Stores index of the second seat
        // of the previous valid pair
        int lastPairEnd = -1;

        // Traverse the corridor
        for (int i = 0; i < corridor.length(); i++) {

            char ch = corridor.charAt(i);

            // Process only seats
            if (ch == 'S') {

                seats++;

                /*
                   Whenever we start a new pair of seats
                   after the first pair, calculate the
                   possible partition positions.

                   Example:
                   S P P S | P P | S P S

                   Number of choices = distance between
                   current seat and previous pair end
                */
                if (seats > 2 && (seats & 1) == 1) {
                    ways = (ways * (i - lastPairEnd)) % MOD;
                }

                // If seat count becomes even,
                // this seat completes a pair
                if ((seats & 1) == 0) {
                    lastPairEnd = i;
                }
            }
        }

        // Invalid if:
        // 1. No seats exist
        // 2. Total seats are odd
        if (seats == 0 || (seats & 1) == 1) {
            return 0;
        }

        return (int) ways;
    }
}
