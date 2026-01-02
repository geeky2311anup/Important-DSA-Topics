# 🤯 Was this really a problem… or just a formality? 😌  
## 🤔 Am I the only one who solved **Repeated N Times** in one clean pass?  

---

<br>

# 🎉🎉🎉 **HAPPY NEW YEAR 2026** 🎉🎉🎉  
## 🥳✨ MAY YOUR BUGS BE FEWER AND YOUR ACs BE MANY ✨🥳  

---

## 🎯 Intuition — what you want to do  
> You are given an array `nums` of size `2N`.  
>  
> Exactly **one element is repeated N times**, while all other elements appear **once**.  
>  
> Your task is simply to **find that repeated element**.

No tricks.  
No math.  
No DP.  
No overthinking.

Just find **the first number that appears twice**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the array once.  
> - Keep track of elements you’ve already seen.  
> - The moment you see a number **again**, return it immediately.

Why this works:
> Because the repeated element appears **many times**, it is guaranteed to be the **first duplicate encountered** during a linear scan.

---

## 🧠 Why this works  
> - A `HashSet` gives **O(1)** average lookup time.  
> - As soon as a number repeats, it must be the answer.  
> - No need to scan the whole array after that.

This is the **cleanest possible solution**.

---

## 🔧 Approach (matching your implementation)

### 1) Create a `HashSet`
> Used to remember numbers seen so far.

---

### 2) Traverse the array  
> For each number:
> - If it already exists in the set → **return it immediately**  
> - Otherwise, add it to the set

---

### 3) Safety return  
> A fallback `-1` is added (won’t be reached as per problem constraints).

---

## 🔍 What each part contributes

### `HashSet<Integer> seen`
> Stores all unique numbers encountered so far.

### `seen.contains(nums[i])`
> Detects repetition instantly.

### Early return
> Stops execution the moment the answer is found (optimal).

---

## 🧪 Dry Run (simple example)

Input:
nums = [5, 1, 5, 2, 5, 3, 5, 4]

yaml
Copy code

Steps:
- see `5` → add  
- see `1` → add  
- see `5` → already present ✅ return `5`

Done. No drama.

---

## 📊 Complexity

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(n)`  

(And yes, this is already optimal.)

---

## 💻 Code

```java
class Solution {
    public int repeatedNTimes(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if (seen.contains(nums[i])) {
                return nums[i];   // repeated element found
            }
            seen.add(nums[i]);
        }

        return -1; // safety (won’t happen as per problem)
    }
}
