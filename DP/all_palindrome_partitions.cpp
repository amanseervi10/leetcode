bool isPalindrome(string &str,int i, int j){
    while(j>=i){
        if(str[i]!=str[j]) return false;
        j--; i++;
    }
    return true;
}

void solve(string &s,int i, int j,vector<vector<string>> &ans, vector<string> &temp){

    if(i>j){
        ans.push_back(temp);
        return;
    }

    for(int k=i; k<=j; k++){
        if(isPalindrome(s,i,k)){
            temp.push_back(s.substr(i,k-i+1));
            solve(s,k+1,j,ans,temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S)
{
    vector<vector<string>> ans;
    vector<string> temp;
    solve(S,0,S.length()-1,ans,temp);
    return ans;
}