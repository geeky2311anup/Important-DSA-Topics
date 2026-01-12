# 🧠 Parentheses: Because Even Symbols Need Supervision  
## LeetCode 22 – Generate Parentheses

Somehow, two characters `(` and `)` still manage to mess things up without rules.
So here we are. Babysitting parentheses.

---

## 📌 Problem Statement

Given an integer `n`, generate **all valid combinations** of `n` pairs of parentheses.

Rules (non-negotiable):
- Every opening `(` must be closed
- You cannot close before you open
- Order matters, chaos is not welcome

Example:
Input: n = 3  
Output:
((()))
(()())
(())()
()(())
()()()

---

## 🧠 Key Insight

At any point while building the string:
- You can add `(` **if** you haven’t used all `n`
- You can add `)` **only if** there are more `(` than `)` so far

If you break these rules, the string becomes invalid.
And no one wants invalid parentheses. Not even computers.

---

## 🔁 Approach: Backtracking (a.k.a. Controlled Exploration)

We build the string step by step:
- Track how many `(` and `)` we have used
- Stop when the string length becomes `2 * n`
- Backtrack after every choice to explore all valid paths

This guarantees:
- No duplicates
- No invalid combinations
- Maximum emotional stability for parentheses

---

## 🧪 Time & Space Complexity

- Time Complexity: O(4^n / √n)  
  (Yes, it grows fast. Parentheses are dramatic.)
- Space Complexity: O(n) for recursion depth

---

## 💻 Java Solution

    class Solution {
        public List<String> generateParenthesis(int n) {
            List<String> result = new ArrayList<>();
            build(0, 0, n, new StringBuilder(), result);
            return result;
        }

        private void build(int open, int close, int limit,
                           StringBuilder current, List<String> result) {

            // If we've used all parentheses, store the result
            if (current.length() == limit * 2) {
                result.add(current.toString());
                return;
            }

            // Add '(' if we still can
            if (open < limit) {
                current.append('(');
                build(open + 1, close, limit, current, result);
                current.deleteCharAt(current.length() - 1); // backtrack
            }

            // Add ')' only if it won't break validity
            if (close < open) {
                current.append(')');
                build(open, close + 1, limit, current, result);
                current.deleteCharAt(current.length() - 1); // backtrack
            }
        }
    }

---

## 🧾 Summary

- This problem is about **rules + recursion**
- Backtracking ensures only valid combinations survive
- Parentheses are simple, but only if you control them strictly

Congrats. You have successfully managed brackets without losing your sanity.
That alone deserves respect.
