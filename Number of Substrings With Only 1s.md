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
    // Fast input/output (useful for large inputs)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; // Number of test cases
    cin >> tc;

    // Loop through each test case
    while (tc--) {
        int n;
        cin >> n; // Number of elements in this test case

        // Unordered set to store only distinct values
        unordered_set<int> distinctVals;

        // Reserve space to improve performance (avoids rehashing)
        distinctVals.reserve(n);

        // Read all numbers
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            // Insert into set (duplicates automatically ignored)
            distinctVals.insert(x);
        }

        // Check how many distinct values are present
        if (distinctVals.size() > 1) {
            // If at least 2 different values exist
            cout << 2 << '\n';
        } else {
            // If all values are same
            cout << -1 << '\n';
        }
    }

    return 0; // End of program
}
