//Avilable on gfg practice

//recursive
// int solve(int arr[],int i,int j){
    
//     if(i==j) return 0;
    
//     int ans=INT_MAX;
//     for(int k=i; k<j; k++){
//         int a=solve(arr,i,k);
//         int b=solve(arr,k+1,j);
//         int c=arr[i-1]*arr[k]*arr[j];
//         ans=min(ans,a+b+c);
//     }
//     return ans;
// }

//memoization
int dp[101][101];
int solve(int arr[],int i,int j){
    
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=INT_MAX;
    for(int k=i; k<j; k++){
        int a=solve(arr,i,k);
        int b=solve(arr,k+1,j);
        int c=arr[i-1]*arr[k]*arr[j];
        ans=min(ans,a+b+c);
    }
    return dp[i][j]=ans;
}

int matrixMultiplication(int N, int arr[])
{
    memset(dp,-1,sizeof(dp));
    solve(arr,1,N-1);
}