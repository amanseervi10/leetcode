#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int a){
    if(s.empty()){
        s.push(a); 
        return;
    }
    int temp=s.top();
    s.pop();
    solve(s,a);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
 
    int n = 7;  //to insert at the bottom
    solve(s,n);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}