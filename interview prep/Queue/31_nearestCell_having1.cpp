vector<vector<int>> nearest(vector<vector<int>> grid)
{

    int rows=grid.size(), cols=grid[0].size();

    vector<vector<int>> ans(rows,vector<int>(cols,-1));     //will also serve as our visited array
    queue<pair<int,int>> q;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j]==1){
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }

    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};

    while(!q.empty()){      //we run while it ain't empty

        int k=q.size();
        for(int i=0; i<k; i++){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();

            for(int j=0; j<4; j++){
                int tx=cx+dx[j];
                int ty=cy+dy[j];

                if(tx>=0 && tx<rows && ty>=0 && ty<cols && ans[tx][ty]==-1){  //as if ans[tx][ty]!=-1, means it's been visited
                    ans[tx][ty]=ans[cx][cy]+1;
                    q.push({tx,ty});
                }
            }
        }
    }

    return ans;
}

//it's standard bfs question.
//you go searching in the 4 directions, since each is expanding with equally in every pass,
//if you find a cell with value not equal to -1, means it's already been touched by the 
//cell containing 1 which was nearest to it