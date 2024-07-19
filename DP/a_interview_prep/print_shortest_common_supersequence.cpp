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

        int i=a.length(),j=b.length();
        while(i>0 && j>0){
            if(a[i-1]==b[i-1]){
                ans=a[i-1]+ans;
                i--; j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans=b[j-1]+ans; j--;
            }
            else{
                ans=a[i-1]+ans; i--;
            }
        }
        while(i>0){
            ans=a[i-1]+ans; i--;
        }
        while(j>0){
            ans=b[j-1]+ans; j--;
        }

        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        maketable(str1,str2);
        return makestring(  str1,str2);
    }
};