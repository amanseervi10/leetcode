void left(Node* root, vector<int> &ans){
    if(root!=NULL){

        //This is so that we do not cater the leaf node. The leaf ndes will be catered in the
        //left function, otherwise there will be repetition
        if(root->left==NULL && root->right==NULL) return;  

        ans.push_back(root->data);

        if(root->left) left(root->left,ans);
        else left(root->right,ans);     //if right is null it will return as we wrapped overall fucntion in such if condition
    }
}

void leaf(Node* root, vector<int> &ans){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
}

void right(Node* root, vector<int> &ans){
    if(root!=NULL){

        //This is so that we do not cater the leaf node. The leaf ndes will be catered in the
        //left function, otherwise there will be repetition
        if(root->left==NULL && root->right==NULL) return;  


        if(root->right) right(root->right,ans);
        else right(root->left,ans);     //if left is null it will return as we wrapped overall fucntion in such if condition
        
        ans.push_back(root->data);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    //To handle corner cases and shit
    ans.push_back(root->data);
    if(root->left==NULL && root->right==NULL) return ans;

    left(root->left,ans);
    leaf(root->right,ans);
    right(root,ans);
    
    return ans;
}