int height(Node* root,int &diameter){
    if(root==NULL) return 0;
    
    int a=height(root->left,diameter);
    int b=height(root->right,diameter);
    diameter=max(diameter,1+a+b);
    return 1+max(a,b);
}

int diameter(Node *root)
{
    int dia=0;
    height(root,dia);
    return dia;
}