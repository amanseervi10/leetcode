#include<bits/stdc++.h>
using namespace std;

int solve(string a,string b,int x,int y){
    if(x==0 && y==0) return 0;
    if(x==0) return b.length();
    if(y==0) return a.length();
    if(a[x-1]==b[y-1]) return solve(a,b,x-1,y-1);
    else return min(solve(a,b,x,y-1),solve(a,b,x-1,y));
}   

int main(){
    string a,b; cin>>a>>b;
    cout<<solve(a,b,a.length(),b.length());
    return 0;
}

// Better logic is to convert one of the string to lcs by a number of deletions
// we then convert that to the required word by a number of additions
//this effectively means our ans is (a.length()-lcs) i.e the number of deletions *(b.length()-lcs)
// which is the number of additions