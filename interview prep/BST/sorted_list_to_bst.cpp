class Solution {
public:

    TreeNode* solve(ListNode* head,ListNode* end){

        if(head==end) return NULL;

        ListNode* fast=head,*slow=head;
        while(fast!=end && fast->next!=end){
            fast=fast->next->next;
            slow=slow->next;
        }

        //slow is our head now in this call 
        //we need to build left and right subtree of this head
        TreeNode* root=new TreeNode(slow->val);
        root->left=solve(head,slow);
        root->right=solve(slow->next,end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head,NULL);
    }
};


//Refer this for better method :  https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

//Related posts : 
//https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
//https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/