//We will use BFS algorithm for this

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int store=image[sr][sc];

    int a[]={1,1,-1,-1};
    int b[]={1,-1,1,-1};

    queue<pair<int,int>> q;
    q.push({sr,sc});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();

        image[temp.first][temp.second]=store;

        for(int i=0; i<4; i++){
            int x=temp.first+a[i],y=temp.second+b[i];
            if(x>=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==store){
                q.push({x,y});
            }
        }
    }

    return image;
}