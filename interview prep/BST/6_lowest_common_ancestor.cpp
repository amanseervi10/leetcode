// Function to find the lowest common ancestor in a BST.

//this is a BST, so finding LCA is even more easier.
//just  find the one node in comparison to whose value, one of n1 and n2 is small
//ans other is greater
Node *LCA(Node *root, int n1, int n2)
{
    if(n1>root->data && n2>root->data) return LCA(root->right,n1,n2);

    else if(n1<root->data && n2<root->data) return LCA(root->left,n1,n2);

    else return root;       //as then one is small and other is greater, hence this is the node
}