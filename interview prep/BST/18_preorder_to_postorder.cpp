 Node* create(int pre[],int &i, int size, int min,int max){

    if(i>=size) return NULL;

    else if(pre[i]<min || pre[i]>max) return NULL;

    Node* root=newNode(pre[i]);
    i++;
    root->left=create(pre,i,size,min,root->data-1);
    root->right=create(pre,i,size,root->data+1,max);

    return root;
}

Node *post_order(int pre[], int size)
{
    //just insert the value into a bst;
    //since it is preoder it will naturally be the correct tree
    
    //Now how do you create that tree
    //Well you could simply write that general bst function that does the thing
    //But that has a complexity of O(n*logn)
    //as n elements as inserted and each element may take as much as logn time

    //We could use that approach of min max though which is used to create tree
    //from preorder array. That will only take time of the order of O(n)

    int i=0;
    return create(pre,i,size,INT_MIN,INT_MAX);
}