//---------------Recursion-------------------

// #include<bits/stdc++.h>
// using namespace std;

// int solve(string x,string y,int a,int b){
//     if(a==0 || b==0) return 0;
//     else if(x[a-1]==y[b-1]) return 1+solve(x,y,a-1,b-1);
//     else return max(solve(x,y,a-1,b),solve(x,y,a,b-1));
// }

// int main(){
//     string x,y; cin>>x>>y;

//     return 0;
// }

//--------------------Tabulation------------------

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