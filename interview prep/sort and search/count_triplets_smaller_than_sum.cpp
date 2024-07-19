long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr,arr+n);
    long long ans=0;
    for(int i=0; i<n; i++){
        int low=i+1, high=n-1;
        while(high>low){
            if(arr[i]+arr[low]+arr[high]<sum){
                ans+=(high-low);
                low++;
            }
            else high--;
        }
    }
    return ans;
}