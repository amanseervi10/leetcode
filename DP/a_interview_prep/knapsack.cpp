//Available on gfg practice

//recursion
// int solve(int wt[],int val[],int W, int n){
//     if(n<0) return 0;

//     if(W>wt[n]) return max(val[n]+solve(wt,val,W-wt[n],n-1),solve(wt,val,W,n-1));

//     return solve(wt,val,W,n-1);
// }

//memoization
// int dp[1001][1001];
// int solve(int wt[],int val[],int W, int n){

//     if(n<0) return 0;

//     if(dp[n-1][W]!=-1) return dp[n-1][W];

//     if(W>wt[n]) return dp[n-1][W]=max(val[n]+solve(wt,val,W-wt[n],n-1),solve(wt,val,W,n-1));
//     return dp[n-1][W]=solve(wt,val,W,n-1);
// 

//Tabulation
int dp[1001][1001];
void solve(int wt[],int val[],int n,int W){
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=W; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j>=wt[i-1]){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    memset(dp,-1,sizeof(dp));
    
    solve(wt,val,n,W);
    
    return dp[n][W];
}