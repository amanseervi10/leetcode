int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int,int> a;
    for(int i=0; i<n; i++){
        a[arr[i]]++;
    }

    int ans=0;
    for(auto i: a){
        auto it=a.find(k-i.first);
        if(it!=a.end()){
            ans+=i.second*((*it).second);
            a.erase(&i); a.erase(it);
        }
    }
    return ans;
}