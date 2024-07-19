//for this we need to check two things
//1. it should be complete binary tree
//2. it should follow heap property, i.e botg children should be less than node

int getCount(Node* root){
    if(root==NULL) return 0;
    else return 1+getCount(root->left) + getCount(root->right);
}

bool check_complete(Node* root, int i, int &count){
    if(root==NULL) return true;
    
    if(i>=count) return false;

    else return (check_complete(root->left,2*i+1,count) && check_complete(root->right,2*i+2,count));
}

bool check_heap(Node* root){
    if(root==NULL) return true;

    if(root->left && root->left->data > root->data) return false;
    if(root->right && root->right->data > root->data) return false;

    return check_heap(root->left) && check_heap(root->right);
}

bool isHeap(struct Node *tree)
{
    int count=getCount(tree);
    return check_complete(tree,0,count) && check_heap(tree);
}