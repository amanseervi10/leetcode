vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int low=j+1,high=n-1;
            while(high>low){
                int sum=arr[i]+arr[j]+arr[low]+arr[high];
                if(sum==k){
                    ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                    high--;
                    low++;
                    while(high>low && arr[low-1]==arr[low]) low++;
                }
                else if(sum<k) low++;
                else high--;
            }
        }
    }
    return ans;
}