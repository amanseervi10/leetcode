Node* merge(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;
    
    Node* result;
    if(a->data>b->data){
        result=b;
        result->bottom=merge(a,b->bottom);
    }
    else if(b->data>a->data){
        result=a;
        result->bottom=merge(a->bottom,b);
    }
    result->next=NULL;
    return result;
}
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL) return root;
    
    root->next=flatten(root->next);
    
    root=merge(root,root->next);
    
    return root;
}