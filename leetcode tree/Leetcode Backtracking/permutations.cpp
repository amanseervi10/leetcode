class Solution {
public:

    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& temp){
        int flag=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=INT_MAX){
                flag=1; break;
            }
        }
        if(flag==0){
            ans.push_back(temp); return;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==INT_MAX) continue;
            int store=nums[i];
            temp.push_back(nums[i]);
            nums[i]=INT_MAX;
            solve(nums,temp);
            nums[i]=store;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp);
        return ans;
    }
};