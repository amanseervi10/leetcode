bool solve(Node* root, int a, int b){       // a is lower limit and b is upper limit, both inclusive
    if(root==NULL) return true;
    else{
        if(root->data<a || root->data>b) return false;
        else{
            return (solve(root->left,a,root->data-1) && solve(root->right,root->data+1,b));
        }
    }
}

bool isBST(Node *root)
{
    return solve(root,INT_MIN,INT_MAX);
}