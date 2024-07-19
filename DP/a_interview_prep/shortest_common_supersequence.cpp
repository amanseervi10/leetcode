//Available on gfg practice

//recursion
// int solve(string a,string b,int i,int j){
//     if(i<0 && j<0) return 0;
//     else if(i<0) return j+1;
//     else if(j<0) return i+1;

//     else if(a[i]==b[j]) return 1+solve(a,b,i-1,j-1);
//     else return min(1+solve(a,b,i-1,j),1+solve(a,b,i,j-1));
// }

//or instead of this new logic , just write the code of lcs and then calculate
// a.length()+b.length() - lcs.length()
//pretty obvious how this will give you the length of shortest common supersequence

//tabulation
int solve(string a,string b, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++) dp[i][0]=i;
    for(int i=0; i<=n; i++) dp[0][i]=i;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    // return solve(X,Y,m-1,n-1)        for recursion
    return solve(X,Y,m,n);            //for tabulation
}


//Also see the code for printing shortest common supersequence.
//It's pretty similar to that of printing lcs