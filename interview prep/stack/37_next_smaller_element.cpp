vector<int> help_classmate(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> ans;

    for(int i=n-1; i>=0; i--){
        
        while(!s.empty() && s.top()>=arr[i]) s.pop();
        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}