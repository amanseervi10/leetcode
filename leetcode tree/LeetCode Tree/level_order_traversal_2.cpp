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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> a;
        vector<vector<int>> ans;

        a.push(root); a.push(NULL);
        while(1){
            TreeNode* temp=a.front();
            if(temp==NULL) break;
            else{
                vector<int> b;
                while(temp!=NULL){
                    b.push_back(temp->val);
                    if(temp->left!=NULL) a.push(temp->left);
                    if(temp->right!=NULL) a.push(temp->right);
                    a.pop();
                    temp=a.front();
                }
                a.pop();
                a.push(NULL);
                ans.push_back(b);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};