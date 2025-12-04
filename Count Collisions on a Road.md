
*(Collision counting made easy)*

---

## 🎯 Intuition — what you want to do  
> Instead of simulating cars or thinking too much about physics,  
> you realized **collisions only happen in the “middle segment”**.  
>
> Why?  
> - A car moving **left (`L`) at the very beginning** will NEVER collide — nothing is before it.  
> - A car moving **right (`R`) at the very end** will NEVER collide — nothing after it.  
>
> Everything **between** these two boundaries **must** eventually collide **unless it is already standing (`S`)**.

Brilliant. Minimal thinking. Maximum effect. 💥😄

---

## 🎯 What you want to do (high-level goal / why)
> - Trim all leading `L` cars — they drive out of the road harmlessly.  
> - Trim all trailing `R` cars — they drive out harmlessly.  
> - Now look at the remaining middle zone:  
>   - Every character that is **not `S`** (`L` or `R`) will collide for sure.  
>
> So collisions = count of all `L` and `R` inside the trimmed middle segment.

That’s it. Zero simulation. Zero stack. Zero complexity headaches.

---

## 🧠 Why this works  
> - Cars starting with `L` on the left edge move away — no collision.  
> - Cars ending with `R` on the right edge move away — no collision.  
> - Once we remove both ends, any remaining:  
>   - `L` crashes into something on its left,  
>   - `R` crashes into something on its right.  
> - Only `S` cars inside the middle do not create collisions.

Thus:  
**Collisions = count of non-`S` characters in the middle region.**  

Elegant. Precise. Fast.

---

## 🔧 Approach (matching your implementation)

### **1. Find first non-safe index from the left**
Skip all `L`:
```java
while (i < n && directions.charAt(i) == 'L') i++;
2. Find first non-safe index from the right
Skip all R:

java
Copy code
while (j >= 0 && directions.charAt(j) == 'R') j--;
3. Count collisions in the middle
Every L or R here must collide:

java
Copy code
if (i <= j) count characters != 'S'
4. Return count
🧪 Dry Run
Input: "LLRSRRL"

Leading L → trim
Trailing R → trim

Middle portion becomes: "RSRR"
Non-S count = 4 → all will collide.

📊 Complexity
Time Complexity: O(n)

Space Complexity: O(1)

Ultra-efficient.

💻 Code
java
Copy code
class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        int i = 0;
        int j = n - 1;
        
        // skip harmless starting L's
        while (i < n && directions.charAt(i) == 'L') {
            i++;
        }
        
        // skip harmless ending R's
        while (j >= 0 && directions.charAt(j) == 'R') {
            j--;
        }
        
        int count = 0;
        
        // every non-S inside middle will collide
        if (i <= j) {
            for (int k = i; k <= j; k++) {
                if (directions.charAt(k) != 'S') {
                    count++;
                }
            }
        }
        
        return count;
    }
}
