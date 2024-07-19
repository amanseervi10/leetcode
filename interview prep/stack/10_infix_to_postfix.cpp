class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans="";
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='+' || s[i]=='-'){
                while(!st.empty() && (st.top()=='+' || st.top()=='-' || st.top()=='*'|| st.top()=='/' || st.top()=='^')){
                    char temp=st.top();
                    st.pop();
                    ans+=temp;
                }
                st.push(s[i]);
            }
            else if(s[i]=='*' || s[i]=='/'){
                while(!st.empty() && (st.top()=='*' ||st.top()=='/' || st.top()=='^')){
                    char temp=st.top();
                    st.pop();
                    ans+=temp;
                }
                st.push(s[i]);
            }
            else if(s[i]=='^'){
                if(st.empty()) st.push(s[i]);
                else if(st.top()!='^') st.push(s[i]);
                else ans+='^';
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    char temp=st.top();
                    st.pop();
                    ans+=temp;
                }
                st.pop();
            }
            else if(s[i]=='(') st.push(s[i]);
            else ans+=s[i];
        }
        while(!st.empty()){
            char temp=st.top();
            ans+=temp;
            st.pop();
        }
        return ans;
    }
};


//Infix to Prefix
//reverse the string
//convert that to postfix or just convert to postfix whilst reading the string from behind
//(take care of the parenthesis, you will have to replace them for one another)
//reverse the ans
//this is the prefix

//https://www.geeksforgeeks.org/convert-infix-prefix-notation/


//postfix to prefix
//Just like when you are evaluating postfix, take the top 2 operands
//only that this time don't do the operation, but place the operator first and operands after
//push this again into the stack ans repeat
// https://www.geeksforgeeks.org/postfix-prefix-conversion/
