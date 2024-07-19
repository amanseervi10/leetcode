
//recursion
// int solve(string a,string b,int i,int j){
    
//     if(j<0) return 1;
//     if(i<0) return 0;

//     if(a[i]==b[j]) return (solve(a,b,i-1,j-1)+solve(a,b,i-1,j));

//     else return solve(a,b,i-1,j);
// }

//memoization
// int dp[10001][5];
int mod=1000000007;

//correct code but dosen't work, we need to optimize more
//we can simply do by tabulation, as it is much similar to lcs and
//also we can clearly see how to apply tabulation

// int solve(string a,string b,int i,int j){
    
//     if(j<0) return 1;
//     if(i<0) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];

//     if(a[i]==b[j]) return dp[i][j]=(solve(a,b,i-1,j-1)+solve(a,b,i-1,j));

//     else return dp[i][j]=solve(a,b,i-1,j);
// }

int solve(string a,string b){
    int m=a.length();
    int n=b.length();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) dp[i][0]=1;
    for(int i=0; i<=n; i++) dp[0][i]=0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            else dp[i][j]=dp[i-1][j]%mod;
        }
    }

    return dp[m][n];    
}

int TotalWays(string str)
{
    return solve(str,"GEEKS");
}