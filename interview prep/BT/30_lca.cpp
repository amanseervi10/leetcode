Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL) return NULL;
    
    if(root->data==n1 || root->data==n2) return root;

    Node* a=lca(root->left,n1,n2);
    Node* b=lca(root->right,n1,n2);

    if(a!=NULL && b!=NULL) return root;

    else if(b==NULL) return a;
    else if(a==NULL) return b;
    else return NULL;
}