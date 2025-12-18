# 🤔 Am I the only one who solved **Maximum Profit with Strategy Adjustment** in such a simple way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given:
> - `prices[i]` → price on day `i`
> - `strategy[i]` → current strategy multiplier for that day
> - `k` → length of a contiguous segment where strategy can be **changed**
>
> Initially, your profit is:
> ```
> sum(strategy[i] * prices[i])
> ```
>
> You are allowed to **modify the strategy** on **one contiguous subarray of length `k`**:
> - In the **first half** of the window, strategy becomes `0`
> - In the **second half**, strategy becomes `1`
>
> Your goal is to **maximize total profit** after applying this change optimally.

---

## 🎯 What you want to do (high-level goal / why)  
> - First compute the profit with the original strategy.
> - Then, try all possible subarrays of length `k`.
> - For each window:
>   - Remove the old contribution from the strategy.
>   - Add the new contribution after applying the forced strategy.
> - Track the **maximum possible increase**.
>
> Finally:
> ```
> answer = initialProfit + max(0, bestIncrease)
> ```

This turns the problem into a **sliding window optimization** problem.

---

## 🧠 Why this works  
> - The strategy change is **fixed** once the window is chosen.
> - The effect of the change is purely arithmetic:
>   - Old value = `sum(strategy[i] * prices[i])`
>   - New value = `sum(prices[i])` for the second half only
> - Prefix sums allow us to compute both values in `O(1)` per window.
> - Since only one window is allowed, we just take the maximum gain.

---

## 🔧 Approach (matching the implementation)

### 1) Compute initial profit  
> Sum all `strategy[i] * prices[i]`.

---

### 2) Build prefix sums  
> - `pricePref[i]` → sum of prices up to index `i`
> - `weightedPref[i]` → sum of `strategy[i] * prices[i]` up to index `i`

These allow fast range queries.

---

### 3) Slide a window of size `k`  
For each starting index `left`:

- **Old contribution**:
