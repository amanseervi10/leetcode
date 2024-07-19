
//for every character in string, either take it don't

void solve(string s, int index, vector<string> &ans, string temp){

    if(index==s.length()){
        if(temp.length()>0) ans.push_back(temp);
        return;
    }

    solve(s,index+1,ans,temp+s[index]);     //take it
    solve(s,index+1,ans,temp);              //don't take it
}   

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    solve(s,0,ans,"");

    sort(ans.begin(),ans.end());
    return ans;
}