For each test case, we are given four integers **a, b, c, d**.  
Our task is to determine whether it is possible to reach a valid configuration under the given constraints.  
If it is possible, we compute and return the required result; otherwise, we return **-1**.

---

## Intuition

The problem reduces to checking whether certain transformations are **feasible** and then calculating the result using a direct formula.

There are two key observations:

1. We may need to increase `b` to `d`.  
2. This increase gives us extra capacity that can help satisfy the requirement involving `c`.

If these conditions cannot be satisfied, the answer is simply **-1**.

---

## Feasibility Conditions

To proceed, **both** of the following conditions must hold:

1. **`b <= d`**  
   - If `b` is already greater than `d`, we cannot reduce it, so the task is impossible.

2. **`c <= a + (d - b)`**  
   - Increasing `b` to `d` gives us `(d - b)` extra units.
   - If even after using this extra capacity, `c` is still too large, the task is impossible.

If **any** of these conditions fail, return `-1`.

---

## Computing the Answer

When both conditions are satisfied:

- Let  
extra = d - b

kotlin
Copy code

- The final result is calculated as:
result = a + extra + (extra - c)

yaml
Copy code

This formula accounts for:
- The initial value `a`
- Extra gain from adjusting `b` to `d`
- Adjustment needed to satisfy `c`

---

## Algorithm

For each test case:
1. Read `a, b, c, d`
2. If `b > d` or `c > a + (d - b)`, print `-1`
3. Otherwise:
 - Compute `extra = d - b`
 - Compute and print `a + extra + (extra - c)`

---

## Complexity Analysis

- **Time Complexity:** `O(1)` per test case  
- **Space Complexity:** `O(1)`

---

## Reference Implementation (C++)

```cpp
class Solution {
    public boolean checkStrings(String first, String second) {
        
        // Arrays to store frequency differences of characters
        // at even and odd indices
        int[] evenCount = new int[26];
        int[] oddCount = new int[26];

        int n = first.length();

        // Traverse both strings simultaneously
        for (int i = 0; i < n; i++) {
            char c1 = first.charAt(i);
            char c2 = second.charAt(i);

            // If index is even
            if ((i & 1) == 0) {
                // Increase count for first string character
                // Decrease count for second string character
                evenCount[c1 - 'a']++;
                evenCount[c2 - 'a']--;
            } else {
                // If index is odd, do the same for oddCount array
                oddCount[c1 - 'a']++;
                oddCount[c2 - 'a']--;
            }
        }

        // Check if all counts are zero
        // If not, strings cannot be made equal
        for (int i = 0; i < 26; i++) {
            if (evenCount[i] != 0 || oddCount[i] != 0) {
                return false;
            }
        }

        // If all counts match, strings are equivalent
        return true;
    }
}
