//-------------Recursion-----------------

// #include<bits/stdc++.h>
// using namespace std;

// int solve(string s,int a,int b){
//     if(a>b) return 0;
//     if(a==b) return 1;
//     if(s[a]==s[b]) return 2+solve(s,a+1,b-1);
//     else return max(solve(s,a+1,b),solve(s,a,b-1));
// }

// int main(){
//     string s; cin>>s;
//     cout<<solve(s,0,s.length()-1);
//     return 0;
// }

// Better is to simply find the reverse if given string and then find lcs


//---------------Tabulation-------------------


class Solution {
public:

    int dp[1001][1001];
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

    int longestPalindromeSubseq(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        return solve(s,k);
    }
};