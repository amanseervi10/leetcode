class Solution {
public:
    string removeDuplicateLetters(string s) {
        int letters[26]={0};
        int visited[26]={0};

        for(int i=0; i<s.length(); i++) letters[s[i]-'a']++;

        stack<char> st;

        for(int i=0; i<s.length(); i++){

            if(visited[s[i]-'a']==1){
                letters[s[i]-'a']--;
            }

            else{
                while(!st.empty() && (st.top()-'a')>(s[i]-'a') && letters[st.top()-'a']>0){
                    visited[st.top()-'a']=0;
                    st.pop();
                }
                st.push(s[i]);
                letters[s[i]-'a']--;
                visited[s[i]-'a']=1;
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};