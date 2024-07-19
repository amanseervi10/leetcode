bool isIsomorphic(Node *root1, Node *root2)
{
    if(!root1 && !root2) return true;

    else if(!root1 || !root2) return false;

    else if(root1->data!=root2->data) return false;

    return (isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right)) ||
            (isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left));
}