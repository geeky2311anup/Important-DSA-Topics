
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* anslist=new ListNode(0);
        ListNode* curr0=anslist;
        int carry=0;
        int sum=0;
        int p=0;
        int q=0;
        while(curr1!=NULL || curr2!=NULL){
            if(curr1!=NULL){
                p=curr1->val;

            }
            else{
                p=0;
            } 

            if(curr2!=NULL){
                q=curr2->val;
            }
            else{
                q=0;

            } 
            sum=p+q;
            curr0->next=new ListNode((carry+sum)%10);
            carry=(carry+sum)/10;
            if(curr1!=NULL){
            curr1=curr1->next;
            }
            if(curr2!=NULL){
            curr2=curr2->next;
            }
            curr0=curr0->next;

        }
        if(carry==0){
            return anslist->next;
        }
        else{
            curr0->next=new ListNode(1);
            return anslist->next;
        }
   };