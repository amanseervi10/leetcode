#include<bits/stdc++.h>
using namespace std;

class st{
    int top=-1;
    int arr[200];

    public:
        void push(int a){
            arr[++top]=a;
        }
        void pop(){
            top--;
        }
        bool empty(){
            return (top==-1);
        }
        int peek(){
            if(top==-1) return INT_MIN;
            return arr[top];
        }

};

int main(){
    st s;
    s.push(10);
    s.push(20);
    cout<<s.peek()<<endl;;
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}