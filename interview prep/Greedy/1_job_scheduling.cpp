static bool comparator(Job &a, Job &b){
    if(a.profit>b.profit) return true;

    else if(a.profit==b.profit && a.dead<b.dead) return true;

    return false;
}

vector<int> JobScheduling(Job arr[], int n)
{
    //we first sort based on profit (more profit to less profit)
    //if profit is same then we put the one with sooner deadline first
    sort(arr,arr+n,comparator);

    int num_jobs=0;
    int profit=0;

    set<int> s;
    
    int max_deadline=0;
    for(int i=0; i<n; i++) max_deadline=max(max_deadline,arr[i].dead);
    for(int i=1; i<=max_deadline; i++) s.insert(i);

    for(int i=0; i<n; i++){
        auto it=s.lower_bound(arr[i].dead);
        
        if(it!=s.end()){
            s.erase(it);
            num_jobs++;
            profit+=arr[i].profit;
        }
    }

    vector<int> ans;
    ans.push_back(num_jobs);
    ans.push_back(profit);

    return ans;
}