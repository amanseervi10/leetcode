class Solution {
public:

    Node* find_next(Node* curr){
        while(curr!=NULL){
            if(curr->left!=NULL) return curr->left;
            else if(curr->right!=NULL) return curr->right;
            curr=curr->next;
        }
        return NULL;
    }


    Node* connect(Node* root) {
        if(root==NULL) return NULL;

        if(root->left!=NULL){
            if(root->right!=NULL){
                root->left->next=root->right;
            }
            else{
                root->left->next=find_next(root->next);
            }
        }
        if(root->next!=NULL){
            if(root->right!=NULL){
                root->right->next=find_next(root->next);
            }
        }
        connect(root->right);
        connect(root->left);   
        return root;
    }
};