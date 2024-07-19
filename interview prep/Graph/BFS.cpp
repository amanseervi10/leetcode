//We obviously use a queue for this
//We will also need a visited array as there may be loops
//Remember that visited array is extremely important in graphs

//Also is the graph is 1 component, i.e no disconnected components, then one function is enough
//else we need two functions
//Below is the general implementation using two functions

#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void BFS(vector<int> graph[],int visited[],int a){
    visited[a]=1;
    queue<int> q;
    q.push(a);

    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";

        for(auto i: graph[temp]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void BFSDisconnected(vector<int> graph[],int n){
    int visited[n]={0};
    for(int i=0; i<n; i++){
        if(!visited[i]){
            BFS(graph,visited,i);
        }
    }
}

int main(){
    int v=5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,2,3);
    addedge(adj,1,2);
    BFSDisconnected(adj,v);
    return 0;
}