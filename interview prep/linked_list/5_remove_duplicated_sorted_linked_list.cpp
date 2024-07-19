Node *removeDuplicates(Node *head)
{
    Node* temp=head;
    while(1){
        if(temp->next==NULL) break;
        else if(temp->next->data==temp->data){
            temp->next=temp->next->next;
        }
        else temp=temp->next;
    }
    return head;
}