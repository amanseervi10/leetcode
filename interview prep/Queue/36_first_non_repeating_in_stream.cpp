string FirstNonRepeating(string A)
{
    int arr[26]={0};
    queue<char> q;

    string ans="";

    for(int i=0; i<A.size(); i++){
        arr[A[i]-'a']++;
        q.push(A[i]);

        while(!q.empty() && arr[q.front()-'a']>1) q.pop();

        if(q.empty()) ans+='#';
        else ans+=q.front();
    }

    return ans;
}