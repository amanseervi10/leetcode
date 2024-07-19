class Solution {
public:

    void solve(vector<int>& candidates, vector<vector<int>>& ans, int i, int target, vector<int>& temp){

        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target<0) return;

        for(int j=i; j<candidates.size(); j++){
            if(j!=i && candidates[j]==candidates[j-1]) continue;
            temp.push_back(candidates[j]);
            solve(candidates,ans,j+1,target-candidates[j],temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,ans,0,target,temp);

        return ans;
    }
};