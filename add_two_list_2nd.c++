class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers: slow moves 1 step, fast moves 2 steps
        ListNode *fast = head, *slow = head;

        // Traverse the list while fast pointer and its next are valid
        while (fast && fast->next) {
            // Move fast pointer by 2 steps
            fast = fast->next->next;

            // Move slow pointer by 1 step
            slow = slow->next;

            // If both pointers meet, a cycle exists
            if (fast == slow) 
                return true;
        }

        // If we reach here, fast pointer hit NULL → no cycle
        return false;
    }
};
