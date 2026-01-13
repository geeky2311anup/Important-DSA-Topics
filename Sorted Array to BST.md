# Divide & Conquer + Trees  
## Sorted Array to BST: Because Balance Is the Bare Minimum

Given a **sorted array**, we want to convert it into a **height-balanced Binary Search Tree (BST)**.  
Balanced means the tree does not lean like bad life decisions.

The trick is simple:
- Pick the **middle element** as root
- Left half becomes left subtree
- Right half becomes right subtree
- Repeat until the array gives up

This guarantees minimal height and maximum dignity.

------------------------------------------------------------

### Visual Intuition (Diagram)

Sorted Array:
    
    [-10, -3, 0, 5, 9]

Pick middle → `0`

BST formed:

            0
          /   \
       -10     5
          \      \
          -3      9

Each recursive split keeps the tree balanced, unlike most group projects.

------------------------------------------------------------

### Why This Works (Logic, Not Magic)

- Middle element ensures equal-ish nodes on both sides
- Recursion stops when the subarray becomes invalid
- Time Complexity: O(n)
- Space Complexity: O(log n) recursion stack

------------------------------------------------------------

### Java Implementation

    public class Solution {

        public TreeNode sortedArrayToBST(int[] nums) {
            return buildTree(nums, 0, nums.length - 1);
        }

        private TreeNode buildTree(int[] arr, int start, int end) {
            // stop recursion when range becomes invalid
            if (start > end) {
                return null;
            }

            // choose middle element to keep the BST height-balanced
            int midIndex = start + (end - start) / 2;

            // create root node using the middle value
            TreeNode node = new TreeNode(arr[midIndex]);

            // recursively build left and right subtrees
            node.left = buildTree(arr, start, midIndex - 1);
            node.right = buildTree(arr, midIndex + 1, end);

            return node;
        }
    }

------------------------------------------------------------

### Final Thought

If your BST is unbalanced after this, the bug is not in the algorithm.  
It’s somewhere between the keyboard and the chair.
