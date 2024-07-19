class Solution {
public:

    void solve(vector<int> &nums, vector<vector<int>> &ans,vector<int> &temp){

        int flag=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=INT_MAX){
                flag=1; break;
            }
        }

        if(!flag){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==INT_MAX) continue;

            int store=nums[i];
            nums[i]=INT_MAX;
            temp.push_back(store);
            solve(nums,ans,temp);
            nums[i]=store;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums,ans,temp);

        return ans;
    }
};