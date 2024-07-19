int dp[51][51];
int solve(vector<vector<int>> &arr, int n, int m, int i, int j){

    if(i<0 || i>=n || j<0 || j>=m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int a=solve(arr,n,m,i-1,j+1);
    int b=solve(arr,n,m,i,j+1);
    int c=solve(arr,n,m,i+1,j+1);

    return dp[i][j]=arr[i][j]+max({a,b,c});
}

int maxGold(int n, int m, vector<vector<int>> M)
{  
    int mx=INT_MIN;
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++){
        mx=max(mx,solve(M,n,m,i,0));
    }

    return mx;
}