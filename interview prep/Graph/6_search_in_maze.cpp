void solve(vector<vector<int>> &m, int n, int i,int j,vector<string> &ans, string s){

    if(i==n-1 && j==n-1 && m[i][j]==1){
        ans.push_back(s);
        return;
    }

    if(i>=0 && i<n && j>=0 && j<n && m[i][j]==1){
        m[i][j]=0;
        solve(m,n,i+1,j,ans,s+'D');
        solve(m,n,i,j+1,ans,s+'R');
        solve(m,n,i-1,j,ans,s+'U');
        solve(m,n,i,j-1,ans,s+'L');
        m[i][j]=1;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    solve(m,n,0,0,ans,"");
    return ans;
}