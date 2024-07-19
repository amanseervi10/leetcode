class Solution{
    public:

    vector<string> ans;
    void solve(vector<vector<int>> &m,int n,int i,int j,string s){


        if(j<0 || j>n-1 || i<0 || i>n-1) return;
        if(m[i][j]!=1) return;
        if(i==n-1 && j==n-1) ans.push_back(s);
        
        m[i][j]=0;

        solve(m,n,i+1,j,s+'D');
        solve(m,n,i,j+1,s+'R');
        solve(m,n,i-1,j,s+'U');
        solve(m,n,i,j-1,s+'L');

        m[i][j]=1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0) return {};
        solve(m,n,0,0,"");
        return ans;
    }
};
