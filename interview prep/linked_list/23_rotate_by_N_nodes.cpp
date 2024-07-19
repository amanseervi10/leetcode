class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        //We first find length
        ListNode* curr=head;
        ListNode* tail;
        int length=0;
        while(curr!=NULL){
            if(curr->next==NULL) tail=curr;
            length++;
            curr=curr->next;
        }
        //In the end this is the length by which we have to rotate
        k=k%length;

        //So we need to go to (length-k)th node, make it's next as NULL and make the next of tail
        //as head
        //the new head will be the (length-k+1)th node

        int count=1;
        curr=head;
        while(count!=(length-k)){
            curr=curr->next;
            count++;
        }

        tail->next=head;
        head=curr->next;    //making the (length-k+1)th node as new head
        curr->next=NULL;   //(length-k)th node become the new tail

        return head;

    }
};