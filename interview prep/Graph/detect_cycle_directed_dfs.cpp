//There are essentially two ways to do this- DFS based and BFS based (uses topological sorting)
//Here we are using DFS based solution

//The idea is that there is a cycle only if there is back edges, i.e only if a node is visited 
//ans is also in the recursion stack right now do we say that there is a cycle

//For this we maintain an additional array, we also need to make sure that we make the element
//false once it leaves the recursion stack

bool solve(vector<int> adj[],int vis[],int rec[],int a){
    vis[a]=1;
    rec[a]=1;

    for(auto i: adj[a]){
        if(!vis[i]){
            if(solve(adj,vis,rec,i)) return true;
        }
        else if(rec[i]) return true;
    }
    rec[a]=0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int vis[V]={0};
    int rec[V]={0};

    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(solve(adj,vis,rec,i)) return true;
        }
    }
    return false;
}