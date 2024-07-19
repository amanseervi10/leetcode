class Solution {
public:

    bool solve(TreeNode* root, int sum, int targetsum){
        if(root==NULL) return false;
        else{
            sum+=root->val;
            if(root->left==NULL && root->right==NULL && sum==targetsum) return true;
            bool a= solve(root->left, sum,targetsum);;
            bool b=solve(root->right, sum,targetsum);
            return a|b;
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};