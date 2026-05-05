class Solution {
public:
    bool hasCycle(ListNode *head) {

        // If the list is empty or has only one node,
        // it cannot form a cycle
        if (head == nullptr || head->next == nullptr)
            return false;

        // Initialize two pointers:
        // slow pointer moves one step at a time
        // fast pointer moves two steps at a time
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse the linked list
        // Condition ensures fast pointer doesn't go out of bounds
        while (fast != nullptr && fast->next != nullptr) {

            // Move slow pointer by one node
            slow = slow->next;

            // Move fast pointer by two nodes
            fast = fast->next->next;

            // If a cycle exists, fast will eventually catch up to slow
            // because it moves faster (2x speed)
            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        // If fast reaches NULL, it means we hit the end of the list
        // → no cycle exists
        return false;
    }
};
