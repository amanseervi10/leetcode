//Also see this : https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/

bool isSafe(bool graph[101][101], int n, int curr_node,vector<int> &color){

    for(int i=0; i<n; i++){
        if(graph[curr_node][i]==true){
            if(color[i]==color[curr_node]) return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],int m, int n,int curr_node,vector<int> &color){

    if(curr_node==n) return true;

    for(int i=1;i<=m; i++){
        color[curr_node]=i;
        if(isSafe(graph,n,curr_node,color)){
            if(solve(graph,m,n,curr_node+1,color)) return true;
        }

        color[curr_node]=0;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n,0);
    return solve(graph,m,n,0,color);
}