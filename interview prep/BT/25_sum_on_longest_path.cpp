void dfs(Node* root,int sum, int &mx, int level, int &mx_level){
    if(root!=NULL){
        sum+=root->data;
        if(root->left==NULL && root->right==NULL){
            if(level>mx_level){
                mx_level=level;
                mx=sum;
            }
            else if(mx_level==level) mx=max(mx,sum);
            return;
        }
        dfs(root->left,sum,mx,level+1,mx_level);
        dfs(root->right,sum,mx,level+1,mx_level);
    }
}

int sumOfLongRootToLeafPath(Node *root)
{
    int mx_level=0;
    int mx=0;
    dfs(root,0,mx,0,mx_level);
    return mx;
}