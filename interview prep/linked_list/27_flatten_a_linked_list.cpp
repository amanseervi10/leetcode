
Node* merge(Node* a, Node* b){
    
    Node* dummy=new Node(-1);
    Node* curr=dummy;

    while(a!=NULL && b!=NULL){
        if(a->data>=b->data){
            curr->next=b;
            b=b->next;
            curr=curr->next;
        }
        else{
            curr->next=a;
            a=a->next;
            curr=curr->next;
        }
    }
    if(a!=NULL){
        curr->next=a;
    }
    if(b!=NULL){
        curr->next=b;
    }

    return dummy->next;
}

Node *flatten(Node *root)
{
    root->next=flatten(root->next);

    return merge(root,root->next);    
}