class Solution {
public:

    unordered_set<string> store,vis;

    int getCount(string s){
        stack<int> st;
        int count=0;
        for(int i=0; i<s.length();i++){
            if(s[i]==')'){
                if(st.empty()) count++;
                else if(st.top()=='(') st.pop();
            }
            else if(s[i]=='(') st.push('(');
        }

        while(!st.empty()){
            st.pop();
            count++;
        }

        return count;
    }

    void solve(string s,int count){

        if(vis.find(s)!=vis.end()) return;

        vis.insert(s);

        if(!count){
            if(!getCount(s)) store.insert(s);
            return;
        }
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]==')'){
                solve(s.substr(0,i)+s.substr(i+1),count-1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int count=getCount(s);

        solve(s,count);

        vector<string> ans;
        for(auto i : store) ans.push_back(i);

        return ans;

    }
};