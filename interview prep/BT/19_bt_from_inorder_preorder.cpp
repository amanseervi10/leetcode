Node* solve(int in[],int pre[],int n ,int &i,int start, int end){

    if(start>end || i>=n) return NULL;
    
    Node* root=new Node(pre[i]);

    int j;
    for(j=start; j<=end;j++){
        if(in[j]==pre[i]) break;
    }

    i++;
    root->left=solve(in,pre,n,i,start,j-1);
    root->right=solve(in,pre,n,i,j+1,end);

}

Node *buildTree(int in[], int pre[], int n)
{
    int i=0;
    return solve(in,pre,n,i,0,n-1);
}