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

/*
    This function processes one test case.
*/
void processCase() {

    // Read size of array
    int n;
    cin >> n;

    // Input array
    vector<ll> a(n);

    // Read all elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
        lastPos map:
        Stores the LAST index where a particular suffix XOR was seen.

        Key   -> suffix XOR value
        Value -> index where that suffix XOR appears
    */
    unordered_map<ll, int> lastPos;

    // Reserve space to avoid frequent rehashing (performance optimization)
    lastPos.reserve(n * 2);

    /*
        nextIndex[i] stores the next position where the same suffix XOR
        appears again.

        If such position exists:
            nextIndex[i] = that position - 1

        Otherwise:
            nextIndex[i] = -1
    */
    vector<int> nextIndex(n, -1);

    /*
        suffixXor stores XOR of suffix elements
        while traversing array from right to left.
    */
    ll suffixXor = 0;

    /*
        Base condition:
        XOR of empty suffix is 0 at position n.
    */
    lastPos[0] = n;

    /*
        Traverse array from right to left
        to compute suffix XOR values.
    */
    for (int i = n - 1; i >= 0; i--) {

        // Update suffix XOR
        suffixXor ^= a[i];

        /*
            If we have seen this suffix XOR before,
            it means the subarray between these positions
            has XOR = 0.
        */
        if (lastPos.count(suffixXor)) {

            /*
                Store the position just before that index
                so we can connect segments later.
            */
            nextIndex[i] = lastPos[suffixXor] - 1;
        }

        // Update the last seen position of this suffix XOR
        lastPos[suffixXor] = i;
    }

    /*
        best[i] stores the best possible value
        starting from index i.
    */
    vector<ll> best(n, 0);

    // Final answer for this test case
    ll answer = 0;

    /*
        Compute DP values from right to left.
    */
    for (int i = n - 1; i >= 0; i--) {

        // Base contribution from element itself
        best[i] = a[i];

        /*
            If we found a next valid segment
            where XOR becomes zero,
            we can combine the results.
        */
        if (nextIndex[i] != -1) {

            // Add best result from that next segment
            best[i] += best[nextIndex[i]];
        }

        // Update global maximum answer
        answer = max(answer, best[i]);
    }

    // Print result for this test case
    cout << answer << "\n";
}

int main() {

    // Fast I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Number of test cases
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
