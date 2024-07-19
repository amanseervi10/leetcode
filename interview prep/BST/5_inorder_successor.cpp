//we simply tweak the function of inorder a bit
//we store in the variable prev the element whose chance it was to be "printed"
//the next time we reach on a element , we know that it comes after the previos one
//we then hence rigtfully make the next of this previous element as the current element aka root

//pretty straighforward stuff

void inorder(Node* root,Node* &prev){
    if(root!=NULL){
        inorder(root->left,prev);
        
        if(prev!=NULL) prev->next=root;
        prev=root;

        inorder(root->right,prev);
    }
}

void populateNext(Node *root)
{
    Node* temp=NULL;
    inorder(root,temp);
}