//almost same as "31_nearest cell having 1"

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int,int>> q;
    int count=0;

    int row=grid.size(), col=grid[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }

    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};

    while(!q.empty()){
        
        int flag=0;

        int k=q.size();
        for(int i=0; i<k; i++){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();

            for(int j=0; j<4; j++){
                int tx=a+dx[j];
                int ty=b+dy[j];

                if(tx>=0 && tx<row && ty>=0 && ty<col && grid[tx][ty]==1){
                    flag=1;
                    grid[tx][ty]=2;
                    q.push({tx,ty});
                }
            }
        }
        if(flag==1) count++;
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==1) return -1;
        }
    }
    
    return count;
}