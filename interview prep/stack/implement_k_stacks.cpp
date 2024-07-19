#include<bits/stdc++.h>
using namespace std;

class st{
    int *arr;
    int *top;
    int *next;
    int free;
    int k;  //number of stacks
    int n; //size of the array

    public:
    st(int n, int k){
        n=n;
        k=k;
        arr=new int[n];
        top=new int[k];
        next=new int[n];

        for(int i=0; i<k; i++) top[i]=-1;
        for(int i=0; i<n-1; i++) next[i]=i+1;
        next[n-1]=-1;
        free=0;
    }

    void push(int x, int y){ //x is number to be pushed,y is the stack into which it need be pushed
        if(free==-1){
            cout<<"Overflow"<<endl;
            return;
        }
        //store index of first free slot
        int index=free;
        //update the free spot from the next array
        free=next[index];
        //update next by pointing it to the next element in that stack which is basically current top
        next[index]=top[y-1];
        //update the top as new top is the current index
        top[y-1]=index;
        //finally insert the element
        arr[index]=x;
    }

    int pop(int y){  //y is the stack from where we want to pop

        int index=top[y-1];

        top[y-1]=next[index];

        next[index]=free;
        free=index;
        return arr[index];
    }
};

int main(){
    int k = 3, n = 10;
    st ks(n,k);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}