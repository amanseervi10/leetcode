//recursion
// void solve(int arr[],int n, int &mn,int sum,int total){
//     if(n<0){
//         mn=min(mn,abs(total-2*sum));
//         return;
//     }
//     else{
//         solve(arr,n-1,mn,sum+arr[n],total);
//         solve(arr,n-1,mn,sum,total);
//     }
// }

//Tabulation
//This might go a bit over head so I suggest to watch Aditya Verma DP video

int solve(int arr[],int n,int total){
    int k=total;
    int dp[n+1][k];

    for(int i=0; i<=k; i++) dp[0][i]=0;
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j>=arr[i-1]){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    int ans=INT_MAX;
    for(int i=0; i<=k; i++){
        if(dp[n][i]){
            ans=min(ans,total-2*i);
        }
    }

    return ans;
}

int minDifference(int arr[], int n)
{
    int total=0;
    for(int i=0; i<n; i++) total+=arr[i];

    return solve(arr,n,total);
}