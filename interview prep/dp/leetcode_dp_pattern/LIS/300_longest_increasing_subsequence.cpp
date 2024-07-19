//for recurive code how to think refer below link
//do see : https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326552/optimization-from-brute-force-to-dynamic-programming-explained/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:

    //below is dp based solution

    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,1);
        
        dp[0]=1;
        int ans=1;

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    ans=max(ans,dp[i]);
                }
            }
        }

        return ans;
    }
};