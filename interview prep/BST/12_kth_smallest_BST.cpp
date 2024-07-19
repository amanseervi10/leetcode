void inorder(Node* root, int &count, int &k,int &ans){
    if(root!=NULL){
        inorder(root->left,count,k);
        count++;
        if(count==k){
            ans=root->data;
            return;
        }
        if(count>=k) return;
        inorder(root->right,count,k);
    }
}

int KthSmallestElement(Node *root, int K)
{
    int count=0,ans=0;
    inorder(root,count,K,ans);
    if(count<K) return -1;
    return ans;
}