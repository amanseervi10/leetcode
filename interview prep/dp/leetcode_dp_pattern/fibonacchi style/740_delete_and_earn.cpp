class Solution {
public:

    int solve(vector<int> &nums, int i,vector<int> &dp){

        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        //assume we take it so we add all values
        int sum=0;
        int curr_val=nums[i];
        int k=i;
        while(i<nums.size() && nums[i]==curr_val){
            sum+=nums[i];
            i++;
        }
        //after this while loop i points toward the next distict element
        //remember this

        //now we will also need to skip elements with value curr_val+1 as that is the rule
        int index=i;
        while(index<nums.size() && nums[index]==curr_val+1) index++;

        //so we eithr take it or leave it and point to the next element
        //i points currently to the next element hence it is there in the second recursive call

        //took k here as i is now altered, we stored k above just so we could save this to dp vector
        return dp[k]=max(sum+solve(nums,index,dp),solve(nums,i,dp));
        
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> dp(nums.size()+1,-1);

        return solve(nums,0,dp);
    }
};