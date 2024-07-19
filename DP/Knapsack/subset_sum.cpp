//-----------------Memoization----------------------

// #include<bits/stdc++.h>
// using namespace std;

// int dp[100][1001];

// bool solve(int arr[],int sum,int i){
//     if(sum==0) return true;
//     if(i<0 || sum<0) return false;
//     if(dp[i][sum]!=-1){
//         return dp[i][sum];
//     }
//     else return dp[i][sum]=solve(arr,sum-arr[i],i-1) || solve(arr,sum,i-1));
// }

// int main(){
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++) cin>>arr[i];
//     int sum; cin>>sum;
//     memset(dp,-1,sizeof(dp));
//     cout<<solve(arr,sum,n-1);
//     return 0;
// }


// --------------------TABULATION----------------------

#include<bits/stdc++.h>
using namespace std;

int dp[100][1001];

bool solve(int arr[],int sum,int n){
    for(int i=0; i<sum+1; i++) dp[0][i]=0;   
    for(int i=0; i<n+1; i++) dp[i][0]=1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(j>=arr[i-1]){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int sum; cin>>sum;
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,sum,n-1);
    return 0;
}
