class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;
        q.push({root,0});

        long long int ans=0;

        while(!q.empty()){
            int temp=q.size();
            long long int l,r;

            for(int i=0; i<temp; i++){
                if(i==0) l=q.front().second;
                if(i==temp-1) r=q.front().second;

                TreeNode* a=q.front().first;
                long long int k=q.front().second;
                q.pop();

                if(a->left) q.push({a->left,2*k});
                if(a->right) q.push({a->right,2*k+1});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};