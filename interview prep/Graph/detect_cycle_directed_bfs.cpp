//This is the bfs version of the solution
//Here we use topological sort

//The idea is simple, if a graph has cycle then it can't have a topological sort
//as there will be interdependency

//We can say the reverse of this also, i.e if there dosen't exist a topological sort of a
//graph then it has a cycle

//So we continue as usual in the kahn's algorithm, and then at last check the indegree
//array, it there are still elements that are not reached, we can say that the graph
//does have a cycle

bool isCyclic(int V, vector<int> adj[])
{
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

    for(int i=0; i<V; i++){
        if(indegree[i]!=0) return true;
    }
    return false;
}