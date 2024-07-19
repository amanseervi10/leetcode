// refer this : https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int count=1;
    int j=0,i=1;
    int ans=INT_MIN;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return count;
}