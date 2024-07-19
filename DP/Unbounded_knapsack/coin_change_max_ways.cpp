#include<bits/stdc++.h>
using namespace std;

int dp[20][10001];
int solve(int coins[],int sum,int n){
    for(int i=0; i<=sum; i++) dp[0][i]=0;
    for(int i=0; i<=n; i++) dp[i][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j>=coins[n-1]) dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n;cin>>n;
    int coins[n];
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    int sum; cin>>sum;
    cout<<solve(coins,sum,n);
    return 0;
}