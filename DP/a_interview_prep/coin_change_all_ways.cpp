//recursion
// long long solve(int coins[],int sum, int i){
//     if(sum==0) return 1;
//     if(i<0) return 0;

//     if(sum>=coins[i]) return solve(coins,sum-coins[i],i)+solve(coins,sum,i-1);
//     else return solve(coins,sum,i-1);
// }

//Tabulation

long long solve(int coins[],int sum, int N){

    long long dp[N+1][sum+1];
    for(int i=0; i<=sum; i++) dp[0][i]=0;
    for(int i=0; i<=N; i++) dp[i][0]=0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=sum; j++){
            if(j>=coins[i-1]) dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[N][sum];
}

long long int count(int coins[], int N, int sum)
{
    return solve(coins,sum,N);
}