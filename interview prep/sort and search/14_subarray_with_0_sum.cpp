long long int findSubarray(vector<long long int> &arr, int n)
{
    unordered_map<long long,int> freq;
    long long sum=0;

    long long count=0;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==0) count++;
        freq[sum]++;

        count+=freq[sum]-1;
    }   

    return count;
}