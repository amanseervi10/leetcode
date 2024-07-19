string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    int indegree[K]={0};

    for(int i=0; i<N-1; i++){
        string a=dict[i];
        string b=dict[i+1];
        int k=min(a.length(),b.length());

        for(int j=0; j<k; j++){
            if(a[j]!=b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                indegree[b[j]-'a']++;
                break;
            }
        }
    }

    string ans="";
    queue<int> q;
    
    for(int i=0; i<K; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans+=char(temp+'a');

        for(auto i: adj[temp]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }

    return ans;

}