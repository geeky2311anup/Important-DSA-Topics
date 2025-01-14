class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode * fast=head;
       ListNode * slow=head;
       ListNode * prev=head;
       int count=0;
      
       while(count<n){
        fast=fast->next;
        count++;
       }
       while(fast!=NULL){
        fast=fast->next;
        prev=slow;
        slow=slow->next;
       }
       if(prev==slow){
        
       ListNode* temp= slow->next;
       delete slow;
       return temp;
       }
       else{
      prev->next=slow->next;
      delete slow;
      return head;
       }
      


    }
};