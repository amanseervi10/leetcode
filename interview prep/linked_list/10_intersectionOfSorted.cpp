Node* findIntersection(Node* head1, Node* head2)
{
    Node* ans=new Node(0);
    Node* curr=ans;

    while(head1->next!=NULL && head2->next!=NULL){
        if(head1->data==head2->data){
            curr->next=new Node(head1->data);
            curr=curr->next;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data>head2->data) head2=head2->next;
        else head1=head1->next;
    }

    if(head1->next==NULL){
        while(head2!=NULL){
            if(head1->data==head2->data){
                curr->next=new Node(head1->data);
                curr=curr->next;
            }
            head2=head2->next;
        }
    }
    else if(head2->next==NULL){
        while(head1!=NULL){
            if(head1->data==head2->data){
                curr->next=new Node(head1->data);
                curr=curr->next;
            }
            head1=head1->next;
        }
    }
    return ans->next;
}