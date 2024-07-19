void preorder(Node* root, vector<int> &ans){
    if(root==NULL){
        ans.push_back(-1); 
        return;
    }

    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

vector<int> serialize(Node *root)
{
    vector<int> ans;
    preorder(root,ans);
    return ans;
}

// Function to deserialize a list and construct the tree.
Node* solve(vector<int> &A, int& i){

    if(i>=A.size() || A[i]==-1) return NULL;

    Node* root=new Node(A[i]);
    root->left=solve(A,++i);
    root->right=solve(A,++i);
    return root;
}

Node *deSerialize(vector<int> &A)
{
    int i=0;
    return solve(A,i);
}