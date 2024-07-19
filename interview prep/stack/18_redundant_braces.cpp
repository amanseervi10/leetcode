//https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/


//We simply push operators and opening braces into the stack
//if any closing braces did not pop atleast one operator, it means it wans't of any use
#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

bool solve(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]==')'){
            int flag=0;
            while(!st.empty() && st.top()!='('){
                if(isOperator(st.top())) flag=1;        //if operator was popped at some point
                st.pop();
            }
            if(flag!=1) return false;   //so if not operator popped, straightsway we return false
        }
        else st.push(s[i]);
    }
    return true;        //if it reahed here means it would have been correct in the first place
}

int main(){
    string s="((a+b))";

    return 0;
}