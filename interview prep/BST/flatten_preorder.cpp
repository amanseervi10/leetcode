//Now here we have to flatten the tree into a linked list which should be in preorder
//Inorder would have been easy, we could easily ,maintained a prev pointer

//Now for preoder we can either use a recurive approach, one which you might have done
//during kr time.
//You really need to visualize the process for this method and also believe in resursion
//i.e just tell it what to do and it will do

//This method although O(n) in time will use space i the form of recursino stack

//Another approach could be morris traversal, which we know is good at threading tree
//It is also O(n) Time but is also O(1) space

//Below i have done the recursion method
//refer :  https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/


void solve(Node* root){

    //if root is null or is a leaf node
    if(root==NULL || (root->left==NULL && root->right==NULL)) return; 

    if(root->left!=NULL){
        solve(root->left);

        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* curr=root;
        while(curr->right!=NULL){
            curr=curr->right;
        }
        curr->right=temp;
    }
    solve(root->right);

}


void flatten(Node *root)
{
    solve(root);
}