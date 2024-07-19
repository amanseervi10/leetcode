class Solution
{
	public:
void solve(vector<vector<int>>& dp, string &a, string &b, int i,int j,set<string> &ans,string temp,int len){
    
    if(temp.length()==len){
        reverse(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    
    //This is also correct
    // if(a[i-1]==b[j-1]) solve(dp,a,b,i-1,j-1,ans,temp+a[i-1]);

    // else if(dp[i-1][j]==dp[i][j-1]){
    //     solve(dp,a,b,i-1,j,ans,temp);
    //     solve(dp,a,b,i,j-1,ans,temp);
    // }
    // else if(dp[i-1][j]>dp[i][j-1]) solve(dp,a,b,i-1,j,ans,temp);
    // else solve(dp,a,b,i,j-1,ans,temp);
    
    for(int x=i; x>0; x--){
        for(int y=j; y>0; y--){
            if(a[x-1]==b[y-1]){
                solve(dp,a,b,x-1,y-1,ans,temp+a[x-1],len);
            }
        }
    }
}

vector<string> all_longest_common_subsequences(string s, string t)
{
    //declaring the dp vector
    vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1));
    int x=s.length(),y=t.length();

    //We make the table
    for(int i=0; i<=x; i++) dp[i][0]=0;
    for(int i=0; i<=y; i++) dp[0][i]=0;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    set<string> store; 
    vector<string> ans;
    // solve(dp,s,t,s.length(),t.length(),store,"");
    solve(dp,s,t,s.length(),t.length(),store,"",dp[x][y]);
    
    
    for(auto i: store) ans.push_back(i);
    return ans;
}
};