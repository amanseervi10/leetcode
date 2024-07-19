#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

void inorder(node* root, node* &prev){
    if(root!=NULL){
        inorder(root->left,prev);

        prev->right=root;
        prev->left=NULL;
        prev=root;

        inorder(root->right,prev);
    }
}

node* flatten(node* root){
    node* dummy=new node(-1);
    node* prev=dummy;
    //I made a new pointer as pointer dummy is going to change when it goes into the function
    //aas it is passed by reference. But we need this initial reference, the head of the list
    //hence we make a new pointer that does the job for us
    inorder(root,prev);

    return dummy->right;
}



int main(){
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    print(flatten(root));
    return 0;
}