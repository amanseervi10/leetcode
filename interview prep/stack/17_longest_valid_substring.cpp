int findMaxLen(string s)
{
    stack<int> st;

    //we store the index of characters that do not match with anyone
    //the longest valid string will lie in between those
    //so we then pop out and count the distance between those indices 
    //to calculate the longest valid expression
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') st.push(i);

        else if(s[i]==')'){
            if(!st.empty() && s[st.top()]=='(') st.pop();
            else st.push(i);
        }
    }

    int a=0, b=s.length();
    int ans=0;
    while(!st.empty()){
        a=st.top(); st.pop();
        ans=max(ans,b-a-1);
        b=a;
    }
    ans=max(ans,b);
    return ans;
}