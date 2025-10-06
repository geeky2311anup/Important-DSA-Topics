
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* temp=head;
        ListNode* temp2=head;
        int count=1;
        ListNode* start=NULL;
        ListNode* end=NULL;
        ListNode* front=NULL;
        ListNode* back=NULL;
        ListNode* prev=head;
        if(left==right){
            return head;
        }
        while(curr!=NULL && count<=right+1){
            if(count==left-1){
                start=curr;
            }
            else if(count==right+1){
                end=curr;
                
            }
            else if(count== left){
                front=curr;
            }
            else if(count == right){
                back=curr;
            }
            if(count>left && count<=right){
                temp=curr->next;
                temp2=curr;
                curr->next=prev;
                curr=temp;
                prev=temp2;
                
            }



            
             if(count<=left){
            curr=curr->next;
             }
            if(count>1 && count<=left ){
                prev=prev->next;
            }
            count++;



        }
        if (left>1){
         start->next=back;
        }
        front->next=end;
        if (left>1){
            return head;
        }
        else{
            return back;
        }
    }
};