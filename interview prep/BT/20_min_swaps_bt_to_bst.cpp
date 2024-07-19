void inorder(vector<int> &A, int i,vector<int>& store){
    if(i>=A.size()) return;

    inorder(A,2*i+1,store);
    store.push_back(A[i]);
    inorder(A,2*i+2,store);
}

int solve(vector<int>& store){

    vector<pair<int,int>> temp;
    for(int i=0; i<store.size(); i++){
        temp.push_back({store[i],i});
    }

    sort(temp.begin(),temp.end());

    int ans=0;
    unordered_set<int> visited;
    for(int i=0; i<temp.size(); i++){
        if(!visited.count(i)){
            
            visited.insert(i);
            if(i==temp[i].second) continue;
            
            int j=1;
            int k=temp[i].second;
            while(k!=i){
                visited.insert(k);
                k=temp[k].second;
                j++;
            }
            ans+=j-1;
        }
    }
    return ans;
}

int minSwaps(vector<int> &A, int n)
{
    vector<int> store;
    inorder(A,0,store);
    return solve(store);
}
  