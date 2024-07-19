//in undirected graph we can simply do dfs
//if we stumble upon a node which was already visited then we can say that it has a cycle

//There is a catch though, we need to skip the "prev" node that is the node which called the
//curr node in the firts place during dfs, as the prev node wil obviously always be visited

//BFS : can also be done using bfs usign same thing. If a node is visited, and it is not parent
//then we can say that there is a cycle

bool solve(vector<int> adj[],int vis[],int i,int prev){
    if(vis[i]) return true;

    vis[i]=1;

    for(int a: adj[i]){
        if(a!=prev){
            if(solve(adj,vis,a,i)) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V]={0};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(solve(adj,vis,i,-1)) return true;
        }
    }
    return false;
}