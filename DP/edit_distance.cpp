
//recursion
// int solve(string s, string t, int i, int j){

//     if(i<0) return j+1;
//     else if(j<0) return i+1;

//     if(s[i]==t[j]) return solve(s,t,i-1,j-1);
//     else{
//         //insertion
//         int a=1+solve(s,t,i-1,j);

//         //deletion
//         int b=1+solve(s,t,i,j-1);

//         //edit
//         int c=1+solve(s,t,i-1,j-1);
//         return min({a,b,c});
//     }
// }

//memoization
int dp[101][101];
int solve(string s, string t, int i, int j){

    if(i<0) return j+1;
    else if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]) return solve(s,t,i-1,j-1);
    else{
        //insertion
        int a=1+solve(s,t,i-1,j);

        //deletion
        int b=1+solve(s,t,i,j-1);

        //edit
        int c=1+solve(s,t,i-1,j-1);
        return  dp[i][j]=min({a,b,c});
    }
}

int editDistance(string s, string t)
{
    memset(dp,-1,sizeof(dp));
    return solve(s,t,s.length()-1,t.length()-1);
}