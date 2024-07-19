class Solution {
public:

    vector<vector<int>> ans;
    set<vector<int>> store;
    void solve(vector<int>& nums, int index, vector<int>& temp){

        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            store.insert(temp);
            solve(nums,i+1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,0,temp);
        for(auto i : store) ans.push_back(i);
        ans.push_back({});
        return ans;
    }
};