class Solution {
public:

    //See reverse linked list logic once on leetcode

    void solve(ListNode*& start, ListNode* end,int &flag){
        if(end==NULL) return;

        solve(start,end->next,flag);

        if(flag) return;

        if(start==end || start->next==end){
            end->next=NULL;
            flag=1; return;
        }

        ListNode* temp=start->next;
        start->next=end;
        end->next=temp;
        start=temp;

    }

    void reorderList(ListNode* head) {
        ListNode* temp=head;
        int flag=0;
        solve(temp,head,flag);
    }
};