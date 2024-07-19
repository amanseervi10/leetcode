// same as the subset partition difference count problem

class Solution {
public:

    int dp[22][1001];

    void maketable(vector<int> v, int range,int n){
        for(int i=0; i<range+1; i++) dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1; i<n+1; i++) dp[i][0]=dp[i-1][0]+(v[i-1]==0)*dp[i-1][0];
        for(int i=1; i<n+1; i++){
            for(int j=1; j<range+1; j++){
                if(j>=v[i-1]) dp[i][j]=dp[i-1][j] + dp[i-1][j-v[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i: nums) sum+=i;
        maketable(nums,sum,nums.size());
        int count=0;
        for(int i=0; i<=sum; i++){
            if(dp[nums.size()][i]){
                if((sum-2*i)==(target)) count+=dp[nums.size()][i];
            }
        }
        return count;
    }
};