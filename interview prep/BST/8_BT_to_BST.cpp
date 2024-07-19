void inorder(Node* root,vector<int>& store){
    if(root!=NULL){
        inorder(root->left,store);
        store.push_back(root->data);
        inorder(root->right,store);
    }
}

void inorder2(Node* root,vector<int>& store,int &i){
    if(root!=NULL){
        inorder(root->left,store,i);
        root->data=store[i];
        i++;
        inorder(root->right,store,i);
    }
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> store;
    inorder(root,store);
    sort(store.begin(),store.end());

    int i=0;
    inorder2(root,store,i);
    return root;
}