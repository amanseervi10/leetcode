class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int &i, int min, int max){
        if(i>=preorder.size()) return NULL;
        
        else if(preorder[i]<min || preorder[i]>max) return NULL;

        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=solve(preorder,i,min,root->val);
        root->right=solve(preorder,i,root->val,max);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MIN,INT_MAX);
    }
};