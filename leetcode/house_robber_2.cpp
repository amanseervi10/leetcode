class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        int ans[nums.size()];

        ans[0]=nums[0];
        ans[1]=max(nums[0],nums[1]);

        for(int i=2; i<nums.size(); i++){
            ans[i]=max(nums[i]+ans[i-2],ans[i-1]);
        }        

        int ans2[nums.size()-1];
        ans2[0]=nums[1];
        ans2[1]=max(nums[1],nums[2]);
        for(int i=3; i<nums.size(); i++){
            ans2[i-1]=max(nums[i]+ans2[i-3],ans2[i-2]);
        }

        return max(ans2[nums.size()-2],ans[nums.size()-2]);
    }
};