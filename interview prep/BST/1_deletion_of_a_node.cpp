class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL) return NULL;     //if it is not found at all
        
        //the first two cases are where the current node dosen't match the key
        //in such case, well simply pass the torch to the appropriate node
        if(key>root->val){
            root->right=deleteNode(root->right,key);
            return root;
        }

        else if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        }

        else{           //if it does match the current node

            //if the node is leaf node, well then no worries
            if(root->right==NULL && root->left==NULL){
                return NULL;
            }
            
            //else if the current node has only left or right child, then
            //just point it to that child, you'll basically be kinda skipping that node
            else if(root->left==NULL) return root->right;

            else if(root->right==NULL) return root->left;

            //the big guy, if the node has both the child, then we sorta change the
            //structure, we make the right child as the curr node and this right child is
            ///returned, changes are made accordingly, simillar to rotating about a node
            
            //steps are :
            //store thr right child of the current node
            //store the left child of the right child of the current node
            //make the current node as the left child of the right child of the current node
            //the current child's new right child is now the node you stored above
            //now order a new function to deleteNode on the right child
            //return the new head node, i.e the right child of the original current node
            //think about it and you'll figure that out

            else{
                TreeNode* temp=root->right;
                TreeNode* temp2=root->right->left;

                root->right=temp2;
                temp->left=root;
                

                temp->left=deleteNode(temp->left,key);
                return temp;    
            }
        }
    }
};