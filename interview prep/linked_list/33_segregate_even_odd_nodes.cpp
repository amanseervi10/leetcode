Node *divide(int N, Node *head)
{   
    Node* dummyodd=new Node(-1);
    Node* dummyeven=new Node(-1);


    Node* even=dummyeven,*odd=dummyodd;
    Node* curr=head;

    while(curr!=NULL){

        if(curr->data%2==0){
            even->next=curr;
            even=even->next;
        }
        else{
            odd->next=curr;
            odd=odd->next;
        }
        curr=curr->next;
    }
    odd->next=NULL;
    even->next=dummyodd->next;
    return dummyeven->next;
}