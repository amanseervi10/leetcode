//basically use of lcs
// a--->b
//ans is (a.length()-lcs.length())+(b.length()-lcs.length());
//where the first part essentially denotes #deletions and second one denotes #insertions

int solve(string a, string b){
    int m=a.length(),n=b.length();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) dp[i][0]=0;
    for(int i=0; i<=n; i++) dp[0][i]=0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[m][n];
}

int minOperations(string str1, string str2)
{
    int k=solve(str1,str2);
    int ans=(str1.length()-k) + (str2.length()-k);

    return ans;
}