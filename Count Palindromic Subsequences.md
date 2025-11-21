# ✨ Count Palindromic Subsequences (Length 3) — Explanation & Code ✨


---

## 🎯 **Intuition**

> We want to count all **unique palindromic subsequences of length 3** of the form  
> **a _ b a**, where the first and last characters are the same, and the middle character can be anything.  
>  
> The key idea is simple:  
> - For each character `'a'` to `'z'`, find **its first occurrence** and **its last occurrence** in the string.  
> - All valid palindromes for that character must have their middle character **between these two positions**.  
> - Count **distinct** middle characters in that range → each distinct middle char gives **one unique palindrome**.

---

## 🎯 **What I want to do (high-level goal)**

> - Track **first** and **last** positions of each letter.  
> - For each letter `c`, if it appears at least twice, scan the substring between its first and last occurrence.  
> - Count how many **distinct** letters appear in the middle → each corresponds to one palindrome like `c?c`.  
> - Accumulate this across all 26 letters.

---

## 🧠 **Why this works**

> - A palindrome of length 3 is uniquely determined by:  
>   - Its **first/last** character (same)  
>   - Its **middle** character  
> - If a letter appears at positions `l` and `r` (`l < r`), then **any distinct character** inside `(l, r)` produces **exactly one distinct palindrome**.  
> - Using a **bitmask** allows us to record distinct middle characters efficiently (`1 << midIdx`), and `Integer.bitCount(mask)` quickly counts them.  
> - We do this for all 26 lowercase letters → total number of unique palindromic subsequences.

---

## 🔧 **Approach (step-by-step)**

> 1. Convert `s` to a character array `arr`.  
> 2. Maintain two arrays `leftMost[26]` and `rightMost[26]` to store the **first** and **last** occurrence of every character.  
> 3. Traverse `s` once:  
>    - The first time a character appears → record its leftmost index.  
>    - Always update its rightmost index.  
> 4. For every character `c` from `'a'` to `'z'`:  
>    - If it appears at least twice (`l < r`), consider the substring `(l, r)`.  
>    - Use a **bitmask** to collect all **distinct** characters appearing in this middle region.  
>    - `bitcount(mask)` gives number of unique palindromes of the form `c?c`.  
> 5. Sum answers for all 26 characters and return it.

---

## 🔍 **Dry Run Example**

> s = `"aabca"`  
>  
> leftMost: a→0  
> rightMost: a→4  
>  
> Middle section = `"abc"` → distinct = {a, b, c}  
>  
> Palindromes:  
> - `"aaa"`  
> - `"aba"`  
> - `"aca"`  
>  
> So answer includes 3 from character `'a'`.  
>  
> Repeat similar logic for `'b'`, `'c'`, etc.

---

## 📊 **Complexity**

> - **Time Complexity:**  
>   - O(n + 26 + n) → effectively **O(n)**  
>   - Scanning each character between its left and right boundary is linear, but each index is scanned at most once overall.  
>  
> - **Space Complexity:** `O(1)`  
>   - Only constant arrays of size 26 and a few integers.

---

## 💻 **Code**

```java
import java.util.*;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();

        int[] leftMost = new int[26];
        int[] rightMost = new int[26];
        Arrays.fill(leftMost, -1);
        Arrays.fill(rightMost, -1);

        // Record first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int idx = arr[i] - 'a';
            if (leftMost[idx] == -1) {
                leftMost[idx] = i;
            }
            rightMost[idx] = i;
        }

        int count = 0;

        // For each character as the first and last char of palindrome
        for (int c = 0; c < 26; c++) {
            int l = leftMost[c];
            int r = rightMost[c];

            if (l != -1 && l < r) {
                int mask = 0;
                // Collect all distinct middle characters between l and r
                for (int mid = l + 1; mid < r; mid++) {
                    int midIdx = arr[mid] - 'a';
                    mask |= (1 << midIdx);
                }
                // Number of set bits = number of distinct middle chars
                count += Integer.bitCount(mask);
            }
        }

        return count;
    }
}
