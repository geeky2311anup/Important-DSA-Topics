# 🤔 Am I the only one who solved **Minimum Penalty for a Shop** in such a clean greedy scan? 😌✨

---

## 🧩 Problem Name  
**Minimum Penalty for a Shop** (LeetCode)

---

## 🎯 Intuition — what you want to do  
> You are given a string `s` consisting of characters:
> - `'Y'` → a customer comes at that hour  
> - `'N'` → no customer comes  
>
> The shop can close at **any hour** `h` (from `0` to `n`).  
>
> Penalty rules:
> - If the shop is **closed** while a customer comes (`'Y'`) → penalty +1  
> - If the shop is **open** while no customer comes (`'N'`) → penalty +1  
>
> Your goal is to find the **closing hour with the minimum total penalty**.

So the real question is:
> 👉 **At which hour should I close the shop to minimize total penalty?**

---

## 🎯 What you want to do (high-level goal / why)  
> - Start by assuming the shop closes at hour `0`.
> - Compute the penalty for this initial state.
> - Move the closing hour step by step from left to right.
> - Update the penalty incrementally instead of recomputing it from scratch.
> - Track the hour where the penalty becomes minimum.

Why incremental?
> Because each step only changes the penalty by **±1**, so we can do this in linear time.

---

## 🧠 Why this works  
> - Closing at hour `0` means **all `'Y'` customers are missed** → penalty = count of `'Y'`.
> - Moving closing time forward by one hour:
>   - If `s[i] == 'Y'`, that customer is now served → penalty decreases by 1.
>   - If `s[i] == 'N'`, the shop stays open unnecessarily → penalty increases by 1.
> - This gives a clean way to update penalty in `O(1)` per step.
> - Scanning once guarantees we find the minimum penalty hour.

This is a classic **prefix-greedy / running-cost** pattern.

---

## 🔧 Approach (matching the implementation)

### 1) Initial penalty (closing at hour 0)  
> - Count how many `'Y'` characters are in the string.
> - This is the penalty if the shop closes immediately.

---

### 2) Track best answer  
> - `bestCost` → minimum penalty seen so far  
> - `bestHour` → hour at which this minimum occurs

---

### 3) Slide the closing hour  
For each hour `i`:
> - If `s[i] == 'Y'`  
>   → customer is now served → `cost--`
>
> - If `s[i] == 'N'`  
>   → shop open without customers → `cost++`
>
> - If current `cost` is smaller than `bestCost`, update:
bestCost = cost
bestHour = i + 1

yaml
Copy code

---

### 4) Return the best closing hour  
> After scanning all hours, return `bestHour`.

---

## 🔍 What each variable contributes

### `cost`  
> Current penalty for the chosen closing hour.

### `bestCost`  
> Minimum penalty seen so far.

### `bestHour`  
> Hour corresponding to the minimum penalty.

---

## 🧪 Dry Run (small example)

Input:
s = "YYNY"

makefile
Copy code

Initial:
close at 0 → penalty = 3 ('Y','Y','Y')
bestCost = 3, bestHour = 0

csharp
Copy code

Step-by-step:
- hour 1 (`Y`) → cost = 2 → bestHour = 1  
- hour 2 (`Y`) → cost = 1 → bestHour = 2  
- hour 3 (`N`) → cost = 2  
- hour 4 (`Y`) → cost = 1  

Minimum penalty = 1 at hour **2**

---

## 📊 Complexity

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(1)`

---

## 💻 Code

```cpp
class Solution {
public:
    int bestClosingTime(string s) {

        int cost = 0;
        // initial penalty if shop closes at hour 0
        for (char ch : s) {
            if (ch == 'Y') cost++;
        }

        int bestCost = cost;
        int bestHour = 0;

        // simulate closing hour from 1 to n
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'Y') {
                cost--;     // customer served before closing
            } else {
                cost++;     // customer missed after closing
            }

            if (cost < bestCost) {
                bestCost = cost;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
