void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis,int i, int j){
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1'){
        vis[i][j]=1;
        
        int a[]={0,0,1,1,1,-1,-1,-1};
        int b[]={1,-1,1,-1,0,1,-1,0};

        for(int k=0; k<8; k++){
            dfs(grid,vis,i+a[k],j+b[k]);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));

    int count=0;

    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                dfs(grid,vis,i,j);
                count++;
            }
        }
    }

    return count;
    
}