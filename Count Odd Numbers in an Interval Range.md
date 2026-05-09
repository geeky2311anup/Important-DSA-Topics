# 🤔 Am I the only one who solved **Count Odd Numbers in an Interval Range** in one line of math? 😌✨  
*(While others loop… we just divide 😎)*

---

## 🎯 Intuition — what you want to do  
You want to find how many **odd numbers** lie in the inclusive interval:

\[
[\,\text{low},\ \text{high}\,]
\]

Most people try to loop, check each number, or write complicated conditions —  
but **you realized a beautiful mathematical shortcut**:

### Count of odd numbers from `0` to `x` is simply:
\[
\frac{x+1}{2}
\]

Why?  
Because every second number is odd:  
`1, 3, 5, 7, ...`

So the number of odds in a range becomes:

\[
\text{oddsUpToHigh} - \text{oddsBeforeLow}
\]

Elegant. Minimal. Perfect.

---

## 🎯 What you want to do (high-level goal / why)
> Instead of iterating from `low` to `high`,  
> compute odds up to `high` and subtract odds before `low`.

This turns an O(n) loop into **O(1)** pure math.

---

## 🧠 Why this works  
### Number of odd integers from 0 to x:
- If x = 0 → 0 odds  
- If x = 1 → 1 odd  
- If x = 2 → 1 odd  
- If x = 3 → 2 odds  
- If x = 4 → 2 odds  
- Pattern:  
\[
\text{oddsUpToX} = \frac{x+1}{2}
\]

Now to count odds in `[low, high]`:

\[
\text{odds} = \text{oddsUpToHigh} - \text{oddsUpTo(low-1)}
\]

Which simplifies to what your code computes.

And using bit shifting `>> 1` instead of `/2` is just a **faster divide by 2**.

---

## 🔧 Approach (matching your implementation)

1. Compute odds from 0 to `high`:
```java
int oddsUpToHigh = (high + 1) >> 1;
Compute odds from 0 to low - 1:

java
Copy code
int oddsBeforeLow = low >> 1;
Subtract to get final answer:

java
Copy code
return oddsUpToHigh - oddsBeforeLow;
🧪 Dry Run
Input:

ini
Copy code
low = 3, high = 9
Odds up to 9 → (9 + 1)/2 = 5 (1,3,5,7,9)
Odds before 3 → 3/2 = 1 (only 1)

Answer → 5 - 1 = 4

Matches odds: 3,5,7,9

📊 Complexity
Time: O(1)

Space: O(1)

Fastest possible.

💻 Code
java
Copy code
class Solution {
    public int countOdds(int low, int high) {

        // Count of odd numbers from 1 to high
        // Example: high = 7 → odds are 1,3,5,7 → total = 4
        int oddsUpToHigh = (high + 1) >> 1;

        // Count of odd numbers before low
        // Example: low = 3 → numbers before 3 are 1,2 → only 1 odd
        int oddsBeforeLow = low >> 1;

        // Subtract to get odd numbers in range [low, high]
        return oddsUpToHigh - oddsBeforeLow;
    }
}
