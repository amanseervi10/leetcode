bool isPalindrome(string str,int i, int j){
    while(j>=i){
        if(str[i]!=str[j]) return false;
        j--; i++;
    }
    return true;
}

int dp[501][501];
int solve(string str, int i, int j){
    
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(isPalindrome(str,i,j)) return 0;

    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int left,right;
        if(dp[i][k]!=-1) left=dp[i][k];
        else left=solve(str,i,k);
        
        if(dp[k+1][j]!=-1) right=dp[k+1][j];
        else right=solve(str,k+1,j);

        mn=min(mn,1+left+right);
    }
    return dp[i][j]=mn;
}

int palindromicPartition(string str)
{
    memset(dp,-1,sizeof(dp));
    return solve(str,0,str.length()-1);
}