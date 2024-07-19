bool search(Node *root, int x)
{
    if(root==NULL) return false;
    else if(root->data==x) return true;
    else{
        if(x>root->data) return search(root->right,x);
        else return search(root->left,x);
    }
}
