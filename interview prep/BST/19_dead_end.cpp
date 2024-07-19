bool preorder(Node* root, int min, int max){
    if(root!=NULL){
        if(min==max) return true;
        else return (preorder(root->left,min,root->data-1) || preorder(root->right,root->data+1,max));
    }
}

bool isDeadEnd(Node *root)
{
    return preorder(root,1,INT_MAX);       
    //we take 1 instead of INT_MIN as the tree only contains values greater than 0
}