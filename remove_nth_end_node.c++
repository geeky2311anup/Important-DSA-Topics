class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Initialize two pointers: fast and slow
        ListNode *fast = head;
        ListNode *slow = head;

        // 'prev' will track the node before 'slow'
        ListNode *prev = head;

        int count = 0;

        // Move 'fast' pointer n steps ahead
        // This creates a gap of n nodes between fast and slow
        while (count < n) {
            fast = fast->next;
            count++;
        }

        // Move both fast and slow until fast reaches NULL
        // At this point, slow will be at the node to delete
        while (fast != NULL) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        // Special case: deleting the head node
        // This happens when prev == slow (i.e., only one movement or n == length)
        if (prev == slow) {
            ListNode* temp = slow->next; // new head
            delete slow;                 // delete old head
            return temp;
        } 
        else {
            // Normal case: bypass the node to delete
            prev->next = slow->next;
            delete slow;
            return head;
        }
    }
};
