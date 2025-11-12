problem Link -> https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/solutions/?envType=daily-question&envId=2025-11-12
# Intuition
When trying to make all array elements equal to 1 using the operation  
`nums[i] = gcd(nums[i], nums[j])`, the key observation is that once we have **at least one `1`**,  
it can be used to turn every other element into `1` in one step.  

If no element is initially `1`, we must find the **smallest subarray whose GCD equals 1**,  
because that subarray represents the minimum number of operations required to produce the first `1`.

---

# Approach

### 1. Count existing 1s
- Traverse the array and count how many elements are already `1`.
- If there are `count` ones, each remaining `(n - count)` element can be made `1` in one step.
- **Total operations** in this case = `n - count`.

---

### 2. Find the smallest subarray with GCD = 1
- If no element is `1`, we need to create one.
- For every starting index `i`, compute GCDs with the next elements until it becomes `1`.
- Keep track of the minimum subarray length `(j - i)` where `gcd(nums[i..j]) == 1`.

---

### 3. Calculate total operations
Once we find such a subarray of length `L = (j - i + 1)`:
- It takes `(L - 1)` operations to make one element become `1`.
- Then, it takes `(n - 1)` more operations to make the entire array equal to 1.
- **Total operations** = `(L - 1) + (n - 1)` = `L + n - 2`.

In code, since `minm` is stored as `(j - i)`,  
we compute the result as `minm + n - 1`.

---

### 4. Handle impossible case
- If no subarray produces GCD = 1, it’s impossible to make all elements `1`.
- Return `-1`.

---

# Dry Run

**Example:**  
`nums = [2, 6, 3, 4]`

| Step | i | j | Subarray | GCD | Action |
|------|---|---|-----------|-----|--------|
| 1 | 0 | 0 | [2] | 2 | Continue |
| 2 | 0 | 1 | [2, 6] | 2 | Continue |
| 3 | 0 | 2 | [2, 6, 3] | 1 | ✅ Found subarray (0,2) → minm = 2 |

No smaller subarray gives GCD = 1.  

Now, `n = 4`, `minm = 2`,  
**Total operations** = `minm + n - 1 = 2 + 4 - 1 = 5`.

✅ **Output:** 5

---

# Complexity
- **Time Complexity:** `O(n² × log(max(nums[i])))`  
  Each pair of indices involves a GCD operation that takes logarithmic time.
- **Space Complexity:** `O(1)`  
  Only a few integer variables are used.

---

# Code
```java
class Solution {
    public int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int minOperations(int[] nums) {
        int n = nums.length;
        int minm = Integer.MAX_VALUE;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int value = nums[i];
            if (nums[i] == 1) {
                count++;
            }

            for (int j = i; j < n; j++) {
                value = gcd(value, nums[j]);
                if (value == 1) {
                    minm = Math.min(minm, j - i);
                    break;
                }
            }
        }

        if (minm == Integer.MAX_VALUE) {
            return -1;
        } else {
            if (count > 0) {
                return n - count;
            } else {
                return minm + n - 1;
            }
        }
    }
}
