int height(Node* root){
    if(root==NULL) return 0;
    
    int a=height(root->left);
    int b=height(root->right);
    if(a==-1 || b==-1) return -1;
    else if(abs(b-a)>1) return -1;
    else return 1+max(a,b);
}

bool isBalanced(Node *root)
{
    if(height(root)==-1) return false;
    return true;
}