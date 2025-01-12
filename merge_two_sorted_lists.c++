class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* upper=NULL;
        ListNode* lower=NULL;
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
       if(list1->val > list2->val){
         upper=list2;
         lower=list1;
       }
       else{
         upper=list1;
         lower=list2;

       }
       ListNode* upcurr=upper->next;
       ListNode* upprev=upper;
       ListNode* lowcurr=lower;
       ListNode* lownext=lower->next;
        while(lowcurr!=NULL){
            if(upcurr == NULL){
                upprev->next=lowcurr;
                break;
            }
            else if(upcurr->val > lowcurr->val){
                upprev->next=lowcurr;
                lowcurr->next=upcurr;
                /////////////update
                upprev=upprev->next;
                lowcurr=lownext;
                if(lownext!=NULL){
                    lownext=lownext->next;
                }
            }
            else{
                 upprev=upprev->next;
                upcurr=upcurr->next;
            }
        }
        return upper;
    }
};