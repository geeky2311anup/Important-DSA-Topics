class Solution {
    public:
        Node* detectCycle(Node* head) {
            if (!head || !head->next) {
                return nullptr;
            }
    
            Node* slow = head;
            Node* fast = head;
            Node* entry = head;
    
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
    
                if (slow == fast) { // Cycle detected
                    while (slow != entry) {
                        slow = slow->next;
                        entry = entry->next;
                    }
                    return entry; // Return the entry point of the cycle
                }
            }
            return nullptr; // No cycle found
        }
    };
    