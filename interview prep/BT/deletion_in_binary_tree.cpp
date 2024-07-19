//question link: https://practice.geeksforgeeks.org/problems/deletion-in-a-binary-tree/1

//i am finding deepest node, at the same time it's parent so that i don't have to traverse 
//again to delete that node

//also the change node is the node with the key,i.e the one to be deleted
//that also i am findind in this single traversal

void traversal(Node* root, int height, int &mx, Node* parent, Node* &parent_mx, Node* &node,Node* &change,int key){
    if(root!=NULL){
        traversal(root->left,height+1,mx,root,parent_mx,node,change,key);
        if(height>=mx){
            mx=height;
            parent_mx=parent;
            node=root;
        }
        if(root->data==key){
            change=root;
        }
        traversal(root->right,height+1,mx,root,parent_mx,node,change,key);
    }
}

struct Node* deletionBT(struct Node* root, int key)
{

    //These 2 if's are corner cases
    if(root==NULL) return NULL;
    
    if(root->right==NULL && root->left==NULL){
        if(root->data==key) return NULL;
        else return root;
    }
    
    int mx=INT_MIN;
    Node* parent_mx; Node* node;Node* change;
    
    traversal(root,0,mx,root,parent_mx,node,change,key);
    
    
    change->data=node->data;
    
    if(parent_mx->right==node){
        parent_mx->right=NULL;
    }
    else parent_mx->left=NULL;
    
    return root;
    
}