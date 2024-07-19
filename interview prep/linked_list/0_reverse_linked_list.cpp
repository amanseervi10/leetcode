class Solution {
public:
    void solve(ListNode* r1,ListNode* r2, ListNode* &head){
        if(r2==NULL){
            head=r1;
            return;
        }  
        solve(r1->next,r2->next,head);
        r2->next=r1;
        r1->next=NULL;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        solve(head,head->next,head);
        return head;
    }
};