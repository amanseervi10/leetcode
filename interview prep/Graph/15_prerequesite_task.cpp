//simply if there is a topological sort possible then answer is yes, else no
//i am using kahn's algo for topological sorting here

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    
    vector<int> adj[N];
    for(int i=0; i<prerequisites.size(); i++){
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }


    int indegree[N]={0};

    for(int i=0; i<N; i++){
        for(int j=0; j<adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i=0; i<N; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        for(auto i : adj[temp]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }

    for(int i=0; i<N; i++){
        if(indegree[i]!=0) return false;
    }
    return true;
}