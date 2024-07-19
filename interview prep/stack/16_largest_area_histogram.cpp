long long getMaxArea(long long arr[], int n)
{
    stack<int> s;
    vector<int> prevSmaller;
    vector<int> nextSmaller;

    //for prevSmaller;
    s.push(-1);
    for(int i=0; i<n; i++){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        prevSmaller.push_back(s.top());
        s.push(i);
    }

    //for nextSmaller
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        nextSmaller.push_back(s.top());
        s.push(i);
    }
    reverse(nextSmaller.begin(),nextSmaller.end());


    long long ans=INT_MIN;
    for(int i=0; i<n; i++){
        int a=prevSmaller[i],b=nextSmaller[i];
        if(b==-1) b=n;
        long long temp=b-a-1;
        ans=max(ans,arr[i]*temp);
    }

    return ans;
    
}