solve(Node* root){


    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while(prev->right!!=curr || prev->right!=NULL){
                prev=prev->right;
            }

            
        }
    }
}