//recursion
// void solve(vector<int>& arr, int n,int d,int &ans,int sum,int total){
//     if(n<0){
//         if(total-2*sum==d) ans++;
//         return;
//     }
//     solve(arr,n-1,d,ans,sum+arr[n],total);
//     solve(arr,n-1,d,ans,sum,total);
// }

int solve(vector<int>& arr,int n,int d, int total){
    int k=total;
    int dp[n+1][k+1];

    for(int i=0; i<=k; i++) dp[0][i]=0;
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j>=arr[i-1]){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][total];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total=0;

    for(int i=0; i<n; i++) total+=arr[i];

    if(total-d<0 || (total-d)%2) return 0;
    total=(total-d)/2;

    return solve(arr,n,d,total);
}