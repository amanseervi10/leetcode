class Solution {
public:

    void solve(vector<int> &candidates,int i, vector<vector<int>>& ans, int target,vector<int> &temp){

        if(i==candidates.size()) return;

        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            solve(candidates,i,ans,target-candidates[i],temp);
            temp.pop_back();
        }
        solve(candidates,i+1,ans,target,temp);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,0,ans,target,temp);

        return ans;
    }
};