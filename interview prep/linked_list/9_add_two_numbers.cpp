class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head,*temp;
        head=new ListNode(0); temp=head;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int a,b;

            if(l1==NULL) a=0;
            else {
                a=l1->val;
                l1=l1->next;
            }

            if(l2==NULL) b=0;
            else {
                b=l2->val;
                l2=l2->next;
            }

            int k=(a+b+carry)%10;
            carry=(a+b+carry)/10;

            temp->next=new ListNode(k);
            temp=temp->next;

        }

        if(carry) temp->next=new ListNode(1);

        return head->next;
    }
};