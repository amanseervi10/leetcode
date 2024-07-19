int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    //n is number of vertices
    int e=edges.size();     //e is number of edges
    vector<int> dist(n,INT_MAX);

    for(int i=1; i<n; i++){
        for(int j=0; j<e; j++){
            if(dist[edges[j][1]]>dist[edges[j][0]]+edges[j][2]){
                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
            }
        }
    }

    for(int i=0; i<e; i++){
        if(dist[edges[i][1]]>dist[edges[i][0]]+edges[i][2]){
            return 1;
        }
    }
    return 0;
}