//recursion
// bool solve(int arr[],int i, int sum){

//     if(sum==0) return true;
//     else if(sum<0 || i<0) return false;

//     return (solve(arr,i-1,sum-arr[i]) || solve(arr,i-1,sum));
// }


//tabulation

int dp[101][1001];

void solve(int arr[],int N,int sum){
    for(int i=0; i<=sum; i++) dp[0][i]=0;
    for(int i=0; i<=N;i++) dp[i][0]=1;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=sum; j++){
            if(j>=arr[i-1]){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
}


int equalPartition(int N, int arr[])
{
    int sum=0;
    for(int i=0; i<N; i++) sum+=arr[i];

    if(sum%2!=0) return false;
    solve(arr,N,sum/2);

    return dp[N][sum];
}