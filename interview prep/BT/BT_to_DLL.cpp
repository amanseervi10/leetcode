//similar to converting binary tree to linked list which is inorder 

void inorder(Node* root, Node* &prev){
    if(root!=NULL){
        inorder(root->left,prev);
        
        prev->right=root;
        root->left=prev;
        prev=root;

        inorder(root->right,prev);
    }
}

Node *bToDLL(Node *root)
{
    Node* dummy=new Node(-1);
    Node* prev=dummy;       
    //I made a new pointer as pointer dummy is going to change when it goes into the function
    //aas it is passed by reference. But we need this initial reference, the head of the list
    //hence we make a new pointer that does the job for us

    inorder(root,prev);

    dummy->right->left=NULL;

    return dummy->right;
}