//---------------Recursion----------------

// #include<bits/stdc++.h>
// using namespace std;

// int solve(string a,string b, int x,int y){
//     if(x==0 && y==0) return 0;
//     if(x==0) return y;
//     if(y==0) return x;
//     if(a[x-1]==b[y-1]) return 1+solve(a,b,x-1,y-1);
//     else return min(1+solve(a,b,x,y-1),1+solve(a,b,x-1,y));
// }

// int main(){
//     string a,b; cin>>a>>b;
//     cout<<solve(a,b,a.length(),b.length());
//     return 0;
// }


// -------------------Tabulation----------------------

class Solution {
public:

    int dp[1001][1001];
    void maketable(string a,string b){
        dp[0][0]=0;
        for(int i=1; i<=a.length(); i++) dp[0][i]=i;
        for(int i=1; i<=b.length(); i++) dp[i][0]=i;
        for(int i=1; i<=b.length(); i++){
            for(int j=1; j<=a.length(); j++){
                if(a[j-1]==b[i-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=min(1+dp[i-1][j],1+dp[i][j-1]);
            }
        }
    }

    string makestring(string a,string b){
        string ans="";
        int x=a.length(),y=b.length();
        while(1){
            if(a[x-1]==b[y-1]){
                ans=a[x-1]+ans; x--; y--;
            }
            else if(dp[y][x-1]<dp[y-1][x]){
                ans=a[x-1]+ans; x--;
            }
            else{
                ans=b[y-1]+ans; y--;
            }
            if(x==0 && y==0) break;
            else if(x==0){
                while(y!=0){
                    ans=b[y-1]+ans; y--;
                }
                break;
            }
            else if(y==0){
                while(x!=0){
                    ans=a[x-1]+ans; x--;
                }
                break;
            }
        }
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        maketable(str1,str2);
        return makestring(str1,str2);
    }
};