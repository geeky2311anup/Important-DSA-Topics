# 😏 Is it just DP… or **GCD-state DP flexing quietly**? 🤔✨  
*(Counting Coprime Selections without losing sanity)*

---

## 🎯 Problem Name  
**Count Coprime Selections from Matrix**

---

## 🎯 Intuition — what you want to do  
> You are given a matrix where:
> - From **each row**, you must pick **exactly one element**.
> - After picking one number from every row, take the **GCD of all chosen numbers**.
>
> Your task:
> 👉 **Count how many ways result in final GCD = 1 (coprime)**  
> Return the answer modulo `1e9 + 7`.

Brute force?
> ❌ Impossible — combinations explode exponentially.

So what’s the trick?
> 👉 Track **GCD states**, not actual selections.

---

## 🎯 What you want to do (high-level goal / why)  
> - Process the matrix **row by row**.
> - Keep a DP map where:
>   - `key = gcd value so far`
>   - `value = number of ways to reach this gcd`
> - Update the map after each row.
> - In the end, return the count of ways where `gcd = 1`.

Why this works:
> GCD values **shrink fast** — the number of distinct gcds is very small.

---

## 🧠 Why this works  
> - GCD is **associative**:  
>   `gcd(a, b, c) = gcd(gcd(a, b), c)`
> - Instead of tracking full sequences, we only track:
>   - what GCD they produce
>   - how many ways lead to that GCD
> - Even if rows are large, GCD states remain limited.

This is a classic **state-compression DP on GCD**.

---

## 🔧 Approach (matching your implementation)

### 1) DP state definition  
> `current[g]` = number of ways to pick elements so far such that their GCD is `g`.

> Start with:
> current = { 0 → 1 }

> Why `0`?
> Because `gcd(x, 0) = x` — perfect neutral start.

---

### 2) Process each row  
For every row:
- Create a new map `nextState`
- For each value `val` in the row:
  - For each `(prevGcd, ways)` in `current`:
    - `newGcd = gcd(prevGcd, val)`
    - Add `ways` to `nextState[newGcd]`

This builds **all valid transitions**.

---

### 3) Move to next row  
After finishing a row:
current = nextState

yaml
Copy code

---

### 4) Final answer  
After processing all rows:
answer = current.get(1)

yaml
Copy code
Because:
> GCD = 1 ⇢ numbers are coprime.

---

## 🔍 What each variable contributes

### `current`
> DP map of gcd → number of ways so far.

### `nextState`
> Temporary map for the next row’s transitions.

### `prevGcd`
> GCD accumulated till previous row.

### `newGcd`
> Updated GCD after including current value.

---

## 🧪 Dry Run (small example)

Matrix:
[
[2, 3],
[4, 9]
]


Row 1:
- Pick 2 → gcd(0,2)=2
- Pick 3 → gcd(0,3)=3

`current = {2:1, 3:1}`

Row 2:
- From gcd 2:
  - pick 4 → gcd(2,4)=2
  - pick 9 → gcd(2,9)=1
- From gcd 3:
  - pick 4 → gcd(3,4)=1
  - pick 9 → gcd(3,9)=3

Final:
{2:1, 1:2, 3:1}



Answer = **2** (two coprime selections)

---

## 📊 Complexity

> - **Time Complexity:**  
>   `O(rows × cols × distinctGCDs)`  
>   (distinct GCDs are small in practice)
>
> - **Space Complexity:**  
>   `O(distinctGCDs)`

Efficient where brute force would die instantly.

---

## 💻 Code

```java
class Solution {

    public int countCoprime(int[][] matrix) {
        final int MOD = 1_000_000_007;

        Map<Integer, Integer> current = new HashMap<>();
        current.put(0, 1);   // base gcd state

        for (int[] row : matrix) {
            Map<Integer, Integer> nextState = new HashMap<>();

            for (int val : row) {
                for (Map.Entry<Integer, Integer> entry : current.entrySet()) {
                    int prevGcd = entry.getKey();
                    int ways = entry.getValue();

                    int newGcd = computeGcd(val, prevGcd);
                    nextState.put(
                        newGcd,
                        (nextState.getOrDefault(newGcd, 0) + ways) % MOD
                    );
                }
            }

            current = nextState;
        }

        return current.getOrDefault(1, 0);
    }

    private int computeGcd(int x, int y) {
        while (y != 0) {
            int rem = x % y;
            x = y;
            y = rem;
        }
        return x;
    }
}
