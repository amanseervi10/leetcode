
//function to collect the value of the nodes, and since it's inorder, we naturally 
//get it in sorted order
void inorder(Node* root, vector<int> &store){
    if(root!=NULL){
        inorder(root->left,store);
        store.push_back(root->data);
        inorder(root->right,store);
    }
}

//recursive function that does it's thing
Node* solve(vector<int> &store, int start,int end){
    
    if(end<start) return NULL;

    int i=(start+end)/2;
    Node* root=new Node(store[i]);
    root->left=solve(store,start,i-1);
    root->right=solve(store,i+1,end);
    return root;

}

Node* buildBalancedTree(Node* root)
{
    //we first collect the node values in a vector
    vector<int> store;
    inorder(root,store);

    return solve(store,0,store.size()-1);
}