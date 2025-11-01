problem link ->  https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01
import java.util.*;

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> s = new HashSet<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            s.add(nums[i]);
        }

        ListNode curr = head;
        ListNode prev = null;
        ListNode ans = null;

        while (curr != null) {
            if (s.contains(curr.val)) {
                curr = curr.next;
            } else {
                prev = curr;
                ans = curr;
                curr = null;
            }
        }

        curr = head;
        if (prev == null) {
            return null;
        } else {
            curr = prev.next;
            while (curr != null) {
                if (s.contains(curr.val)) {
                    prev.next = curr.next;
                    curr = prev.next;
                } else {
                    prev = curr;
                    curr = curr.next;
                }
            }
        }
        return ans;
    }
}
