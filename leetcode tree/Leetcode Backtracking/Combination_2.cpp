class Solution {
public:

   
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int index,int sum, vector<int> temp){        
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(sum>target) return;

        for(int i=index; i<candidates.size(); i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates,target,i+1,sum,temp);
            sum-=candidates[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,0,temp);
        return ans;
    }
};