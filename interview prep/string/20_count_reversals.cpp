int countRev(string s)
{
    if(s.length()%2) return -1;

    stack<char> st;
    int count=0;

    for(int i=0; i<s.length(); i++){
        if(st.empty() && s[i]=='}'){
            st.push('{');
            count++;
        }
        else if(s[i]=='}' && st.top()=='{') st.pop();
        else st.push('{');
    }

    int temp=0;
    while(!st.empty()){
        st.pop();
        temp++;
    }
    count+=temp/2;
    return count;
}