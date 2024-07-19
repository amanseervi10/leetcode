int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int mx=0;
    int ans=-1;
    for(int i=0; i<n; i++){
        auto lower=lower_bound(arr[i].begin(),arr[i].end(),1);
        int count=0;
        if(lower!=arr[i].end()){
            count=(arr[i].end()-lower);
            if(count>mx){
                mx=count; ans=i;
            }
        }
    }
    return ans;
}