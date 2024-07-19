
//we find all subarray sums using prefix sum
//we put them in min heap
//if size of min heap gets more than k we pop else insert
//top of min heap is the answer

int kthLargest(vector<int> &arr, int n, int k)
{
    for(int i=1; i<n; i++){
        arr[i]+=arr[i-1];
    }

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(arr[0]);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pq.push(arr[j]-arr[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    return pq.top();
}