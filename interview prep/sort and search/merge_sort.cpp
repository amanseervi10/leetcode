long long merge(long long arr[], long long l, long long m, long long r)
{    
    long long i=l, j=m+1;
    long long count=0;
    vector<int> temp;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]); i++;
        }
        else{
            temp.push_back(arr[j]); j++;
            count+=m-i+1;
        }
    }
    
    while(i<=m){
        temp.push_back(arr[i]); i++;
    }
    while(j<=r){
        temp.push_back(arr[j]); j++;
    }
    
    int k=l;
    for(int i=0; i<temp.size(); i++){
        arr[k]=temp[i]; k++;
    }
    return count;
}

public:
long long mergeSort(long long arr[], long long l, long long r)
{
    if(l>=r) return 0;

    long long count=0;
    long long mid=l+ (r-l)/2;
    count+=mergeSort(arr,l,mid);
    count+=mergeSort(arr,mid+1,r);
    count+=merge(arr,l,mid,r);
    return count;
}

    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }