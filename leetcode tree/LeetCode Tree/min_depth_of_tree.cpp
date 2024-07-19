/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int& ans, int curr_depth){
        if(root!=NULL){
            solve(root->left,ans,curr_depth+1);
            if(root->left==NULL && root->right==NULL) ans=min(ans,curr_depth);
            solve(root->right,ans,curr_depth+1);
        }
    }

    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MAX;
        solve(root,ans,1);
        return ans;
    }
};