ListNode *moveToFront(ListNode *head)
{
    if(head->next==NULL) return head;
    ListNode* temp=head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    ListNode* temp2=temp->next;
    temp->next=NULL;
    temp2->next=head;
    return temp2;

}