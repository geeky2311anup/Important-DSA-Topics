# 📘 C++ Solution Explanation

## 💡 Problem Summary

You are given two integers **a** and **b**.

The steps to compute the final answer are:

1. Increase **a** by 1 → `a + 1`
2. Multiply this updated value by **4**
3. Multiply **b** by **3**
4. Add both contributions to get a **total**
5. Divide this total by **8**, but using **ceiling division** (rounding up)

The result after these operations is printed.

---

## 🧠 Intuition

Think of the problem as computing a weighted total:

- Each unit of the updated `a` contributes **4**
- Each unit of `b` contributes **3**

After computing this total, we want to see:
> **How many full groups of size 8 are needed to cover this total?**

Since groups must be complete, if the total is not exactly divisible by 8,  
we take the **next integer** (ceiling).

---

## 🛠️ Approach

1. Read integers `x` and `y`
2. Increase `x` by 1
3. Compute  
sum = (x + 1) * 4 + y * 3

markdown
Copy code
4. Compute  
result = ceil(sum / 8)

arduino
Copy code
5. Print the result

We use a mathematical trick for ceiling division:


{ceil}(S / 8) = (S + 7) / 8


---

# ✅ C++ Code (Non-Plagiarized)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);

 int x, y;
 cin >> x >> y;

 // After increasing x by 1
 int updated = x + 1;

 // Compute weighted total
 int sum = updated * 4 + y * 3;

 // Divide by 8 with ceiling
 int result = (sum + 7) / 8;  // ceiling division trick

 cout << result;
 return 0;
}
