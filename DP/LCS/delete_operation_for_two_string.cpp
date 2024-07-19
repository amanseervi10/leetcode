class Solution {
public:

    int dp[501][501];
    int solve(string x,string y){
        for(int i=0; i<=x.length(); i++) dp[0][i]=0;
        for(int i=0; i<=y.length(); i++) dp[i][0]=0;
        for(int i=1; i<=y.length(); i++){
            for(int j=1; j<=x.length(); j++){
                if(x[j-1]==y[i-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[y.length()][x.length()];
    }

    int minDistance(string word1, string word2) {
        return (word1.length()+word2.length()-2*solve(word1,word2));
    }
};