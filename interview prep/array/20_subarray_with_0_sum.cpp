bool subArrayExists(int arr[], int n)
{
    unordered_set<int> store;
    int sum=0;
    store.insert(0); // to tackle cases where it begin or ends with the subarray that gives 0 sum
    // like -> -1 1 2 3 4
    // -> 2 3 4 -1 1
    // gotta have one 0 to compare with in the set beforehand too

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(store.find(sum)!=store.end()) return true;
        else store.insert(sum);
    }
    // if(sum==0) return true; //in case only the entire array made a perfect 0
    // // example -> 4 2 -10 2 2
    return false;
}