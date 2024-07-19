
//tells us whether the cell is safe or not
bool safe(vector<vector<int>> &mat, int i, int j){
    if(mat[i][j]==0) return false;
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    
    for(int k=0; k<4; k++){
        int a=i+x[k],b=j+y[k];
        if(a>=0 && a<mat.size() && b>=0 && b<mat[0].size()){
            if(mat[a][b]==0) return false;
        }
    }
    return true;
}

//we want shortest path...so we apply bfs
int findShortestPath(vector<vector<int>> &mat)
{
    queue<pair<int,int>> q;
    vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
    
    //insert all safe cells in first column
    for(int i=0; i<mat.size(); i++){
        if(safe(mat,i,0)){
            q.push({i,0});
            vis[i][0]=1;
        }
    }


    int count=0;
    while(!q.empty()){
        int t=q.size();
        for(int i=0; i<t; i++){
            auto temp=q.front();
            q.pop();

            if(temp.second==mat[0].size()) return count;

            int x[4]={0,0,1,-1};
            int y[4]={1,-1,0,0};
    
            for(int k=0; k<4; k++){
                int a=temp.first+x[k],b=temp.second+y[k];
                if(a>=0 && a<mat.size() && b>=0 && b<mat[0].size() && !vis[a][b] && safe(mat,a,b)){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
            
        }
        count++;
    }
    return -1;
}