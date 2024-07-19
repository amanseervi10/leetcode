int solve(Node* root){

    if(root==NULL) return 0;

    int temp=root->data;
    root->data=solve(root->left)+solve(root->right);
    
    return root->data+temp;
}


void toSumTree(Node *node)
{
    solve(node);
}