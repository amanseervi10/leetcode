
Node* solve(int in[],int post[],int &i, int start,int end){

    if(start>end || i<0) return NULL;

    Node* root=new Node(post[i]);

    int j;
    for(j=start; j<=end; j++){
        if(post[i]==in[j]) break;
    }

    root->left=solve(in,post,--i,start,j-1);
    root->right=solve(in,post,--i,j+1,end);

    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int i=n-1;
    return solve(in,post,i,0,n-1);
}