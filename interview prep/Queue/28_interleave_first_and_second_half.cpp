#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);q.push(2);q.push(3);
    q.push(4);q.push(5);q.push(6);
    q.push(7);q.push(8);q.push(9);
    q.push(10);

    queue<int> temp;
    for(int i=0; i<q.size()/2;i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }
    return 0;
}  