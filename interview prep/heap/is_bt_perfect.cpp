pair<int,bool> solve(Node* root){
    if(root==NULL) return {0,true};

    auto a=solve(root->left);
    auto b=solve(root->right);
    
    if(!a.second || !b.second) return {0,false};
    if(a.first!=b.first) return {0,false};
    else return {a.first+1,true};
}

bool isPerfect(Node *root)
{
    auto temp=solve(root);

    return temp.second;
}