int getNthFromLast(Node *head, int n)
{
    Node* ahead=head;

    int k=n-1;
    while(k--){
        ahead=ahead->next;
        if(ahead==NULL) return -1;
    }

    Node* behind=head;

    while(ahead->next!=NULL){
        ahead=ahead->next;
        behind=behind->next;
    }

    return behind->data;
}
