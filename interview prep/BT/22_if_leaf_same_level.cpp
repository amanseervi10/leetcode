void solve(Node* root, int level, int &k,int& flag){
    if(root!=NULL){
        solve(root->left,level+1,k,flag);
        if(root->left==NULL && root->right==NULL){
            if(k==-1) k=level;
            else{
                if(level!=k) flag=1;
            }
        }
        if(flag=1) return;
        solve(root->right,level+1,k,flag);
    }
}

bool check(Node *root)
{
    int flag=0;
    int k=-1;
    solve(root,0,k,flag);
    if(flag) return false;
    return true;
}