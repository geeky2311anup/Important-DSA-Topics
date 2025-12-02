
---

## 🎯 Intuition — what you want to do  
> Given a permutation-like array `a` of size `n`, we want to answer queries that ask: if we **remove all values strictly between L and R** (value-wise), how many inversions remain?  
>  
> An **inversion** is a pair `(i < j)` with `a[i] > a[j]`.  
>  
> Precompute the total number of inversions once, then for a query `(L, R)` subtract the inversions that are completely internal to the removed-value ranges so the remaining inversions are those that survive after removing values in `(L, R)`.

---

## 🎯 What you want to do (high-level goal / why)  
> - Compute the total inversions in the array.  
> - Precompute contributions grouped by **value** rather than by index: for each value `v`, how many inversions are there where `v` participates as the *right element* (`a[j] = v`, coming from left larger values) and how many inversions where `v` participates as the *left element* (`a[i] = v`, contributing with smaller right values).  
> - With these per-value contributions we can remove (subtract) contributions that lie totally inside the forbidden intervals for each query quickly by range-summing over value domain.  
>
> This transforms query handling from index-based reasoning to value-based range sums.

---

## 🧠 Why this works  
> - Inversions can be counted and attributed to one of the two participating values. If we attribute an inversion `(i<j, a[i] > a[j])` to the value `a[j]` (the right value) we can sum how many inversions each right-value receives from earlier bigger elements. Similarly attributing to the left-value `a[i]` we can count how many later smaller elements it pairs with.  
> - For a query removing values in `(L, R)` (actually the code uses thresholds `L` and `R`, handling inclusive behaviour), inversions that we must delete are precisely those where **both** participating values lie inside removed-value set. If we pre-store per-value contributions and use Fenwick trees (BITs) for prefix/range sums over the value axis, removing those is an O(log n) range-sum per query.  
> - All required data can be accumulated in two Fenwick-based stores: one stores contributions when value acts as the right-end of an inversion, the other when it acts as the left-end. Then query answers are `totalInversions - removedByRightSide - removedByLeftSide`.

---

## 🔧 Approach (matching the implementation)

### 1) Data structures
> - `Fenwick` (Binary Indexed Tree) for point updates and prefix/range sums over **value domain** `[1..n]`.  
> - `bitLeft` and `storeLeft`: `bitLeft` tracks seen values while scanning left→right; `storeLeft` stores, at index `v`, how many inversions have `v` as the right element.  
> - `bitRight` and `storeRight`: symmetric but built by scanning right→left; `storeRight` stores, at index `v`, how many inversions have `v` as the left element.

### 2) Precompute `totalInv` and `storeLeft`
> - Iterate `i` from `1..n`:  
>   - `biggerBefore = count of previous values > a[i]` = `bitLeft.range(a[i], n)`  
>   - Add `biggerBefore` to `totalInv`.  
>   - `storeLeft.update(a[i], biggerBefore)` — record that value `a[i]` (as right element) has `biggerBefore` inversions.  
>   - Mark `a[i]` in `bitLeft` (`bitLeft.update(a[i], 1)`).

### 3) Precompute `storeRight`
> - Iterate `i` from `n..1`:  
>   - `smallerAfter = count of later values < a[i]` = `bitRight.range(1, a[i])`  
>   - `storeRight.update(a[i], smallerAfter)` — record that value `a[i]` (as left element) pairs with `smallerAfter` smaller later values.  
>   - Mark `a[i]` in `bitRight`.

### 4) Answer queries `(L, R)`
> - Start from `ans = totalInv`.  
> - Subtract inversions where *both* values are ≥ `R` — these were stored in `storeLeft` for right-values with value ≥ `R`. So `ans -= storeLeft.range(R, n)`.  
> - Subtract inversions where *both* values are ≤ `L` — these were stored in `storeRight` for left-values with value ≤ `L`. So `ans -= storeRight.range(1, L)`.  
> - Output `max(0, ans)` (safety clamp).

---

## 🔍 What each part contributes (detailed)

### Fenwick `bitLeft`
> helps compute, for each position `i`, how many previously seen values are larger than `a[i]` (needed to count inversions and to store them by right-value).

### Fenwick `storeLeft`
> for each value `v` stores `sum_{j: a[j]=v} (# of earlier elements > v)`.  
> When you want to remove all inversions whose *both values* are ≥ `R`, summing `storeLeft.range(R, n)` exactly counts inversions whose right element is in `[R..n]` and whose left came from a larger value (also ≥ R if both were ≥ R).

### Fenwick `bitRight`
> symmetric scan from right to left to help count, for each position `i`, how many later elements are smaller than `a[i]`.

### Fenwick `storeRight`
> for each value `v` stores `sum_{i: a[i]=v} (# of later elements < v)`.  
> Summing `storeRight.range(1, L)` counts inversions whose left element is in `[1..L]` and whose right element is smaller (also ≤ L when both are ≤ L).

### `totalInv`
> initial full inversion count used as base for all queries.

---

## 🧪 Dry Run (small example)

Array: `a = [3, 1, 4, 2]` (values 1..4), compute steps:

- Left→right:
  - i=1 (3): `biggerBefore=0` → total=0, storeLeft[3]+=0, mark 3
  - i=2 (1): `biggerBefore=count >1` =1 (the 3) → total=1, storeLeft[1]+=1, mark 1
  - i=3 (4): `biggerBefore=count >4` =0 → total=1, storeLeft[4]+=0, mark 4
  - i=4 (2): `biggerBefore=count >2` =2 (3 and 4) → total=3, storeLeft[2]+=2, mark 2

- Right→left:
  - i=4 (2): `smallerAfter=count<2` =0 → storeRight[2]+=0, mark 2
  - i=3 (4): `smallerAfter=count<4` =1 (2) → storeRight[4]+=1, mark 4
  - i=2 (1): `smallerAfter=count<1` =0 → storeRight[1]+=0, mark 1
  - i=1 (3): `smallerAfter=count<3` =2 (1 and 2) → storeRight[3]+=2, mark 3

`totalInv = 3` (pairs: (3,1), (3,2), (4,2))

Query example: `L=1, R=2` (remove values ≤1 and ≥2? — code subtracts storeLeft.range(R,n) and storeRight.range(1,L))
- `storeLeft.range(2,4)` sums contributions for right-values 2..4 (inversions where right >= R)  
- `storeRight.range(1,1)` sums contributions for left-values ≤ L  
After subtraction you get remaining inversions count.

(Exact query effect depends on problem statement indexing; code uses value thresholds as shown.)

---

## 📊 Complexity

> - **Preprocessing (counting & building stores):**  
>   - Left scan: `O(n log n)` (Fenwick updates/queries per element)  
>   - Right scan: `O(n log n)`  
> - **Each query:** `O(log n)` to compute two range sums with Fenwick trees.  
> - **Space:** `O(n)` for Fenwick trees and maps.

---

## 💻 Code

```cpp
// Problem: Inversion Queries
// Contest: CodeChef - START188
// URL: https://www.codechef.com/problems/INVQUER

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    inline void update(int idx, ll delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    inline ll prefix(int idx) const {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    inline ll range(int l, int r) const {
        if (l > r) return 0;
        return prefix(r) - prefix(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // BITs over value domain [1..n] (array is permutation / compressed)
    Fenwick bitLeft(n), storeLeft(n);   // contributions from left side (i < j, a[i] > a[j])
    Fenwick bitRight(n), storeRight(n); // contributions from right side

    ll totalInv = 0;

    // Count inversions (i < j, a[i] > a[j]) and distribute contributions by value a[j]
    for (int i = 1; i <= n; ++i) {
        // how many previous values are > a[i]
        ll biggerBefore = bitLeft.range(a[i], n);
        totalInv += biggerBefore;

        // store contribution at position of value a[i]
        storeLeft.update(a[i], biggerBefore);

        // mark current value as present
        bitLeft.update(a[i], 1);
    }

    // From right to left: (i < j, a[i] > a[j]), contribution associated with a[i]
    for (int i = n; i >= 1; --i) {
        // how many later values are < a[i]
        ll smallerAfter = bitRight.range(1, a[i]);
        storeRight.update(a[i], smallerAfter);
        bitRight.update(a[i], 1);
    }

    // Process queries
    while (q--) {
        int L, R;
        cin >> L >> R;

        if (L == R) {
            cout << 0 << "\n";
            continue;
        }

        ll ans = totalInv;

        // remove inversions with both values >= R
        ans -= storeLeft.range(R, n);

        // remove inversions with both values <= L
        ans -= storeRight.range(1, L);

        if (ans < 0) ans = 0;  // safety

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
