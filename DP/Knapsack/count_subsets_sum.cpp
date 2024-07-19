// -------------------Recursion--------------------

// #include<bits/stdc++.h>
// using namespace std;


// void solve(vector<int> arr,int i,int sum,int &ans){
//     if(sum==0){
//         ans++; return;
//     }
//     else if(sum<0 || i<0) return;
//     else{
//         solve(arr,i-1,sum-arr[i],ans);
//         solve(arr,i-1,sum,ans);
//     }
// }

// int main(){
//     int n; cin>>n;
//     vector<int> arr;
//     for(int i=0; i<n; i++){
//         int k; cin>>k;
//         arr.push_back(k);
//     }
//     int sum; cin>>sum;
//     int ans=0;
//     solve(arr,n-1,sum,ans);
//     cout<<ans;
//     return 0;
// }


//-----------------Tabulation-----------------------

#include<bits/stdc++.h>
using namespace std;

int dp[100][1001];
int solve(vector<int> arr,int n,int sum){
    for(int i=0; i<sum+1; i++) dp[0][i]=0;
    for(int i=0; i<n+1; i++) dp[i][0]=1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(j>=arr[i-1]){
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n; cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        arr.push_back(k);
    }
    int sum; cin>>sum;
    cout<<solve(arr,n,sum);
    return 0;
}