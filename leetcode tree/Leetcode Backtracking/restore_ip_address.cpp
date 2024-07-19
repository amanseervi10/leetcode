class Solution {
public: 

    vector<string> ans;
    void solve(string s,int index, vector<string>& temp,int count){
        
        if(index==s.length()){
            if(count==0){
                string store="";
                for(auto i : temp){
                    store+=i; store+='.';
                }
                store.pop_back();
                ans.push_back(store);
            }
            return;
        }

        if(count<0) return;

        if(s[index]=='0'){
            temp.push_back("0");
            solve(s,index+1,temp,count-1);
            temp.pop_back();
            return; 
        }


        int x=min(index+3,s.length());
        for(int i=index; i<x; i++){
            string k=s.substr(index,i-index+1);
            int m=stoi(k);
            if(m>=0 && m<=255){
                temp.push_back(k);
                solve(s,i+1,temp,count-1);
                temp.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12 || s[0]-'0'>2) return ans;
        solve(s,0,temp,3);
        return ans;
    }
};