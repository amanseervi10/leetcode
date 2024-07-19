    // ------------------Memoization------------------

// #include<bits/stdc++.h>
// using namespace std;

// int dp[101][1001];

// int solve(int weight[],int value[], int i,int capacity){
//     if(i==0 || capacity==0) return 0;
//     if(dp[i][capacity]!=-1){
//         return dp[i][capacity];
//     }
//     else if(value[i]>=capacity){
//         return dp[i][capacity]=max(value[i]+solve(weight,value,i-1,capacity-weight[i]),
//                     solve(weight,value,i-1,capacity));
//     }
//     else return dp[i][capacity]=solve(weight,value,i-1,capacity);
// }

// int main(){
//     int n; cin>>n;
//     int weight[n],value[n];
//     for(int i=0; i<n; i++) cin>>weight[i];
//     for(int i=0; i<n; i++) cin>>value[i];
//     int capacity; cin>>capacity;
//     memset(dp,-1,sizeof(dp));
//     cout<<solve(weight,value,n-1,capacity);
//     return 0;
// }

//-----------------Tabulation-----------------------

#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];

int solve(int weight[],int value[],int capacity,int n){
    for(int i=0; i<capacity+1; i++) dp[0][i]=0;   
    for(int i=0; i<n+1; i++) dp[i][0]=0;
    for (int i = 1; i < n+1; i++){
        for(int j=1; j<capacity+1; j++){
            if(j>=weight[i-1]){
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],
                                dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][capacity];
}

int main(){
    int n; cin>>n;
    int weight[n],value[n];
    for(int i=0; i<n; i++) cin>>weight[i];
    for(int i=0; i<n; i++) cin>>value[i];
    int capacity; cin>>capacity;
    memset(dp,-1,sizeof(dp));
    cout<<solve(weight,value,capacity,n);
    return 0;
}