# 😏 Only **four divisors**? That’s oddly specific… let’s count them cleanly 😌✨  
*(No overthinking, no fancy math — just precise divisor counting)*

---

## 🎯 Problem Name  
**Sum of Numbers With Exactly Four Divisors**

---

## 🎯 Intuition — what you want to do  
> You are given an integer array `nums`.  
>  
> For **each number**:
> - Find **all its positive divisors**
> - If it has **exactly 4 divisors**, add the **sum of those divisors** to the final answer
>
> Return the total sum across all valid numbers.

Key observation:
> 👉 Most numbers **do NOT** have exactly 4 divisors.

---

## 🎯 What you want to do (high-level goal / why)  
> - For each number, enumerate its divisors efficiently.
> - Stop early if divisor count exceeds 4.
> - Only when divisor count is **exactly 4**, add the divisor sum.

Why brute force works here:
> - Constraints are small enough.
> - Checking divisors up to `√num` is efficient.

---

## 🧠 Why this works  
> - Divisors come in **pairs**: `(i, num / i)`
> - Iterating only till `i * i ≤ num` ensures:
>   - No duplicate work
>   - Fast enumeration
> - Early break saves time when divisors exceed 4

This avoids unnecessary checks and keeps the solution clean.

---

## 🔧 Approach (matching your implementation)

### 1) Loop through each number  
> Process each number independently.

---

### 2) Enumerate divisors up to √num  
For each `i` from `1` to `√num`:
- If `i` divides `num`:
  - Count divisor `i`
  - Count divisor `num / i` (if different)
  - Add both to sum

---

### 3) Early stopping  
> If divisor count exceeds `4`, break immediately.

---

### 4) Check condition  
> Only if `divisorCount == 4`, add `divisorSum` to answer.

---

## 🔍 What each variable contributes

### `divisorCount`
> Tracks how many divisors the current number has.

### `divisorSum`
> Sum of all divisors found so far.

### `answer`
> Final accumulated result across all valid numbers.

---

## 🧪 Dry Run (example)

Input:
nums = [21, 4, 7]

markdown
Copy code

- `21 → divisors = {1, 3, 7, 21}` ✔  
  sum = 32 → added
- `4 → divisors = {1, 2, 4}` ✘  
- `7 → divisors = {1, 7}` ✘  

Final Answer:
32

yaml
Copy code

---

## 📊 Complexity

> - **Time Complexity:**  
>   `O(n * √m)`  
>   where `m` is the max number in `nums`
>
> - **Space Complexity:**  
>   `O(1)`  
>   (constant extra space)

Efficient enough without any heavy math tricks.

---

## 💻 Code

```java
class Solution {
    public int sumFourDivisors(int[] nums) {
        int answer = 0;

        for (int num : nums) {
            int divisorCount = 0;
            int divisorSum = 0;

            // check all possible divisors up to sqrt(num)
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    int d1 = i;
                    int d2 = num / i;

                    divisorCount++;
                    divisorSum += d1;

                    if (d1 != d2) {
                        divisorCount++;
                        divisorSum += d2;
                    }

                    if (divisorCount > 4) break;
                }
            }

            if (divisorCount == 4) {
                answer += divisorSum;
            }
        }

        return answer;
    }
}
