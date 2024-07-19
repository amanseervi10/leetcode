void reverse(Node* a,Node* b,Node* &root){
    if(b==NULL){
        root=a;
        return;
    }
    reverse(a->next,b->next,root);
    b->next=a;
    a->next=NULL;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    reverse(first,first->next,first);
    reverse(second,second->next,second);

    Node* dummy=new Node(-1);
    Node* curr=dummy;
    int carry=0;

    while(first!=NULL || second!=NULL){
        int a,b;

        if(first==NULL) a=0;
        else{
            a=first->data;
            first=first->next;
        }

        if(second==NULL) b=0;
        else{
            b=second->data;
            second=second->next;  
        }

        int sum=(a+b+carry)%10;
        int carry=(a+b+carry)/10;

        Node* temp=new Node(sum);
        curr->next=temp;
        curr=curr->next;
    }

    if(carry==1){
        curr->next=new Node(1);
    }
    return dummy->next;
}