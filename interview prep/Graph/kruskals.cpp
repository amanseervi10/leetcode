//We will need Disjoint set for this algorithm
//Read this article : https://www.scaler.com/topics/data-structures/disjoint-set/

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

int spanningTree(int V, vector<vector<int>> adj[])
{

    //Making parent and rank and shit
    int parent[V],rank[V];
    for(int i=0; i<V; i++){
        parent[i]=i;
        rank[i]=0;
    }

    //first insert into a vector all the edges
    //then sort that vector

    //the first element of the vector is the weight, the second and third are labels of the vertices
    vector<vector<int>> store;
    for(int i=0; i<V; i++){
        for(auto j: adj[i]){
            store.push_back({j[1],j[0],i});
        }
    }

    //now we sort this vector
    sort(store.begin(),store.end());

    int cost=0; //to store the cost of the MST

    for(int i=0; i<store.size(); i++){
        
        int x=find(parent,store[i][1]);
        int y=find(parent,store[i][2]);

        if(x!=y){
            cost+=store[i][0];
            Union(parent,rank,x,y);
        }
    }
    return cost;
}