//recursion
// int solve(int price[],int i,int length){
//     if(i<0 || length==0) return 0;

//     if(length>=i+1) return max(price[i]+solve(price,i,length-i-1),solve(price,i-1,length));
//     else return solve(price,i-1,length);
// }

//Tabulation
int solve(int price[],int n){
    int dp[n+1][n+1];
    for(int i=0;i<n+1; i++) dp[0][i]=0;
    for(int i=0;i<n+1; i++) dp[i][0]=0;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(j>=i) dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][n];
}

int cutRod(int price[], int n)
{
    return solve(price,n);
}