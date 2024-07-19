//one obvious method would be to traverse the entire the tree and keep incrementing the count
//when any node satisfies the condition

//but we can optimize it by neglecting a few subtrees

//eg. if curr node itself is less than lower limit then no point in searching it's left child
//as all left children will be less. so we search only in right subtree of this node

//similarly we do others


void preorder(Node* root, int &count, int l, int h){
    if(root!=NULL){
        if(root->data>=l && root->data<=h){
            count++;
            preorder(root->left,count,l,h);
            preorder(root->right,count,l,h);
        }
        else if(root->data<l){
            preorder(root->right,count,l,h);
        }
        else preorder(root->left,count,l,h);
    }
}

int getCount(Node *root, int l, int h)
{
    int count=0;
    preorder(root,count,l,h);
    return count;
}