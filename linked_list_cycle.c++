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