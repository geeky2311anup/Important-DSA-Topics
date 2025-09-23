
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && slow!=NULL){
          
         if(fast->next!=NULL){
            fast=fast->next->next;
           }
           else {
            return false;
           }
           slow=slow->next;
            if(fast==slow){
            return true;
           }
        }
        return false;
    }
};