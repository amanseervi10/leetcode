//-----------------Recursion------------------

// #include<bits/stdc++.h>
// using namespace std;

// int solve(int arr[],int i,int j){
//     if(i>=j) return 0;   
// //obvious for(i>j), also if i==j then only one matrix...no scope of multiplication
//     else{
//         int ans=INT_MAX;
//         for(int k=i; k<=j-1; k++){
//             int a=solve(arr,i,k);
//             int b=solve(arr,k+1,j);
//             int c=arr[i-1]*arr[k]*arr[j];
//             ans=min(ans,a+b+c);
//         }
//         return ans;
//     }
// }

// int main(){
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++) cin>>arr[i];
//     cout<<solve(arr,1,n-1);
//     return 0;
// }

//-----------------Memoization------------------

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int solve(int arr[],int i,int j){
    if(i>=j) return 0;   
    else{
        int ans=INT_MAX;
        for(int k=i; k<=j-1; k++){
            int a,b,c;
            if(dp[i][k]!=-1) a=dp[i][k];
            else a=dp[i][k]=solve(arr,i,k);
            if(dp[k+1][j]!=-1) b=dp[k+1][j];
            else b=dp[k+1][j]=solve(arr,k+1,j);
            c=arr[i-1]*arr[k]*arr[j];
            ans=min(ans,a+b+c);
        }
        return ans;
    }
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,1,n-1);
    return 0;
}