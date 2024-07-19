//we are given adjacency list and we need to implement djiktras

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    
    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();

        for(auto edge : adj[temp.second]){
            if(dist[edge[0]]>dist[temp.second]+edge[1]){
                dist[edge[0]]=dist[temp.second]+edge[1];
                pq.push({dist[edge[0]],edge[0]});
            }
        }
    }
    return dist;
}