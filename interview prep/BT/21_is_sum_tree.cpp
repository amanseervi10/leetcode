int solve(Node* root){
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL) return root->data;

    int a=solve(root->left);
    int b=solve(root->right);
    if(a==-1 || b==-1) return -1;
    if(root->data==a+b) return 2*root->data;
    else return -1;
}

bool isSumTree(Node *root)
{
    if(solve(root)==-1) return false;
    return true;
}