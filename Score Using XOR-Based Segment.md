# Maximum Score Using XOR-Based Segment Chaining

## Problem Summary

You are given an array of integers for each test case.

Your goal is to compute the **maximum possible score** by selecting elements such that:
- You can start at any index
- From index `i`, you may jump forward to another index `j`
- A jump from `i` to `j` is allowed if the XOR of the subarray `a[i..j]` is `0`
- The score is the sum of selected elements along the chosen chain

You must compute the maximum achievable score.

---

## Key Observation

If the XOR of a subarray is zero, then:
- The prefix XOR before the subarray equals the prefix XOR after it

This allows us to:
- Use **suffix XOR**
- Track where the same XOR value appears again
- Jump between valid segment boundaries

---

## Core Idea

1. Traverse the array from right to left
2. Maintain a map of:
   
   XOR value → earliest index where it appears

3. For each index `i`:
   - Compute the suffix XOR starting at `i`
   - If this XOR was seen before, we can jump to the previous position minus one
4. Use Dynamic Programming to compute the best score starting from each index

---

## Data Structures Used

- `unordered_map` to track last occurrence of XOR values
- `nextIndex[i]` to store where we can jump from `i`
- `best[i]` to store maximum score starting at index `i`

---

## Algorithm Steps

### Step 1: Build jump links
- Traverse from right to left
- Compute suffix XOR
- If the same XOR appears again, record a jump

### Step 2: Dynamic Programming
- For each index `i`:
  - Start with `a[i]`
  - If a valid jump exists, add the score from the jump destination
- Track the maximum score globally

---

## C++ Implementation

(Indented to stay safely inside the markdown block)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void processCase() {
    int n;
    cin >> n;

    // Read the array
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Map to store last occurrence of each suffix XOR value
    // key = suffix XOR value
    // value = index where this suffix XOR was last seen
    unordered_map<ll, int> lastPos;
    lastPos.reserve(n * 2);

    // nextIndex[i] will store the next position
    // where the same suffix XOR occurs
    vector<int> nextIndex(n, -1);

    ll suffixXor = 0;

    // Base case:
    // suffix XOR = 0 at imaginary index n
    lastPos[0] = n;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Update suffix XOR
        suffixXor ^= a[i];

        // If this suffix XOR was seen before
        // store the next index
        if (lastPos.count(suffixXor)) {
            nextIndex[i] = lastPos[suffixXor] - 1;
        }

        // Update last occurrence of this suffix XOR
        lastPos[suffixXor] = i;
    }

    // best[i] stores the best value starting from index i
    vector<ll> best(n, 0);
    ll answer = 0;

    // Compute best values from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Start with the value at current index
        best[i] = a[i];

        // If there is a valid next segment
        // add its best value
        if (nextIndex[i] != -1) {
            best[i] += best[nextIndex[i]];
        }

        // Update global answer
        answer = max(answer, best[i]);
    }

    // Output final result
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Process each test case
    while (t--) {
        processCase();
    }
    return 0;
}

---

## Complexity Analysis

Let `n` be the array size.

Time Complexity:
O(n) per test case

Each index is processed a constant number of times.

Space Complexity:
O(n)

For maps, jump array, and DP array.

---

## Final Thought

This solution works because:
- XOR patterns repeat predictably
- Repeated XOR means a zero-XOR segment exists
- Dynamic Programming turns valid jumps into maximum score paths

It’s not magic.
It’s just XOR remembering where it has been before.
And DP making the best possible choice every time.
