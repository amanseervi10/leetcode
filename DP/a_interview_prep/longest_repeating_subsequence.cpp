int solve(string s1,string s2){
    int x=s1.length(),y=s1.length();    //as both are same string
    int dp[x+1][y+1];
    for(int i=0; i<=x; i++) dp[i][0]=0;
    for(int i=0; i<=y; i++) dp[0][i]=0;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1]==s2[j-1] && i!=j) dp[i][j]=1+dp[i-1][j-1];   
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[x][y];
}

int LongestRepeatingSubsequence(string str)
{
    return solve(str,str)/2;
}