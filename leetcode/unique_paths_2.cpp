class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int ans[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1) ans[i][j]=0;
                else if(i==0 && j==0) ans[i][j]=1;
                else{
                    if(i==0) ans[i][j]=ans[i][j-1];
                    else if(j==0) ans[i][j]=ans[i-1][j];
                    else ans[i][j]=ans[i-1][j]+ans[i][j-1];
                }
            }
        }
        return ans[m-1][n-1];
    }
};