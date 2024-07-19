#include<bits/stdc++.h>
using namespace std;

int dp1[1000];
int dp2[1000];

void dfs(vector<int> arr[],int node,int parent,int c[]){
    int sum1=0,sum2=0;
    for(auto i: arr[node]){
        if(i==parent) continue;
        dfs(arr,i,node,c);
        sum1+=dp2[i];
        sum2+=max(dp1[i],dp2[i]);
    }

    dp1[node]=c[node]+sum1;
    dp2[node]=sum2;
}


int main(){
    int n; cin>>n;
    vector<int> arr[n+1];

    int c[n+1];
    for(int i=1; i<=n; i++) cin>>c[i];

    for(int i=1; i<n; i++){
        int a,b; cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(arr,1,0,c);
    cout<<max(dp1[1],dp2[1]);
    return 0;
}