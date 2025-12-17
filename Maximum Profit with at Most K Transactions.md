# 🤔 Am I the only one who solved **Maximum Profit with at Most K Transactions** in such a simple way? 😌✨

---

## 🎯 Intuition — what you want to do  
> You are given an array `prices`, where `prices[i]` is the stock price on day `i`, and an integer `k` representing the **maximum number of transactions** allowed.  
>  
> One transaction = **one buy + one sell**.  
>  
> Your goal is to compute the **maximum profit** you can achieve using **at most `k` transactions**.

Instead of using a big 2D DP table, you compress everything into a **state-based DP** that tracks profit changes smartly.

---

## 🎯 What you want to do (high-level goal / why)  
> - For each transaction count `t (1..k)`, track:
>   - the best profit achieved so far  
>   - the best value if we are currently holding a stock  
>   - the best value if we are currently free (just sold or not holding)  
> - Update these states day by day while iterating through prices.  
>
> This avoids recomputation and keeps the solution efficient even for large `k`.

---

## 🧠 Why this works  
> - At any day and any transaction count, your situation can be summarized using **three values**:
>   - `best`: maximum profit so far  
>   - `hold`: best possible value after buying a stock  
>   - `free`: best possible value after selling a stock  
> - Each new price either improves an existing state or keeps the previous best.  
> - By updating transaction counts **backwards**, you avoid overwriting needed states.

This compresses classic DP into a clean and fast state machine.

---

## 🔧 Approach (matching the implementation)

### 1) State definition  
Each `State` object stores:
- `best` → max profit achieved so far  
- `hold` → best value if you are holding a stock  
- `free` → best value if you are not holding a stock  

---

### 2) Initialization  
> On day 0:
> - Buying once costs `prices[0]`
> - Initialize all transaction states using the first price

```java
dp[i] = new State(0, -firstPrice, firstPrice);
3) DP transition (day by day)
For every price and for every transaction count t (from k down to 1):

best can be updated by:

keeping old best

selling from hold

buying again after being free

hold can be updated by:

keeping old hold

buying today using previous transaction profit

free can be updated by:

keeping old free

selling today using previous transaction profit

4) Final answer
The maximum profit using at most k transactions is stored in:

java
Copy code
dp[k].best
🔍 What each state contributes
best
Represents the maximum achievable profit till the current day with t transactions.

hold
Represents the best value if you are holding a stock after buying.

free
Represents the best value if you are not holding any stock (after selling).

These three together fully describe your situation at any time.

🧪 Dry Run (small example)
Input:

ini
Copy code
prices = [3, 2, 6, 5, 0, 3]
k = 2
Possible transactions:

Buy at 2, sell at 6 → profit = 4

Buy at 0, sell at 3 → profit = 3

Total profit = 7

The DP states evolve to capture exactly this behavior.

📊 Complexity
Time Complexity: O(n * k) — each day updates k transaction states

Space Complexity: O(k) — only k+1 states stored

💻 Code
java
Copy code
class State {
    long best;     // maximum profit till now
    long hold;     // best value after buying
    long free;     // best value after selling

    State(long best, long hold, long free) {
        this.best = best;
        this.hold = hold;
        this.free = free;
    }
}

class Solution {
    public static long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        int firstPrice = prices[0];

        State[] dp = new State[k + 1];
        for (int i = 0; i <= k; i++) {
            dp[i] = new State(0, -firstPrice, firstPrice);
        }

        for (int i = 1; i < n; i++) {
            int price = prices[i];
            for (int t = k; t >= 1; t--) {
                State curr = dp[t];
                long prevProfit = dp[t - 1].best;

                curr.best = Math.max(
                    curr.best,
                    Math.max(curr.hold + price, curr.free - price)
                );

                curr.hold = Math.max(curr.hold, prevProfit - price);
                curr.free = Math.max(curr.free, prevProfit + price);
            }
        }
        return dp[k].best;
    }
}
