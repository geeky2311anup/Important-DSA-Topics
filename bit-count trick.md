# 🤔 Am I the only one who noticed this neat **bit-count trick**? 😌✨

---

## 🧩 Problem Name  
**(Based on logic)**: *Bitwise Index Validation*  
*(Check whether each array value has the same number of set bits as its 1-based index)*

---

## 🎯 Intuition — what you want to do  
> You are given an array `arr` of size `n`.  
>  
> For every position `i` (1-based index), you want to check:
>
> ```
> number of set bits in arr[i] == number of set bits in (i + 1)
> ```
>
> If this condition holds for **all elements**, print `"Yes"`, otherwise print `"No"`.

So the task is not about values or sorting — it’s purely about **binary representation**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the array once.
> - For each index:
>   - Count set bits in the value.
>   - Count set bits in its 1-based index.
> - If any mismatch occurs, stop immediately and answer `"No"`.
> - If all positions match, answer `"Yes"`.

Why early stopping?
> Because a single mismatch invalidates the entire array.

---

## 🧠 Why this works  
> - Binary set-bit count is a **stable and deterministic property**.
> - The index `(i + 1)` is fixed and known at traversal time.
> - There is no dependency between elements — each check is independent.
> - As soon as one element fails, further checks are unnecessary.

This leads to a clean **linear scan with bitwise operations**.

---

## 🔧 Approach (matching the implementation)

### 1) Helper function: `bitCount(int x)`
> - Repeatedly check the least significant bit using `x & 1`.
> - Right-shift `x` until it becomes zero.
> - Count how many times a `1` appears.

This computes the **number of set bits** in `x`.

---

### 2) Process each test case
> - Read `n` and the array `arr`.
> - Initialize a boolean flag `ok = true`.
> - Loop over all indices `i` from `0` to `n-1`:
>   - `bitsInValue = bitCount(arr[i])`
>   - `bitsInIndex = bitCount(i + 1)`
>   - If they differ → set `ok = false` and break.

---

### 3) Print result
> - If `ok` is still true → print `"Yes"`.
> - Otherwise → print `"No"`.

---

## 🔍 What each part contributes

### `bitCount(int x)`
> Computes how many `1`s exist in the binary form of a number.

### `bitsInValue`
> Set-bit count of the current array element.

### `bitsInIndex`
> Set-bit count of the element’s **1-based index**.

### `ok`
> Tracks whether all positions satisfy the required condition.

---

## 🧪 Dry Run (small example)

**Input**
n = 3
arr = [1, 2, 3]

sql
Copy code

Binary representations:
Index (1-based): 1 → 001 → bits = 1
Value: 1 → 001 → bits = 1 ✅

Index: 2 → 010 → bits = 1
Value: 2 → 010 → bits = 1 ✅

Index: 3 → 011 → bits = 2
Value: 3 → 011 → bits = 2 ✅

pgsql
Copy code

All match → **Yes**

---

## 📊 Complexity

> - **Time Complexity:**  
>   `O(n × log(maxValue))`  
>   (bit counting per element)
>
> - **Space Complexity:**  
>   `O(1)` extra space (excluding input array)

---

## 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

// counts number of 1s in binary representation
int bitCount(int x) {
    int ones = 0;
    while (x > 0) {
        if (x & 1) ones++;
        x >>= 1;
    }
    return ones;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            int bitsInValue = bitCount(arr[i]);
            int bitsInIndex = bitCount(i + 1);

            if (bitsInValue != bitsInIndex) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}
