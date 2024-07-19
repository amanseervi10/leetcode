long long maxSubarraySum(int arr[], int n)
{
    long long max_overall=INT_MIN;
    long long max_till_here=0;

    for(int i=0; i<n; i++){
        max_till_here+=arr[i];

        max_overall=max(max_overall,max_till_here);

        if(max_till_here<0) max_till_here=0;
    }

    return max_overall;
}