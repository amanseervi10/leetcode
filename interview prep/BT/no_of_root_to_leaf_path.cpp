void solve(Node* root, int level,unordered_map<int,int> &mp){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            mp[level]++;
        }
        solve(root->left,level+1,mp);
        solve(root->right,level+1,mp);
    }
}

void pathCounts(Node *root)
{
    unordered_map<int,int> mp;
    solve(root,1,mp);

    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<" $";
    }
}