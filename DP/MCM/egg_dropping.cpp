// #include<bits/stdc++.h>
// using namespace std;

// int dp[101][1001];
// int solve(int k,int n){
    
//     if(k==1) return n;
//     if(n==0) return 0;
//     if(n==1) return 1;

//     if(dp[k][n]!=-1) return dp[k][n];

//     int ans=INT_MAX;    
//     for(int i=1; i<=n; i++){
//         int a=solve(k-1,i-1);
//         int b=solve(k,n-i);
//         ans=min({ans,1+max(a,b)});
//     }
//     return dp[k][n]=ans;
// }

// int main(){
//     int k,n; cin>>k>>n;
//     memset(dp,-1,sizeof(dp));
//     cout<<solve(k,n);
//     return 0;
// }



class Solution {
public:


    int dp[101][1001];
    int solve(int k,int n){

        if(k==1) return n;
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[k][n]!=-1) return dp[k][n];
    
        int ans=INT_MAX; 
        int low=0,high=n;
        while(low<=high){
            int mid=low+high/2;
            int a=solve(k-1,mid-1);
            int b=solve(k,n-mid);
            ans=min({ans,1+max(a,b)});
            if(a<b){
                low=mid+1;
            }
            else high=mid-1;
        }
        return dp[k][n]=ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};