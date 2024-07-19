//Available on gfg practice

//Recursion2
// int solve(string a,string b, int i,int j, int ans){
//     if(i<0 || j<0) return 0;

//     else if(a[i]==b[j]) ans=solve(a,b,i-1,j-1,ans+1);

//     else ans=max({ans,solve(a,b,i-1,j,0),solve(a,b,i,j-1,0)});

//     return ans;
// }

//Tabulation
int solve(string a, string b, int n,int m){
    int dp[n+1][m+1];
    int ans=0;

    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            ans=max(ans,dp[i][j]);
        }
    }

    return ans;
}
 

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    return solve(S1,S2,n,m);
}