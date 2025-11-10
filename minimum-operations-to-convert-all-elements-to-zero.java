/*
 * LeetCode Problem:
 * https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
 *
 * Approach Explanation:
 * ----------------------
 * This problem requires finding the minimum number of operations needed to convert
 * all elements in an array to zero by repeatedly choosing subarrays and subtracting
 * the smallest positive element from each element in that subarray.
 *
 * Intuition:
 * ----------
 * - Think of this as maintaining an increasing stack that represents the sequence
 *   of distinct non-decreasing numbers we've seen so far.
 * - Whenever we find an element smaller than the top of the stack,
 *   it means the sequence is decreasing — so we need to "pop" elements
 *   (undo previous levels) and count those operations.
 * - Each unique increasing step contributes to one operation.
 *
 * Step-by-step logic:
 * -------------------
 * 1. Create an array `st` (acting as a stack) to keep track of the current increasing sequence.
 * 2. Use `idx` as a stack pointer (top of stack).
 * 3. Iterate over each number in `arr`:
 *    - While the current number is smaller than the stack's top value,
 *      pop from stack (decrement `idx`) and increment `count` (operations).
 *    - If the top value is not equal to the current number,
 *      push the current number onto the stack.
 * 4. At the end, the total operations are `count + idx`, 
 *    because each remaining element in the stack contributes one operation.
 *
 * Example:
 * --------
 * Input: arr = [3, 1, 6, 4, 2]
 * 
 * Stack building process:
 *  - 3 pushed  → stack = [3]
 *  - 1 smaller than 3 → pop 3 (count=1), push 1 → stack = [1]
 *  - 6 > 1 → push 6 → stack = [1, 6]
 *  - 4 smaller than 6 → pop 6 (count=2), push 4 → stack = [1, 4]
 *  - 2 smaller than 4 → pop 4 (count=3), push 2 → stack = [1, 2]
 * 
 * Total operations = count + stack size = 3 + 2 = 5
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
    public int minOperations(int[] arr) {
        int[] st = new int[arr.length + 1];  // stack to track increasing sequence
        int idx = 0;    // stack top pointer
        int count = 0;  // total operations

        for (int i = 0; i < arr.length; i++) {
            while (st[idx] > arr[i]) {  // if current element breaks increasing order
                idx--;                  // pop from stack
                count++;                // increment operation count
            }
            if (st[idx] != arr[i]) {    // avoid duplicates
                st[++idx] = arr[i];     // push current element
            }
        }
        return count + idx; // remaining elements also contribute to operations
    }
}
