# ✨ Minimum Subarray Removal to Make Sum Divisible by p — Explanation & Code ✨

> **Classic prefix-sum modulo trick — elegant, fast, and avoids brute force completely.**

---

## 🎯 **Intuition**

> We want to remove the **smallest subarray** such that the **remaining sum** of the array is divisible by `p`.  
>
> Let the total sum be `S`. If `S % p == 0`, nothing needs to be removed → answer is 0.  
>
> Otherwise, suppose `S % p = req`.  
> We must remove a subarray whose sum is also congruent to **req modulo p**, because:
>
> - remaining_sum = S – removed_sum  
> - (S – removed_sum) % p = 0  
> → removed_sum % p = S % p = req  

---

## 🎯 **What I want to do (high-level goal)**

> - Compute `req = totalSum % p`.  
> - Find the **shortest subarray** whose sum modulo `p` equals this same `req`.  
> - Use prefix modulo + hashmap to locate such subarrays in `O(n)` time.  
> - Track the minimal length.

---

## 🧠 **Why this works**

> Using prefix sums:  
>  
> Let `pref[i] = (sum of nums[0..i] % p)`  
>
> A subarray `l..r` has sum:  
> `sub = pref[r] – pref[l-1]`  
>  
> We want:  
> `(pref[r] – pref[l-1]) % p = req`  
>
> Rearranged:  
> `pref[l-1] % p = (pref[r] – req + p) % p`  
>
> Meaning →  
> If current prefix modulo is `running`,  
> we need an earlier prefix modulo equal to:  
> `want = (running – req + p) % p`  
>
> So for each position, we check if that `want` value appeared before;  
> if yes, we can remove subarray between those indices.

---

## 🔧 **Approach (step-by-step)**

> 1. Compute `sum`, get `required = sum % p`.  
> 2. If `required == 0`, return 0.  
> 3. Maintain a map `seen` → `{prefixMod : index}`.  
> 4. Initialize with `{0 : -1}` to handle subarrays starting at index 0.  
> 5. Loop over array:  
>    - Update running prefix modulo.  
>    - Compute needed value `want = (running - required + p) % p`.  
>    - If `want` exists in map → update best subarray length.  
>    - Store/update current prefix modulo in map.  
> 6. If best equals full length, return -1, else return best.

---

## 🔍 **Dry Run Example (conceptual)**

> nums = [3,1,4,2], p = 6  
> sum = 10 → required = 4  
>
> As you scan, prefix mods appear like: 3, 4, 2, 4  
> When running = 2, want = (2 - 4 + 6) % 6 = 4 → prefix 4 was seen at index 1  
> → candidate subarray (2..2) length = 1  
>
> Best = 1.

---

## 📊 **Complexity**

> - **Time Complexity:** `O(n)` — one pass, hash lookups  
> - **Space Complexity:** `O(n)` — hashmap storing prefix modulo indices

---

## 💻 **Code**

```java
class Solution {
    public int minSubarray(int[] nums, int p) {

        // Step 1: Compute total sum of the array
        long sum = 0;
        for (int v : nums) sum += v;

        // Step 2: Find remainder when total sum is divided by p
        // This is the value we need to "remove" from the array
        long required = sum % p;

        // If already divisible by p, no need to remove anything
        if (required == 0) return 0;

        // Step 3: Use a HashMap to store:
        // key   -> prefix sum modulo p
        // value -> index where this modulo was first seen
        Map<Integer, Integer> seen = new HashMap<>();

        // Initialize with prefix sum 0 at index -1
        // This helps handle subarrays starting from index 0
        seen.put(0, -1);

        long running = 0;          // running prefix sum modulo p
        int best = nums.length;    // stores minimum length of subarray

        // Step 4: Traverse the array
        for (int i = 0; i < nums.length; i++) {

            // Update running prefix modulo
            running = (running + nums[i]) % p;

            /*
             We want to find a previous prefix such that:
             
             (current_prefix - previous_prefix) % p == required

             Rearranging:
             previous_prefix % p == (current_prefix - required + p) % p

             This is the value we are searching for in the map
            */
            int want = (int)((running - required + p) % p);

            // If such a prefix exists, we found a valid subarray
            if (seen.containsKey(want)) {
                // Calculate its length and update minimum
                best = Math.min(best, i - seen.get(want));
            }

            // Store current prefix modulo with index
            // NOTE: We overwrite to keep the latest index
            // (this helps minimize subarray length)
            seen.put((int)running, i);
        }

        // If we never found a valid subarray, return -1
        return best == nums.length ? -1 : best;
    }
}
