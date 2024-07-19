//---------------Memoised-----------------
// very important question

#include<bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int solve(string s, int i, int j, bool istrue){
    if(i>j) return 0;
    if(i==j){
        if(istrue) return s[i]=='t';
        else return s[i]=='f';
    }
    if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
    int ans=0;
    for(int k=i+1; k<=j-1; k+=2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        if(s[k]=='^'){
            if(istrue) ans+=lt*rf+lf*rt;
            else ans+=lt*rt+lf*rf;
        }
        else if(s[k]=='|'){
            if(istrue) ans+=lt*rf+lt*rt+lf*rt;
            else ans+=lf*rf;
        }
        else{
            if(istrue) ans+=lt*rt;
            else ans+=lf*rt+lt*rf+lf*rf;
        }
    }
    return dp[i][j][istrue]=ans;
}

int main(){
    string s; cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,s.length()-1,true);
    return 0;
}