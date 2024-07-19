class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) ans[i][j]=grid[i][j];
                else if(i==0) ans[i][j]=ans[i][j-1] + grid[i][j];
                else if(j==0) ans[i][j]=ans[i-1][j] + grid[i][j];
                else ans[i][j]=grid[i][j] + min(ans[i-1][j],ans[i][j-1]);
            }
        }
        return ans[m-1][n-1];
    }
};