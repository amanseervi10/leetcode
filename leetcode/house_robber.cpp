class Solution {
public:

    // int solve(vector<int> &nums,int i){
    //     if(i<0) return 0;
    //     return max(nums[i]+solve(nums,i-2),solve(nums,i-1));
    // }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0],nums[1]);
        int ans[nums.size()];
        ans[0]=nums[0];
        ans[1]=max(nums[0],nums[1]);
        for(int i=2; i<nums.size(); i++){
            ans[i]=max(nums[i]+ans[i-2],ans[i-1]);
        }
        return ans[nums.size()-1];
    }
};