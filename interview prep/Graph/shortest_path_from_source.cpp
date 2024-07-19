//here we need to output shortest path from source to all other nodes

//Cleary we should simply perform BFS as bfs always gives the shortest distance between two nodes
//(distance as in the minimum number of edges)
//of course if the graph is weighted, simple bfs wouldn't necessarily give the correct answer

void BFS(vector<int> graph[],int src,vector<int> &ans){
    queue<int> q;
    q.push(src);
    ans[src]=0;

    int count=1;
    while(!q.empty()){
        int k=q.size();
        for(int j=0; j<k; j++){
            int temp=q.front();
            q.pop();
            
            for(auto i : graph[temp]){
                if(ans[i]==-1){
                    q.push(i);
                    ans[i]=count;
                }
            }
        }
        count++;
    }
}

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    //First gotta make a graph
    vector<int> graph[N];
    for(int i=0; i<M; i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    //this and vector will also be used as visited array
    vector<int> ans(N,-1);

    BFS(graph,src,ans);
    return ans;
}