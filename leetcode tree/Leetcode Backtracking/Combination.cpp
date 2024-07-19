class Solution {
public:

    void solve(vector<int>& candidates, int target,int i, int curr_sum, vector<int> curr, vector<vector<int>>& ans){
        if(i>=candidates.size()) return;
        solve(candidates,target,i+1,curr_sum,curr,ans);

        curr_sum+=candidates[i];
        curr.push_back(candidates[i]);
        if(curr_sum>target) return;
        if(curr_sum==target){
            ans.push_back(curr);
            return;
        }
        solve(candidates,target,i,curr_sum,curr,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(candidates,target,0,0,a,ans);
        return ans;
    }
};