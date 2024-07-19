class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for(int i=0; i<x.length(); i++){
            if(x[i]==')' || x[i]=='}' || x[i]==']'){
                if(st.empty()) return false;

                else if(x[i]==')' && st.top()=='(') st.pop();
                else if(x[i]=='}' && st.top()=='{') st.pop();
                else if(x[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
            else st.push(x[i]);
        }

        if(!st.empty()) return false;
        return true;
    }

};