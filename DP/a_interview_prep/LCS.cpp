//Available on gfg practice

//Recursive
// int solve(string s1,string s2,int x,int y){

//     if(x<0 || y<0) return 0;

//     if(s1[x]==s2[y]) return 1+solve(s1,s2,x-1,y-1);
//     else return max(solve(s1,s2,x-1,y),solve(s1,s2,x,y-1));
// }

//Memoization
// int solve(string s1,string s2,int x,int y,vector<vector<int>>& v){

//     if(x<0 || y<0) return 0;
//     if(v[x][y]!=-1) return v[x][y];

//     if(s1[x]==s2[y]) return v[x][y]=1+solve(s1,s2,x-1,y-1,v);
//     else return v[x][y]=max(solve(s1,s2,x-1,y,v),solve(s1,s2,x,y-1,v));
// }

//Tabulation
int solve(string s1,string s2,int x,int y){
    int dp[x+1][y+1];
    for(int i=0; i<=x; i++) dp[i][0]=0;
    for(int i=0; i<=y; i++) dp[0][i]=0;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[x][y];
}

int lcs(int x, int y, string s1, string s2)
{
    // vector<vector<int>> v(x+1,vector<int>(y+1,-1));
    return solve(s1,s2,x,y);
}