#include<bits/stdc++.h>
using namespace std;

int dp[100][10001];

void maketable(vector<int> v, int range,int n){
    for(int i=0; i<range+1; i++) dp[0][i]=0;
    for(int i=0; i<n+1; i++) dp[i][0]=1;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<range+1; j++){
            if(j>=v[i-1]) dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int solve(int range, int n){
    int ans=INT_MAX;
    for(int i=0; i<=(range)/2; i++){
        if(dp[n][i]){
            ans=min(ans,range-2*i);
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    memset(dp,-1,sizeof(dp));
    int range=0;
    for(auto i:v){
        range+=i;
    }
    maketable(v,range,n);
    cout<<solve(range,n);
    return 0;
}