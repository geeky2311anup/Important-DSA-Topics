
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* start=head;
         ListNode* newhead=head;
          ListNode* end=head;
          int count=0;
           ListNode* slow=head;
            ListNode* fast=head;
             ListNode* curr=head;
             

            while(curr!=NULL){
                count++;
                curr=curr->next;
            }

            if( count==0 || count==1){
                return head;
            }
            k=k%count;
            
            if(k==0 ){
                return head;
            }
            count=0;
        while(fast!=NULL){
            if(fast->next==NULL){
                end=fast;
                newhead=slow->next;
                slow->next=NULL;
            }


            fast=fast->next;
            count++;
            if(count>k){
                slow=slow->next;
            }
        }
        end->next=start;
        return newhead;

        
        

        
    }
};