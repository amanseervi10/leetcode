
//we can traverse in a inorder fashion and hence get elements in sorted order ans store in vector
//we then again traverse in postorder fasion and deliver the elements as we move

void inorder(Node* root,vector<int> &v){
    if(root!=NULL){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}

void postorder(Node* root, vector<int> &v, int& i){
    if(root!=NULL){
        postorder(root->left,v,i);
        postorder(root->right,v,i);
        root->data=v[i]; 
        i++;
    }
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> v;
    inorder(root,v);
    int i=0;
    postorder(root,v,i);
}