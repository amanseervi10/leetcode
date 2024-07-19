//below is a good method

// Calculate the number of nodes (count) in the binary tree.

// Start recursion of the binary tree from the root node of the binary tree with index (i) 
// being set as 0 and the number of nodes in the binary (count).

// If the current node under examination is NULL, then the tree is a complete binary tree.Return true.

// If index (i) of the current node is greater than or equal to the number of nodes in the binary tree
//  (count) i.e. (i>= count), then the tree is not a complete binary. Return false.

// Recursively check the left and right sub-trees of the binary tree for same condition. 
// For the left sub-tree use the index as (2*i + 1) while for the right sub-tree use the 
// index as (2*i + 2).

int getCount(Node* root){
    if(root==NULL) return 0;
    else return 1+getCount(root->left) + getCount(root->right);
}

bool check(Node* root, int i, int &count){
    if(root==NULL) return true;
    
    if(i>=count) return false;

    else return (check(root->left,2*i+1,count) && check(root->right,2*i+2,count));
}

bool isCompleteBT(Node *root)
{
    int count=getCount(root);
    return check(root,0,count);
}