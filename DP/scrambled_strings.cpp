unordered_map<string,bool> dp;
bool solve(string a,string b){

    if(a==b || a.length()==0) return true;
    string temp=a+" "+b;
    if(dp.find(temp)!=dp.end()) return dp[temp];

    int n=a.length();
    for(int i=1; i<n; i++){
        if((solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i))) || 
            (solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)))){
                return dp[temp]=true;
            }
    }
    return dp[temp]=false;
    
}

bool isScramble(string S1, string S2)
{
    return solve(S1,S2);
} 