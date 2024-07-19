class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& temp){

        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            solve(nums,i+1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        ans.push_back({});
        return ans;
    }
};