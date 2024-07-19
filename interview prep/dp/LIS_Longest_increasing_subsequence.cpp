// Although this is a classical dp problem, it also has a solution in NlogN

// Here i am doing the dp version
// for dp refer : https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
// for NlogN method refer : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

// problem link : https://practice.geeksforgeeks.org/problems/increasing-sub-sequence1712/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


int maxLength(string s)
{
    int dp[s.length()];
    dp[0]=1;
    int ans=1;

    for(int i=1; i<s.length(); i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(s[i]>s[j]){
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }

    return ans;
}