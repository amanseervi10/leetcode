    // #include<bits/stdc++.h>
// using namespace std;

// unordered_map<string,bool> dp;
// bool solve(string s1,string s2){

//     if(s1==s2 || s1.length()==0) return true;
//     string key=s1+" "+s2;
//     if(dp.find(key)!=dp.end()) return dp[key];

//     int n=s1.length();
//     for(int i=1; i<n; i++){
//         if((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i)))
//          || (solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(0,i),s2.substr(0,n-i)))){
//             return dp[key]=true;
//          }
//     }
//     return dp[key]=false;
// }

// int main(){
//     string s1,s2; cin>>s1>>s2;
//     cout<<solve(s1,s2);
//     return 0;
// }

class Solution {
public:

    unordered_map<string,bool> dp;
    bool solve(string s1,string s2){

        if(s1==s2 || s1.length()==0) return true;
        string key=s1+" "+s2;
        if(dp.find(key)!=dp.end()) return dp[key];

        int n=s1.length();
        for(int i=1; i<n; i++){
            if((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i)))
             || (solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i)))){
                return dp[key]=true;
             }
        }
        return dp[key]=false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};