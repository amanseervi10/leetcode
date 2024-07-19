//we essentially need to count the number of disconnected components
//if number of disconnected components is n, then the minimum number of connectins requied is n-1

class Solution {
public:

    void bfs(vector<int> arr[],int n, int visited[],int i){
        visited[i]=1;

        queue<int> q;

        q.push(i);

        while(!q.empty()){
            int temp=q.front();
            q.pop();

            for(int a: arr[temp]){
                if(!visited[a]){
                    q.push(a);
                    visited[a]=1;
                }
            }
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        //first lets make the adjacency list

        vector<int> arr[n];

        for(int i=0; i<connections.size(); i++){
            arr[connections[i][0]].push_back(connections[i][1]);
            arr[connections[i][1]].push_back(connections[i][0]);
        }

        int visited[n];
        memset(visited,0,sizeof(visited));
        int count=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(arr,n,visited,i);
                count++;
            }
        }

        return count-1; 
    }
};