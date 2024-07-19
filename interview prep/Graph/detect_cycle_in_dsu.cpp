int find(int parent[],int a){
    if(a==parent[a]) return a;
    else return parent[a]=find(parent,parent[a]);
}

void Union(int parent[],int rank[],int a,int b){
    int u=find(parent,a);
    int v=find(parent,b);

    if(u==v) return;

    if(rank[u]>rank[v]) parent[v]=u;
    else if(rank[u]<rank[v]) parent[u]=v;
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int detectCycle(int V, vector<int> adj[])
{
    //Making parent and rank and shit
    int parent[V],rank[V];
    for(int i=0; i<V; i++){
        parent[i]=i;
        rank[i]=0;
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            if(adj[i][j]>i){
                int x=find(parent,i);
                int y=find(parent,adj[i][j]);
                if(x==y) return 1;
                else Union(parent,rank,y,x);
            }
        }
    }
    return 0;
}



// Why i < adj[i][j] ?

// This is because if we have processed for edge for eg. 0 to 1 
// then we will not be checking again for 1 to 0 [i.e. loop encountered];

// Check for below test case:

// V = 3, adj = {{1}, {0, 2}, {1}}