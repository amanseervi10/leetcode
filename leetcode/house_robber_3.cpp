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

    // [pick,not-pick]
    vector<int> solve(TreeNode* root){
        if(root==NULL) return {0,0};

        vector<int> l,r,curr;

        l=solve(root->left);
        r=solve(root->right);
        
        curr.push_back(root->val+l[1]+r[1]);
        curr.push_back(max(l[0],l[1])+max(r[0],r[1]));
        return curr;
    }

    int rob(TreeNode* root) {
        vector<int> ans=solve(root);
        return max(ans[0],ans[1]);
    }
};