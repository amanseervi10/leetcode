class Solution {
public:
    int palin[2001][2001];
    bool ispalindrome(string &s,int i,int j){
        int a=i; int b=j;
        while(a<=b){
            if(s[a]!=s[b]){
                palin[i][j]=0;
                return false;
            }
            a++; b--;
        }
        return palin[i][j]=true;
    }

    int dp[2001][2001];
    int solve(string &s,int i,int j){
        if(i>=j || palin[i][j]==1) return 0;
        if(ispalindrome(s,i,j)){
            dp[i][j]=0; return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;  
        for(int k=i; k<j; k++){
            if(ispalindrome(s,i,k)){
                ans=min(ans,1+solve(s,k+1,j));
            }
        }
        return dp[i][j]=ans;
    }   
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(palin,-1,sizeof(palin));
        return solve(s,0,s.length()-1);
    }
};