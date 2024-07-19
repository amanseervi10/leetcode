//Can do this using recursion or using explicit stack
//Recursion is best though, simple and small code

//Similar to BFS though, we will need two functions if we have disconnected components
//Below is general implementation

#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS(vector<int> graph[],int vis[],int a){
    vis[a]=1;
    cout<<a<<" ";
    for(auto i: graph[a]){
        if(!vis[i]){
            DFS(graph,vis,i);
        }
    }
}

void DFSdisconnected(vector<int> graph[],int n){
    int visited[n]={0};
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(graph,visited,i);
        }
    }
}


int main(){
    int v=5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,2,3);
    addedge(adj,1,2);
    DFSdisconnected(adj,v);
    return 0;
}