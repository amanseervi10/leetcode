bool find3Numbers(int arr[], int n, int X)
{
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) mp[arr[i]]++;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k=X-arr[i]-arr[j];
            
            if(mp.find(k)!=mp.end()){
                if((k==arr[i] || k==arr[j]) && mp[k]==1) continue; 
                else if((k==arr[i] && k==arr[j]) && mp[k]==2) continue; 
                else return true;
            }
        }
    }
    return false;
}