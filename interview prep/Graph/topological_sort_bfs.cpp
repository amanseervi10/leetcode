//topological sort can be found using both bfs(kahn's algo) and dfs
//here we are using bfs based algorithm

//We simply have to maintain an extra array of indegree
//the idea is that any node which has 0 indegree i.e 1 nodes as parents can be done(i.e printed)
//we also need to decrease indegree of a node as an when it's parent is freed(i.e printed)

vector<int> topoSort(int V, vector<int> adj[])
{
    //we first make array for indegree
    int indegree[V]={0};
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }

    //now we do bfs
    queue<int> q;
    vector<int> ans;
    
    //we push the ones with 0 indegree
    for(int i=0; i<V; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans.push_back(temp);

        for(int i: adj[temp]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return ans;
}