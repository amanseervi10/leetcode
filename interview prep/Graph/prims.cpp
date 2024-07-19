int spanningTree(int V, vector<vector<int>> adj[])
{
    int cost=0; //the total weight of the resultant mst

    vector<int> vis(V,0);

    vector<int> parent(V,-1);

    //in this priority queue we will store the edges , the first element of the vector
    //denotes the weight of the edge, the second denotes the vertex it ends at and the third
    //tells where it begin at
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,0,0});


    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        if(vis[temp[1]]) continue;
        vis[temp[1]]=1;
        parent[temp[1]]=temp[2];

        cost+=temp[0];
        for(auto i: adj[temp[1]]){
            pq.push({i[1],i[0],temp[1]});
        }
    }

    //to print the tree
    // for(int i=0; i<V; i++){
    //     cout<<parent[i]<<" ";
    // }
    cout<<endl;
    return cost;
}