class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        dp[0][0]=triangle[0][0];

        for(int i=1; i<n; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
                else if(j==triangle[i].size()-1) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                else dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }

        int mn=INT_MAX;
        for(int i=0; i<n; i++) mn=min(mn,dp[n-1][i]);

        return mn;
    }
};