class Solution {
public:

    bool ispalindrome(string s,int a,int b){
        while(a<=b){
            if(s[a]!=s[b]) return false;
            a++; b--;
        }
        return true;
    }

    void solve(string s,int start, vector<string> a, vector<vector<string>> &b){
        if(start>=s.length()){
            b.push_back(a);
            return;
        }
        for(int i=start;i<=s.length()-1; i++){
            if(ispalindrome(s,start,i)){
                string k=s.substr(start,i-start+1);
                a.push_back(k);
                solve(s,i+1,a,b);
                a.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> b;
        vector<string> a;
        solve(s,0,a,b);
        return b;
    }
};