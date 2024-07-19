void solve(Node* root, int& count, int &K, int &ans){
    if(root!=NULL){
        solve(root->right,count,K,ans);
        count++;
        if(count==K){
            ans=root->data;
        }
        if(count>=K) return;
        solve(root->left,count,K,ans);
    }
}

int kthLargest(Node *root, int K)
{
    int count=0, ans=0;
    solve(root,count,K,ans);
    if(count<K) return -1;
    return ans;
}