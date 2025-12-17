## 🤔Am I the only one who solved this in such a simple way?😌✨

---

## 🎯 Intuition — what you want to do  
> You are given:
> - a **pattern string** (made of characters), and  
> - a **sentence string** `s` (made of space-separated words).  
>
> The task is to check whether `s` **follows the same pattern** as `pattern`.
>
> “Follows the same pattern” means:
> - Each character in `pattern` maps to **exactly one word**.
> - Each word maps back to **exactly one character**.
> - The mapping must be **one-to-one and consistent**.

So this is nothing but checking a **bijective mapping** between characters and words.

---

## 🎯 What you want to do (high-level goal / why)  
> - First, split the sentence into words.  
> - If the number of characters and words don’t match → impossible → return `false`.  
> - Ensure:
>   - Same character always maps to the same word.
>   - Same word always maps to the same character.
>
> To enforce this, you explicitly check the mapping in **both directions**.

That’s why **two maps** are used.

---

## 🧠 Why this works  
> - A single map (char → word) is not enough because two characters could map to the same word.  
> - A second map (word → char) ensures the mapping is **bijective**.  
> - Any inconsistency detected in either direction immediately violates the pattern.  
> - If no inconsistency exists after full traversal, the pattern is valid.

This guarantees correctness.

---

## 🔧 Approach (matching your implementation)

### 1) Pre-check length  
> - Split the sentence using spaces.  
> - If `pattern.length != number of words`, return `false`.

---

### 2) First map: `character → word`  
> - Traverse both arrays together.  
> - If the character already exists in the map:
>   - Its mapped word must equal the current word.
> - Otherwise:
>   - Store the new mapping.

Any mismatch increments `count`.

---

### 3) Second map: `word → character`  
> - Traverse again.  
> - If the word already exists in the map:
>   - Its mapped character must equal the current character.
> - Otherwise:
>   - Store the new reverse mapping.

Again, any mismatch increments `count`.

---

### 4) Final decision  
> - If `count == 0`, no conflicts were found → return `true`.  
> - Otherwise, return `false`.

---

## 🔍 What each part contributes (detailed)

### `mp1 (Map<Character, String>)`  
> Ensures that **each pattern character maps to only one word**.

### `mp2 (Map<String, Character>)`  
> Ensures that **each word maps to only one pattern character**.

### `count`  
> Acts as a conflict detector.  
> If any inconsistency appears in either direction, it increases.

### Final check  
> `count == 0` → valid pattern  
> `count > 0` → invalid pattern

---

## 🧪 Dry Run (example)

Input:
pattern = "abba"
s = "dog cat cat dog"

yaml
Copy code

Split words:
["dog", "cat", "cat", "dog"]

pgsql
Copy code

First map (char → word):
- a → dog
- b → cat
- b → cat (ok)
- a → dog (ok)

Second map (word → char):
- dog → a
- cat → b
- cat → b (ok)
- dog → a (ok)

No conflicts → `count = 0` → return `true`.

---

## 📊 Complexity

> - **Time Complexity:** `O(n)` — single traversal (done twice)  
> - **Space Complexity:** `O(n)` — maps store up to `n` mappings  

---

## 💻 Code

```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        int count = 0;
        String[] st = s.split(" ");
        char[] arr = pattern.toCharArray();
        int n = arr.length;
        int m = st.length;

        if (n != m) return false;

        Map<Character, String> mp1 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (mp1.containsKey(arr[i])) {
                if (!mp1.get(arr[i]).equals(st[i])) {
                    count++;
                }
            } else {
                mp1.put(arr[i], st[i]);
            }
        }

        Map<String, Character> mp2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (mp2.containsKey(st[i])) {
                if (mp2.get(st[i]) != arr[i]) {
                    count++;
                }
            } else {
                mp2.put(st[i], arr[i]);
            }
        }

        return count == 0;
    }
}
