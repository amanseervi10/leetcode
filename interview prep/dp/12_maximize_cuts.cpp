//  int solve(int n, int x, int y, int z){
    
//     if(n==0) return 0;
//     if(n<0) return INT_MIN;

//     return 1+max({solve(n-x,x,y,z),solve(n-y,x,y,z),solve(n-z,x,y,z)});
// }

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0]=0;

    for(int i=1; i<=n; i++){
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;

        if(i-x>=0) a=dp[i-x];
        if(i-y>=0) b=dp[i-y];
        if(i-z>=0) c=dp[i-z];

        dp[i]=1+max({a,b,c});
    }
    if(dp[n]<0) return 0;
    return dp[n];
}