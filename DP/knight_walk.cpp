
//bfs, cause we need shortest path
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
    queue<pair<int,int>> q;

    q.push({KnightPos[0],KnightPos[1]});
    vis[KnightPos[0]][KnightPos[1]]=1;

    int x[8]={2,2,-2,-2,1,-1,1,-1};
    int y[8]={1,-1,1,-1,2,2,-2,-2};

    int count=0;
    while(!q.empty()){
        int t=q.size();

        for(int i=0; i<t; i++){
            auto temp=q.front();
            q.pop();

            if(temp.first==TargetPos[0] && temp.second==TargetPos[1]) return count;

            for(int k=0; k<8; k++){
                int a=temp.first+x[k],b=temp.second+y[k];
                if(a>=1 && a<=N && b>=1 && b<=N && !vis[a][b]){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
        }
        count++;
    }
    return -1;
}