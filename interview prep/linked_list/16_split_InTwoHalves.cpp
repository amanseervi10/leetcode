void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* fast=head->next->next;
    Node* slow=head->next;

    while(1){
        if(fast->next->next==head){
            *head1_ref=(fast->next->next);  //or simply head
            *head2_ref=(slow->next);
            slow->next=*head1_ref;
            fast->next->next=*head2_ref;
            return;
        }
        else if(fast->next==head){
            *head1_ref=(fast->next);    //or simply head
            *head2_ref=(slow->next);
            slow->next=*head1_ref;
            fast->next=*head2_ref;
            return;
        }
        else{
            fast=fast->next->next;
            slow=slow->next;
        }
    }
}