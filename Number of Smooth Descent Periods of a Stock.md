# 😌 Is it just me, or does this problem look harder than it actually is?

### (Problem: **Number of Smooth Descent Periods of a Stock**)

---

## 🎯 Intuition — what you want to do  
> You are given an array `prices`, where `prices[i]` represents the stock price on day `i`.  
>  
> A **smooth descent period** is a contiguous subarray where:
> - For every consecutive day, the price decreases by **exactly 1**.
> - A single day by itself is also considered a valid descent period.
>
> Your goal is to count **all possible smooth descent periods**.

So instead of checking all subarrays (which would be slow), we just need to **track descending streaks**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the array once.  
> - Keep track of how long the current “−1 descending streak” is.  
> - At each index, add the current streak length to the answer.  
>  
> Why does this work?  
> Because if a streak has length `k`, then it contributes **k descent subarrays ending at this index**.

---

## 🧠 Why this works  
> - Every element alone forms a valid descent period (length = 1).  
> - If `prices[i] == prices[i-1] - 1`, then:
>   - All descent periods ending at `i-1` can be extended to `i`.  
>   - Plus one new subarray `[prices[i]]`.  
> - So the number of descent periods ending at index `i` is exactly:
>   ```
>   streak length so far
>   ```
> - If the condition breaks, the streak resets to `1`.

This avoids nested loops and counts everything in **one pass**.

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Initialize variables
- `answer` → stores total number of descent periods  
- `streak` → length of current smooth descent ending at index `i`

---

### 2️⃣ Traverse the prices array
For each index `i`:

- If `i > 0` **and**  
  `prices[i] == prices[i-1] - 1`  
  → the descent continues  
  → increment `streak`

- Otherwise  
  → descent breaks  
  → reset `streak = 1`

- Add `streak` to `answer`

---

## 🔍 What each variable contributes

### `streak`
> Represents how many smooth descent subarrays **end at the current index**.

### `answer`
> Accumulates all valid descent subarrays seen so far.

At every index:
