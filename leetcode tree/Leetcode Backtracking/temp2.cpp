#include<bits/stdc++.h>
using namespace std;

set<int> store;
void solve(string s,int index,string temp,int &count){

    if(index==s.length()){
        return;
    }

    for(int i=index; i<s.length(); i++){
        temp+=s[i];
        int k=stoi(temp);
        // cout<<k<<endl;
        if(k%7==0){
            if(store.find(k)==store.end()){
                count++;
                store.insert(k);
                cout<<k<<endl;
            }
        }
        solve(s,i+1,temp,count);
        temp.pop_back();
    }
}

int main(){
    int n; cin>>n;
    string s=to_string(n);
    int count=0;
    solve(s,0,"",count);
    cout<<count<<endl;
    return 0;
}