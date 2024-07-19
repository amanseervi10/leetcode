int search(int arr[], int l, int h, int key)
{
    int start=0;
    int mn=INT_MAX;

    for(int i=l; i<=h; i++){
        if(arr[i]<mn){
            mn=arr[i];
            start=i;
        }
    }

    int end=start+(h-l);
    int mod=(h-l)+1;

    while(end>=start){
        int mid=(start+end)/2;
        int actual_mid=mid%mod;

        if(arr[actual_mid]==key) return actual_mid;
        else if(arr[actual_mid]>key) end=mid-1;
        else start=mid+1;
    }
    return -1;
}