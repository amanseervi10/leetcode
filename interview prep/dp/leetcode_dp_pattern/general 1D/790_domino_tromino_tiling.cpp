//for a good explanation refer : https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116581/detail-and-explanation-of-o-n-solution-why-dp-n-2-d-n-1-dp-n-3/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int numTilings(int n) {
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(n==3) return 5;

        int mod=1e9+7;

        vector<int> dp(n+1);
        dp[1]=1; dp[2]=2,dp[3]=5;

        for(int i=4; i<=n; i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }

        return dp[n];
    }
};