# Partition Array and Count Distinct Elements per Segment

## Problem Summary

You are given an array of integers.
The array may contain duplicate values.

Your task is to:
- Split the array into the smallest number of contiguous segments
- Ensure that each value appears in only one segment
- For each segment, count how many **distinct** values it contains
- Return the **sum** of distinct counts across all segments

This must be done efficiently for multiple test cases.

---

## Key Insight

If a value appears multiple times in the array, **all occurrences of that value must belong to the same segment**.

So:
- Any segment must extend at least to the **last occurrence** of every value it contains
- Once we reach that farthest boundary, the segment is complete

This is a greedy partitioning problem based on last positions.

---

## Preprocessing Step

We first compute the **rightmost (last) index** of every value in the array.

Why?
- This tells us how far a segment must extend if it includes a given value

Example:

Array:
1 2 1 3 2

Rightmost positions:
1 → 2  
2 → 4  
3 → 3  

---

## Segment Construction Logic

We scan the array from left to right.

For each new segment:
1. Start at index `left`
2. Set the initial boundary to the last occurrence of `arr[left]`
3. Move forward inside the segment:
   - For every element encountered, update the boundary to the maximum of:
     - current boundary
     - last occurrence of that element
4. Continue until the current index reaches the boundary

At this point:
- All elements in the segment are fully contained
- None will appear later in the array

---

## Counting Distinct Elements

While expanding a segment:
- Track all values encountered using a set
- After the segment ends, add the size of the set to the answer
- Clear the set before starting the next segment

---

## Why This Works

This guarantees:
- Each value appears in exactly one segment
- Segments are as small as possible
- Every index is processed only once

This is a greedy strategy with preprocessing.

---

## C++ Implementation

(Indented to stay inside the markdown block)

    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int testCases;
        cin >> testCases;

        while (testCases--) {
            int size;
            cin >> size;

            vector<int> arr(size);
            unordered_map<int, int> rightMost;

            for (int i = 0; i < size; i++) {
                cin >> arr[i];
                rightMost[arr[i]] = i;
            }

            unordered_set<int> visited;
            int answer = 0;

            for (int left = 0; left < size; ) {
                int boundary = rightMost[arr[left]];
                int cur = left;

                while (cur < boundary) {
                    boundary = max(boundary, rightMost[arr[cur]]);
                    visited.insert(arr[cur]);
                    cur++;
                }

                visited.insert(arr[cur]);
                answer += visited.size();
                visited.clear();

                left = cur + 1;
            }

            cout << answer << "\n";
        }

        return 0;
    }

---

## Complexity Analysis

Let n be the size of the array.

Time Complexity:
O(n) per test case  
Each index is visited once.

Space Complexity:
O(n)  
For hash map and set storage.

---

## Final Takeaway

This problem is not about counting elements.
It is about **knowing when a group is complete**.

Once you respect the last occurrence of every value,
the partitioning becomes inevitable.

Greedy, clean, and efficient.
Exactly how interview problems like to pretend they’re hard.
