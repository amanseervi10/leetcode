//This is the recursive solution and i find it better
//There is also the usual queue based solution, i did the leftview problem that way

void solve(Node* root,int level,vector<int> &ans){
    if(root!=NULL){
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
}

vector<int> rightView(Node *root)
{
    vector<int> ans;
    solve(root,0,ans);
    return ans;
}
