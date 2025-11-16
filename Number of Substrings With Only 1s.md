# 🔥 Clean & Simple C++ Solution – Explained Clearly

## 🔍 Problem Summary
For each test case:

- You read an integer **N**
- Then read **N** numbers
- You must check **how many distinct values** are present

### 🎯 Output Rules
- If there are **at least 2 different values**, output **2**
- Otherwise, output **-1**

---

## 💡 Key Idea
You don't need the actual values —  
you only need to know **how many unique numbers** appear.

That means a simple `set` / `unordered_set` solves the problem.

---

## 🧠 Approach
1. Create an `unordered_set<int>`
2. Insert each number into it  
   (duplicates automatically get ignored)
3. After reading all numbers:
   - If set size > 1 → print **2**
   - Else → print **-1**

This is efficient and clean.

---

## 💻 Optimized, Non-Plagiarized C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        unordered_set<int> distinctVals;
        distinctVals.reserve(n);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            distinctVals.insert(x);
        }

        if (distinctVals.size() > 1) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
