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
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
      long long a, b, c, d;
      cin >> a >> b >> c >> d;

      if (b > d || c > (a + d - b)) {
          cout << -1 << '\n';
      } else {
          long long extra = d - b;
          long long result = a + extra + (extra - c);
          cout << result << '\n';
      }
  }

  return 0;
}
