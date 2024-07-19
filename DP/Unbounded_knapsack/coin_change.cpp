class Solution {
public:

    int dp[13][10001];

    void solve(vector<int> coins,int amount){
        for(int i=0; i<=coins.size(); i++) dp[i][0]=0;
        for(int i=1; i<=amount; i++) dp[0][i]=INT_MAX-1;
        for(int i=1; i<=coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j>=coins[i]) dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                else dp[i][j]=dp[i-1][j];
            }
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        solve(coins,amount);
        if(dp[coins.size()][amount]==INT_MAX-1) return -1;
        else return dp[coins.size()][amount];
    }
};