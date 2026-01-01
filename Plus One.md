# 🤔 Am I the only one who solved **Plus One** this cleanly? 😌✨

---

## 🎉🎉🎉  
# 🥳✨ **HAPPY NEW YEAR 2026** ✨🥳  
## 🚀 May your code be bug-free and your logic always optimal 🚀  
## 🎯 Keep grinding, keep winning, keep growing 🎯  
## 💻💡 Cheers to more DSA, more offers, and more success 💡💻  
## 🎉🎉🎉

---

## 🧠 Problem Name  
**Plus One**

---

## 🎯 Intuition — what you want to do  
> You are given a number represented as an array of digits.  
>  
> Your task is to **add 1** to this number and return the resulting digit array.  
>
> Just like manual addition:
> - Start from the **last digit**
> - Handle **carry**
> - If everything becomes `0` (like `999 + 1`), add a new leading `1`

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse digits from right to left  
> - Keep a `carry` flag (initially `true` because we add 1)  
> - If digit is `9`, it becomes `0` and carry continues  
> - Otherwise, increment digit and stop  
> - If carry still exists after the loop → create a new array with leading `1`

This avoids converting to numbers and works for **very large inputs**.

---

## 🧠 Why this works  
> - Addition only propagates carry **until a digit < 9 is found**  
> - Worst case (`999...9`) requires a new digit  
> - Each digit is touched **at most once**

This makes the solution:
> ✅ Simple  
> ✅ Efficient  
> ✅ Clean  

---

## 🔧 Approach (matching the implementation)

### 1️⃣ Initialize carry  
> We assume we are adding `1`, so `carry = true`.

---

### 2️⃣ Traverse from the last digit  
> - If digit is `9`:  
>   - Set it to `0`, carry continues  
> - Else:  
>   - Increment digit  
>   - Stop processing

---

### 3️⃣ Handle overflow case  
> If carry is still `true` after the loop, it means:
999 → 1000

yaml
Copy code
So we create a new array with leading `1`.

---

## 🔍 What each variable contributes

### `carry`
> Indicates whether addition needs to propagate to the next digit.

### `a[]`
> Input digit array (modified in-place if possible).

### `res[]`
> New array created only in the overflow case.

---

## 🧪 Dry Run

### Example 1  
Input:
[1, 2, 3]

makefile
Copy code
Steps:
- Last digit `3 + 1 = 4`
Output:
[1, 2, 4]

yaml
Copy code

---

### Example 2  
Input:
[9, 9, 9]

markdown
Copy code
Steps:
- All digits become `0`
- Carry remains → add leading `1`
Output:
[1, 0, 0, 0]

yaml
Copy code

---

## 📊 Complexity

> - **Time Complexity:** `O(n)`  
> - **Space Complexity:** `O(1)` (or `O(n)` only in overflow case)

---

## 💻 Code

```java
class Solution {
    public int[] plusOne(int[] a) {

        boolean carry = true;

        for (int i = a.length - 1; i >= 0 && carry; i--) {
            if (a[i] == 9) {
                a[i] = 0;
            } else {
                a[i]++;
                carry = false;
            }
        }

        if (!carry) return a;

        int[] res = new int[a.length + 1];
        res[0] = 1;
        return res;
    }
}
