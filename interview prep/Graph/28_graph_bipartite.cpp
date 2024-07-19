//A graph is bipartite if it can be colored using just two colors

bool dfs(vector<int> adj[],int curr_node, vector<int> &color){

    for(auto i: adj[curr_node]){
        if(color[i]==-1){
            color[i]=!color[curr_node];
            if(!dfs(adj,i,color)) return false;
        }
        else{
            if(color[i]==color[curr_node]) return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V,-1);
    
    for(int i=0; i<V; i++){
        if(color[i]==-1){
            color[i]=0;
            if(!dfs(adj,i,color)) return false;
        }
    }
    return true;
}