int evaluatePostfix(string S)
{
    stack<int> st;

    for(int i=0; i<S.length(); i++){
        if(S[i]>=48 && S[i]<=57){
            st.push(S[i]-'0');
        }
        else{
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();

            if(S[i]=='+') st.push(a+b);
            else if(S[i]=='-') st.push(a-b);
            else if(S[i]=='*') st.push(a*b);
            else if(S[i]=='/') st.push(a/b);
            else if(S[i]=='^') st.push(a^b);
        }
    }
    return st.top();
}


//Evaluating prefix 
//Do just like above but from right end of the string