class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        ListNode* nextNode;

        
        for (int i = 0; i < right - left; i++) {
            nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};
