class Solution {
public:

    int solve(string a, string b, int i, int j,vector<vector<int>> &dp){

        if(i<0 && j<0) return 0;
        else if(i<0) return j+1;
        else if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(a[i]==b[j]) return dp[i][j]=solve(a,b,i-1,j-1,dp);

        int insert=1+solve(a,b,i,j-1,dp);
        int delete_op=1+solve(a,b,i-1,j,dp);
        int replace=1+solve(a,b,i-1,j-1,dp);

        return dp[i][j]=min({insert,delete_op,replace});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,word1.length()-1,word2.length()-1,dp);
    }
};