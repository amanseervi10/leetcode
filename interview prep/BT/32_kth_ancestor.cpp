Node* solve(Node* root, int &k, int node){

    if(root==NULL) return NULL;

    if(root->data==node) return root;

    Node* l=solve(root->left,k,node);
    Node* r=solve(root->right,k,node);

    if(l!=NULL || r!=NULL){
        if(l!=NULL){
            if(k==0) return l;
            k--;
            return root;
        }
        if(r!=NULL){
            if(k==0) return r;
            k--;
            return root;
        }
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* temp=solve(root,k,node);;
    if(k!=0) return -1;
    return temp->data;
}