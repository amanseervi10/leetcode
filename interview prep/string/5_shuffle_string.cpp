class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char* ans=new char[s.length()];
        for(int i=0; i<s.length(); i++){
            ans[indices[i]]=s[i];
        }
        string final="";
        for(int i=0; i<s.length(); i++){
            final+=ans[i];
        }
        return final;
    }
};