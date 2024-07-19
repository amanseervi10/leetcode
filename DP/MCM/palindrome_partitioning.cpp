#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s,int a,int b){
    while(a<=b){
        if(s[a]!=s[b]) return false;
        a++; b--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i>j) return 0;
    else if(i==j) return 0;
    else{
        if(ispalindrome(s,i,j)) return 0;
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int a,b;
            a=solve(s,i,k);
            b=solve(s,k+1,j);
            ans=min(ans,a+b+1);
        }
        return ans;
    }
}

int main(){
    string s; cin>>s;
    cout<<solve(s,0,s.length()-1);
    return 0;
}