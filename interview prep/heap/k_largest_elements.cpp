
//can just sort it, then it won't take extra space but then time cmplexity would be NlogN

//we will use heap here

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;

     for(int i=0; i<n; i++){
        pq.push(arr[i]);
        
        if(pq.size()>k) pq.pop();
    }

    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}