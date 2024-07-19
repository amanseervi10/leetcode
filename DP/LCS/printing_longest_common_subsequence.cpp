#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int solve(string x,string y){
    for(int i=0; i<=x.length(); i++) dp[0][i]=0;
    for(int i=0; i<=y.length(); i++) dp[i][0]=0;
    for(int i=1; i<=y.length(); i++){
        for(int j=1; j<=x.length(); j++){
            if(x[j-1]==y[i-1]) dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[y.length()][x.length()];
}

int main(){
    string x,y; cin>>x>>y;
    cout<<solve(x,y);
    return 0;
}