# 🤔 Am I the only one who solved **Largest Prime ≤ N** without generating primes every time? 😌✨

---

## 🧩 Problem Name  
**Largest Prime Less Than or Equal to Given Number**

---

## 🎯 Intuition — what you want to do  
> You are given a number `limit`.  
>  
> You need to return the **largest prime number that is ≤ limit**.
>
> The twist here is:
> - You are **not** asked to generate primes
> - You already have a **precomputed list of primes**
>
> So the real task becomes:
> 👉 **Find the rightmost prime in a sorted array that is ≤ limit**

That immediately screams: **Binary Search**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Use the given sorted array of primes.
> - Search for the **largest value ≤ limit**.
> - Avoid expensive prime generation or checking.
> - Return the answer in `O(log n)` time.

Why binary search?
> Because the prime list is **sorted** and static.

---

## 🧠 Why this works  
> - The prime array is strictly increasing.
> - For any index:
>   - If `PRIMES[mid] ≤ limit`, all primes to the **left** are also valid.
>   - If `PRIMES[mid] > limit`, all primes to the **right** are invalid.
> - This creates a **monotonic condition**, perfect for binary search.
>
> You simply keep pushing right while the prime is valid.

---

## 🔧 Approach (matching the implementation)

### 1) Pre-store prime numbers  
> The array `PRIMES[]` contains precomputed prime numbers in ascending order.

This avoids:
- Sieve of Eratosthenes
- Repeated primality checks

---

### 2) Binary search on the prime array  
> Maintain:
> - `left = 0`
> - `right = PRIMES.length - 1`
> - `answer = 0`

At each step:
> - If `PRIMES[mid] ≤ limit`  
>   → store it as a candidate and move right  
> - Else  
>   → move left

---

### 3) Return the best valid candidate  
> `answer` always stores the **largest prime seen so far** that fits.

---

## 🔍 What each variable contributes

### `PRIMES`
> Precomputed sorted list of prime numbers.

### `left`, `right`
> Standard binary search pointers.

### `mid`
> Current index being tested.

### `answer`
> Stores the best (largest valid) prime ≤ limit.

---

## 🧪 Dry Run (example)

Input:
limit = 100

yaml
Copy code

Relevant primes:
2, 5, 17, 41, ...

sql
Copy code

Binary search checks:
- 41 ≤ 100 → candidate
- 197 > 100 → move left

Final answer:
41

yaml
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(log P)`  
>   where `P` is the number of stored primes  
>
> - **Space Complexity:** `O(1)`  
>   (no extra memory used)

---

## 💻 Code

```java
class Solution {

    private static final int[] PRIMES = {
        2, 5, 17, 41, 197, 281, 7699, 8893, 22039,
        24133, 25237, 28697, 32353, 37561, 38921, 43201,
        44683, 55837, 61027, 66463, 70241, 86453,
        102001, 109147, 116533, 119069, 121631, 129419,
        132059, 263171, 287137, 325019, 329401, 333821,
        338279, 342761, 360979, 379667, 393961, 398771
    };

    public int largestPrime(int limit) {

        int left = 0, right = PRIMES.length - 1;
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (PRIMES[mid] <= limit) {
                answer = PRIMES[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
}
