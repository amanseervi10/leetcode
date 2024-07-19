class Solution {
public:

    void solve(TreeNode* root, vector<int> curr,vector<vector<int>>& ans,int targetsum, int sum){
        if(root!=NULL){
            sum+=root->val;
            curr.push_back(root->val);
            if(root->left==NULL && root->right==NULL && sum==targetsum){
                vector<int> temp=curr;
                ans.push_back(temp);
            }
            solve(root->left,curr,ans,targetsum,sum);
            solve(root->right,curr,ans,targetsum,sum);
            curr.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root,curr, ans, targetSum, 0);
        return ans;
    }
};