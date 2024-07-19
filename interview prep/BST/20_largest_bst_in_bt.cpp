vector<int> solve(Node* root, int &maxcount){


    if(root->left==NULL && root->right==NULL) return {1,root->data,root->data};
    
    vector<int> a,b;
    if(root->left==NULL) a={0,INT_MIN,INT_MIN};
    else a=solve(root->left,maxcount);
    if(root->right==NULL) b={0,INT_MAX,INT_MAX};
    else b=solve(root->right,maxcount);

    if(a[1]==-1 || b[1]==-1) return {0,-1,-1};

    else{
        if(root->data>a[2] && root->data<b[1]){
            maxcount=max(maxcount,a[0]+b[0]+1);
            int k=a[1];
            if(k==INT_MIN) k=root->data;
            int p=b[2];
            if(p==INT_MAX) p=root->data;
            vector<int> temp={a[0]+b[0]+1,k,p};
            return temp;
        }
        else{
            return {0,-1,-1};
        }
    }

}

int largestBst(Node *root)
{
    int maxcount=1;
    solve(root,maxcount);
    return maxcount;
}