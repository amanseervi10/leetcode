int sum(Node* root, int &mx){
    if(root==NULL) return 0;

    int a=sum(root->left,mx);
    int b=sum(root->right,mx);

    int temp=root->data+a+b;
    mx=max(mx,temp);
    return temp;
}

int findLargestSubtreeSum(Node *root)
{
    int mx=INT_MIN;
    sum(root,mx);
    return mx;
}