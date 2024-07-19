Node* reverseDLL(Node * head)
{
    while(head->next!=NULL) head=head->next;
    
    Node* curr=head;

    while(curr!=NULL){
        Node* temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->next;
    }
    return head;
}