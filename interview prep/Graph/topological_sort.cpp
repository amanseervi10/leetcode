//Here we use a stack
//The idea although can be written, would be better if visualized
//I recommend watching the gfg course lecture which deals with this topic
//you will get idea

void dfs(vector<int> adj[],int vis[],int i,stack<int> &s){
    vis[i]=1;

    for(int a: adj[i]){
        if(!vis[a]){
            dfs(adj,vis,a);
            s.push(a);
        }
    }
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V]={0};
    stack<int> s;

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(adj,vis,i,s);
            s.push(i);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}