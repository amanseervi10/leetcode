
int solve(Node* head){
    if(head==NULL) return 1;

    int temp=solve(head->next);

    if(temp){
        int k=head->data;
        head->data=(head->data+1)%10;
        cout<<head->data;
        if(k==9) return 1;
    }
    else return 0;
}


Node *addOne(Node *head)
{
    int k=solve(head);
    cout<<k<<endl;
    if(k){
        Node* new_head=new Node(k);
        new_head->next=head;
        return new_head;
    }

    return head;

}