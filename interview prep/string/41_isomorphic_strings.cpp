bool areIsomorphic(string s1, string s2)
{
    unordered_map<char,char> mp;

    if(s1.length()!=s2.length()) return false;

    int n=s1.length();
    for(int i=0; i<n; i++){
        if(mp.find(s1[i])!=mp.end()){
            if(mp[s1[i]]!=s2[i]) return false;
        }
        if(mp.find(s2[i])!=mp.end()){
            if(mp[s2[i]]!=s1[i]) return false;
        }
        else{
            mp[s1[i]]=s2[i];
            mp[s2[i]]=s1[i];
        }
    }

    return true;
}